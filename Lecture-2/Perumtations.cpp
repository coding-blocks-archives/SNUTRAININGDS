#include <iostream>
using namespace std;

int main(){
	int freq[26]={0}; // Asumming string consists
	// of a-z characters only
	char a[]="abbca";
	char b[]="cbaad";

	for(int i=0;a[i]!='\0';i++){
		// Update the frequency array
		int indx=a[i]-'a';
		freq[indx]++;
	}

	for(int i=0;b[i]!='\0';i++){
		// decrement the frequency array
		int indx=b[i]-'a';
		freq[indx]--;
	}
	
	//Check whether every bucket in freq array is 
	// 0 or not
	int i;
	for(i=0;i<26;i++){
		if(freq[i]!=0){
			cout<<"Not a Permutation"<<endl;
			break;
		}
	}
	if(i==26){
		cout<<"Permutation"<<endl;
	}

	return 0;
}