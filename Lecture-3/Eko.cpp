// Eko.cpp
#include <iostream>
#include <climits>
using namespace std;
#define ll long long int

bool isValid(ll arr[],ll n,ll wood,ll height){
	ll current_choppedWood=0;
	for(ll i=0;i<n;i++){
		if(arr[i]-height>=0){
			current_choppedWood+=arr[i]-height;
			if(current_chop pedWood>=wood){
				return true;
			}
		}
	}
	return false;
}


ll Trees(ll arr[],ll n,ll wood){
	ll s=0;
	ll e=INT_MAX;

	ll ans=0;
	while(s<=e){
		ll mid=(s+e)/2;
		if(isValid(arr,n,wood,mid)){
			ans=mid;
			s=mid+1;
		}
		else{
			e=mid-1;
		}

	}
	return ans;
}


int main(){
	ll n,wood;

	ll arr[1000001];

	cin>>n>>wood;

	for(int i=0;i<n;i++){cin>>arr[i];}

		cout<<Trees(arr,n,wood)<<endl;


	return 0;
}