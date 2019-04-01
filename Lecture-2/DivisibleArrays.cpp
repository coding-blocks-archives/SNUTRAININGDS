// DivisibleArrays
#include <iostream>
using namespace std;

int main(){
	int a[]={1,2,3,5,6};
	int n=sizeof(a)/sizeof(int);

	int csum[1000]={0};
	int freq[1000]={0};

	// Find the cumulative sum and %n
	int sum=0;
	freq[0]=1;
	for(int i=0;i<n;i++){
		sum += a[i];
		sum=sum%n;
		sum = (sum+n)%n;
		freq[sum]++;
	}

	//calculate the number of subarrays
	int ans=0;
	for(int i=0;i<n;i++){
		int m=freq[i];
		ans = ans + (m*(m-1))/2;
	}
	cout<<ans<<endl;

	return 0;
}