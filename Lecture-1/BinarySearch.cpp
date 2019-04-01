// BinarySearch
#include <iostream>
using namespace std;

int main(){
	int a[]={1,3,4,5,6,7,8};
	int n=sizeof(a)/sizeof(int);

	int s=0;
	int e=n-1;
	int key;
	cin>>key;
	while(s<=e){
		int mid=(s+e)/2;
		if(a[mid]==key){
			cout<<"Element found at index: "<<mid<<endl;
			break;
		}
		else if(a[mid]>key){
			e=mid-1;
		}
		else{
			s=mid+1;
		}
	}


	return 0;
}