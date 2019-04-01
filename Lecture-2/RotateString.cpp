// RotateString
#include <iostream>
using namespace std;

int length(char a[]){
	int i;

	for(i=0;a[i]!='\0';i++){

	}
	return i;
}


int main(){
	char a[]="Coding";
	int n=4;

	int l=length(a);
	cout<<a<<endl;
	// Shift all the characters n position ahead
	for(int i=l-1;i>=0;i--){
		a[i+n]=a[i];
	}
	cout<<a<<endl;
	int i=0;
	int j=l;
	// Bring the last n characters at front
	for(int k=1;k<=n;k++){
		a[i]=a[j];
		i++;
		j++;
	}
	cout<<a<<endl;
	a[l]='\0';// Insert the Null at the length pos
	cout<<a<<endl;







	return 0;
}