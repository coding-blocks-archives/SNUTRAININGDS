// Permutations
#include <iostream>
using namespace std;

char result[100][100];
int k=0;

void Permutations(char in[],int i){
	if(in[i]=='\0'){
		strcpy(result[k],in);
		k++;
		cout<<in<<endl;
		return;
	}

	for(int j=i;in[j]!='\0';j++){
		swap(in[i],in[j]);
		Permutations(in,i+1);
		swap(in[i],in[j]);
	}
}


int main(){
	char in[100];
	cin>>in;


	Permutations(in,0);
	for(int i=0;i<k;i++){
		cout<<result[i]<<endl;
	}

	return 0;
}