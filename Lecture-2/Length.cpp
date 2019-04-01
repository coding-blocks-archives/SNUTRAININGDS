// Length
#include <iostream>
using namespace std;

int length(char a[]){
	int i;

	for(i=0;a[i]!='\0';i++){

	}
	return i;
}

void COPY(char a[],char b[]){
	// copy b in a
	int i;
	for(i=0;b[i]!='\0';i++){
		a[i]=b[i];
	}
	a[i]='\0';
}

int main(){
	char a[100];
	int n;
	cin>>n;
	cin.ignore();
	int ms=0;
	char longest[100];


	for(int i=0;i<n;i++){
		cin.getline(a,100);
		int l=length(a);
		if(l>ms){
			// update the longest string
			COPY(longest,a);
			ms=l;
		}
	}
	cout<<"Largest : "<<longest<<endl;
	cout<<"length : "<<ms<<endl;

	// // cin.get();
	// cin.ignore();
	// cin.getline(a,100);

	// cout<<n<<endl;
	// cout<<a<<endl;
	// cout<<sizeof(a)<<endl;
	// cout<<length(a)<<endl;

	return 0;
}