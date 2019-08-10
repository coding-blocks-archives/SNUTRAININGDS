// Tries
#include <iostream>
#include <unordered_map>
using namespace std;

class node{
public:
	char ch;
	bool isTerminal;
	unordered_map<char,node*> h;
	node(char c){
		ch = c;
		isTerminal = false;
	}
};

class Trie{
	node* root;
public:
	Trie(){
		root= new node('\0');
	}

	void addWord(char* word){
		node* temp=root;
		for(int i=0;word[i]!='\0';i++){
			char ch = word[i];
			if(temp->h.count(ch)==0){
				node* n = new node(ch);
				temp->h[ch] = n;
				temp=temp->h[ch];
			}
			else{
				temp=temp->h[ch];
			}
		}
		temp->isTerminal = true;
	}

	bool searchWord(char* word){
		node* temp = root;
		for(int i=0;word[i]!='\0';i++){
			char ch = word[i];
			if(temp->h.count(ch)==0){
				return false;
			}
			else{
				temp=temp->h[ch];
			}
		}
		return temp->isTerminal;
	}
};

int main(){

	Trie t;

	t.addWord("Hell");
	t.addWord("Hell");
	t.addWord("Code");
	t.addWord("Coder");
	t.addWord("Coding");

	while(1){
		char a[100];
		cin>>a;
		if(t.searchWord(a)){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}







	return 0;
}