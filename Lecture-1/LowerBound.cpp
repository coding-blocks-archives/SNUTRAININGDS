// LowerBound
#include <iostream>
using namespace std;

int main(){
	int a[]={1,1,1,2,2,2,2,2,2,3,4,5,7};
	int n=sizeof(a)/sizeof(int);

	int s=0;
	int e=n-1;
	int ans=-1;
	int key=2;
	while(s<=e){
		int mid=(s+e)/2;
		if(a[mid]==key){
			ans=mid;
			e=mid-1;
		}
		else if(a[mid]>key){
			e=mid-1;
		}
		else{
			s=mid+1;
		}
	}

	cout<<"Lower bound is : "<<ans<<endl;


	return 0;
}