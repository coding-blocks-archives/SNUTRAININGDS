// BubbleSort
#include <iostream>
using namespace std;
#define ll long long int

void BubbleSort(int a[],int n,int i){
	if(i==n-1){
		return;
	}

	for(int j=0;j<n-1;j++){
		if(a[j]>a[j+1]){
			swap(a[j],a[j+1]);
		}
	}

	BubbleSort(a,n,i+1);
}


int main(){
	int a[]={6,5,4,2,1,0};
	int n=sizeof(a)/sizeof(int);

	BubbleSort(a,n,0);

	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;




	return 0;
}