// CharacterArray
#include <iostream>
using namespace std;

void Readline(char a[],char delimit='\n'){
	char ch;
	ch=cin.get();
	int i=0;
	while(ch!=delimit){
		a[i]=ch;
		i++;
		ch=cin.get();
	}
	a[i]='\0';
	// cout<<endl;c
}


int main(){
	char a[100];
	// char b[100];
	// Readline(a,'.');
	cin.getline(a,100,'$');
	cout<<a<<endl;



	return 0;
}