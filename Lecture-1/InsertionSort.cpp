// InsertionSort
#include <iostream>
using namespace std;

int main(){
	int a[]={5,4,3,1,2};
	int n=sizeof(a)/sizeof(int);
	int j;
	for(int i=1;i<n;i++){
		int pickedup_Card=a[i];
		for(j=i-1;j>=0&&pickedup_Card<a[j];j--){
			a[j+1]=a[j];
		}
		a[j+1]=pickedup_Card;
	}

	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;	

	return 0;
}