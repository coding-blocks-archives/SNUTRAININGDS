// AggressiveCows
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long int
bool KyaPlaceHoPaai(ll arr[],ll n,ll cows,ll dist){
	ll placed_cows=1;
	ll pos=arr[0];
	for(ll i=1;i<n;i++){
		if(arr[i]-pos>=dist){
			placed_cows++;
			pos=arr[i];
			if(placed_cows==cows){
				return true;
			} 
		}
	}
	return placed_cows==cows;
}

int AggressiveCows(ll arr[],ll n,ll cows){
	ll s=0;
	ll e=arr[n-1];
	ll ans=0;
	while(s<=e){
		ll mid=(s+e)/2;

		if(KyaPlaceHoPaai(arr,n,cows,mid)){
			ans=max(ans,mid);
			s=mid+1;
		}
		else{
			e=mid-1;
		}
	}
	return ans;
}

int main(){
	ll t,n,cows;
	cin>>t;
	ll arr[1000001];

	while(t--){
	cin>>n>>cows;

	for(ll i=0;i<n;i++){cin>>arr[i];}
	sort(arr,arr+n);

	cout<<AggressiveCows(arr,n,cows)<<endl;

	}

	return 0;
}