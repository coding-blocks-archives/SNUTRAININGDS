// PivotElement
#include <iostream>
using namespace std;

int main(){
	int a[]={5,5,6,7,8,9,1,2,3,4};
	int n=sizeof(a)/sizeof(int);

	int s=0;
	int e=n-1;
	int ans=-1;
	while(s<=e){
		int mid=(s+e)/2;
		if(mid+1<n && a[mid]>a[mid+1]){
			ans=mid;
			break;
		}
		else if(mid-1>=0 && a[mid]<a[mid-1]){
			ans=mid-1;
			break;
		}
		else if(a[s]<a[mid]){
			s=mid+1;
		}
		else{
			e=mid-1;
		}
	}
	cout<<"Ans : "<<ans<<endl;


	return 0;
}