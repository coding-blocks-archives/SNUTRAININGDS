// Subsequences
#include <iostream>
using namespace std;

void Subsequences(char in[],char out[],int i,int j){
	// base case
	if(in[i]=='\0'){
		out[j]='\0';
		cout<<out<<endl;
		return;
	}
	// Recursive case
	out[j]=in[i];
	Subsequences(in,out,i+1,j+1);

	Subsequences(in,out,i+1,j);
}


int main(){
	char in[100];
	cin>>in;

	char out[100];
	Subsequences(in,out,0,0);




	return 0;
}