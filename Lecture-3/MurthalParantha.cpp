// MurthalParantha
#include <iostream>
#include <climits>
using namespace std;

bool isValid(int arr[],int cooks,int paranthas,int total_time){
	for(int i=0;i<cooks;i++){
		int current_time=0;
		int fact=1;
		while(current_time+fact*arr[i]<=total_time){
			paranthas--;
			current_time+=fact*arr[i];
			fact++;

			if(paranthas==0){
				return true;
			}
		}
	}

	return paranthas==0;
}


int MurthalParantha(int arr[],int cooks,int paranthas){
	int s=0;
	int e=INT_MAX;
	int ans=INT_MAX;

	while(s<=e){
		int mid=(s+e)/2;
		if(isValid(arr,cooks,paranthas,mid)){
			ans=min(ans,mid);
			e=mid-1;
		}
		else{
			s=mid+1;
		}
	}
	return ans;
}


int main(){

	int p,cooks;
	int arr[1000001];

	cin>>p>>cooks;
	for(int i=0;i<cooks;i++){cin>>arr[i];}

	cout<<MurthalParantha(arr,cooks,p)<<endl;	

	return 0;
}