#include <iostream>
using namespace std;

template<typename T>
class node{
public:
	string key;
	T value;
	node<T>* next;
	node(string s,T v){
		key = s;
		value=v;
		next = NULL;
	}
};
template<typename T>
class hashmap{
	node<T>** Bucket;
	int cs;
	int ts;

	int hashFn(string key){
		int ans = 0;
		int mul_factor = 1;
		for(int i=0;key[i]!='\0';i++){
			ans += mul_factor*key[i];
			mul_factor *= 37;

			ans %= ts;
			mul_factor %= ts;
		}
		ans = ans%ts;
		return ans;
	}

	void rehash(){
		node<T> ** oldBucket = Bucket;
		int oldts = ts;
		Bucket = new node<T>*[2*ts];
		cs = 0;
		ts = 2*ts;
		for(int i=0;i<ts;i++){
			Bucket[i] = NULL;
		}

		for(int i=0;i<oldts;i++){
			node<T>* temp = oldBucket[i];
			while(temp!=NULL){
				insert(temp->key,temp->value);
				temp=temp->next;
			}
		}
		delete []oldBucket;
	}

public:
	hashmap(int s=7){
		ts = s;
		cs = 0;
		Bucket = new node<T>*[ts];
		for(int i=0;i<ts;i++){
			Bucket[i] = NULL;
		}
	}

	void insert(string key,T value){
		int i = hashFn(key);
		// i : hash_index 
		node<T>* n = new node<T>(key,value);
		n->next = Bucket[i];
		Bucket[i] = n;
		cs++;

		float load_factor = cs/(1.0*ts);
		if(load_factor>0.7){
			rehash();
		}
	}

	void Print(){
		for(int i=0;i<ts;i++){
			cout<<i<<"-->";
			node<T>* temp = Bucket[i];
			while(temp){
				cout<<temp->key<<",";
				temp=temp->next;
			}
			cout<<endl;
		}
	}

	T* search(string key){
		int i = hashFn(key);
		node<T>* temp = Bucket[i];
		while(temp){
			if(temp->key == key){
				return &(temp->value);
			}
		}
		return NULL;
	}

	T& operator[](string key){
		T* temp = search(key);
		if(temp == NULL){
			// This key does not exists
			T garbage;
			insert(key,garbage);
			temp = search(key);
			return *temp;
		}
		else{
			// this key exists
			return *temp;		
		}

	}

	int count(string key){
		node<T>* temp=search(key);
		if(temp==NULL){
			return 0;
		}
		else{
			return 1;
		}
	}

	void Delete(string key){
		int i=hashFn(key);
		node<T>* temp = Bucket[i];
		node<T>* prev= NULL;
		while(temp){
			if(temp->key==key){
				if(prev==NULL){
					Bucket[i] = temp->next;
					temp->next = NULL;
					delete temp;
					break;
				}
				else{
					prev->next= temp->next;
					temp->next = NULL;
					delete temp;
					break;
				}
			}
			else{
				prev= temp;
				temp=temp->next;
			}
		}
	}

};

int main(){
	hashmap<int> h;

	h.insert("Apple",150);
	h.insert("PineApple",50);
	h.insert("Guava",30);
	h.insert("Kiwi",40);
	// h.insert("Mango",100);
	h["Mango"] = 100; // Insertion
	cout<<h["Mango"]<<endl; // Search
	h["Mango"] = 150;// Updation
	cout<<h["Mango"]<<endl;
	h.Delete("PineApple");

	h.Print();


	return 0;
}