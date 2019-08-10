// HashMap
#include <iostream>
using namespace std;

template<typename T>
class node{
public:
	string key;
	T data;
	node<T>* next;
	node(string k,T d):key(k),data(d),next(NULL){}
};
//////////////////////////////////////////////////////////
template<typename T>
class hashmap{
	int cs;
	int ts;
	node<T>** bucket;

	int hashFn(string key){
		int ans=0;
		int mf=1;

		for(int i=0;key[i]!='\0';i++){
			ans += key[i]*mf;
			mf*=37;
			mf%=ts;
			ans%=ts;
		}
		return ans;
	}

public:
	hashmap(int s=7){
		cs=0;
		ts=s;
		bucket = new node<T>*[ts];
		for(int i=0;i<ts;i++){
			bucket[i]=NULL;
		}
	}

	void push(string key,T value){
		int i=hashFn(key);
		node<T>* n = new node<T>(key,value);
		n->next=bucket[i];
		bucket[i]=n;
		cs++;

		float load_factor = (cs)/(ts*1.0);
		// if(load_factor>0.7){
		// 	rehash();
		// }
	}

	void print(){
		for(int i =0;i<ts;i++){
			cout<<"Bucket "<<i<<"-->";
			node<T>* temp=bucket[i];
			while(temp){
				cout<<temp->key<<",";
				temp = temp->next;
			}
			cout<<endl;
		}
	}

};
//////////////////////////////////////////////////////////




int main(){
	hashmap<int> h;

	h.push("Mango",100);
	h.push("Apple",200);
	h.push("Kiwi",300);
	h.push("Banana",100);

	h.print();







	return 0;
}