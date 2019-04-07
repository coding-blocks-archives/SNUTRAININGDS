// PainterPartition
#include <iostream>
using namespace std;
#define ll long long int

bool KyaPaintHoPaaya(int arr[],int n,int k,int area){
	int current_painter=1;
	int total_area=0;

	for(int i=0;i<n;i++){
		if(total_area+arr[i]<=area){
			total_area+=arr[i];
		}
		else{
			current_painter++;
			total_area=arr[i];
			if(current_painter>k){
				return false;
			}
		}
	}
	return true;


}


int PainterPartition(int arr[],int n,int k){
	int s=0;
	int e;
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=arr[i];
	}
	e=sum;
	int ans=0;

	while(s<=e){
		int mid=(s+e)/2;
		if(KyaPaintHoPaaya(arr,n,k,mid)){
			ans=mid;
			e=mid-1;
		}
		else{
			s=mid+1;
		}
	}
	return ans;

}


int main(){
	int k,n;
	int arr[100];

	cin>>k>>n;
	for(int i=0;i<n;i++){cin>>arr[i];}

	cout<<PainterPartition(arr,n,k)<<endl;

	return 0;
}
