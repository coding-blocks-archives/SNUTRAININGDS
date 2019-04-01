// InbuiltString
#include <iostream>
#include <cstring>
using namespace std;

int main(){
	char a[100]="Hello World";

	cout<<strlen(a)<<endl;
	char b[100];
	strcpy(b,a);
	cout<<b<<endl;
	strcat(a,b);
	cout<<a<<endl;

	return 0;
}