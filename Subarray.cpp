// Subarray
#include <iostream>
#include <climits>
using namespace std;

int main(){
	int a[]={4,-3,-2,6,-8,7};
	int n=sizeof(a)/sizeof(int);
	
	// O(N^3)
	// for(int i=0;i<n;i++){
	// 	for(int j=i;j<n;j++){
	// 		cout<<"{";
	// 		for(int k=i;k<=j;k++){
	// 			cout<<a[k]<<",";
	// 		}
	// 		cout<<"\b \b"<<"}"<<endl;
	// 	}
	// }

	// O(N^2)
	// int csum[1000]={0};
	// csum[0]=a[0];
	// int sum=a[0];
	// for(int i=1;i<n;i++){
	// 	sum += a[i];
	// 	csum[i]=sum;
	// }
	// int ms=INT_MIN; // Will store the result of the max subarray
	// int cs=0;
	// for(int i=0;i<n;i++){
	// 	for(int j=i;j<n;j++){
	// 		if(i-1>=0){
	// 			cs=csum[j]-csum[i-1];
	// 		}
	// 		else{
	// 			cs=csum[j];
	// 		}
	// 		if(cs>ms){
	// 			ms=cs;
	// 		}
	// 	}
	// }

	// cout<<"Max sum is : "<<ms<<endl;

	int ms=a[0];
	int cs=0;
	int csum[1000]={0};
	
	int sum=a[0];
	csum[0]=a[0];
	for(int i=1;i<n;i++){
		sum += a[i];
		if(sum<0){
			sum=0;
		}
		csum[i]=sum;
	}

	for(int i=0;i<n;i++){
		cout<<csum[i]<<" ";
	}
	cout<<endl;










	return 0;
}