// ReadPages.cpp
#include <iostream>
#include <cmath>
using namespace std;
#define ll long long int

bool isValid(ll books[],ll n,ll students,ll pages){
	ll current_student=1;
	ll current_pages=0;

	for(ll i=0;i<n;i++){
		if(current_pages+books[i]<=pages){
			current_pages+=books[i];
		}
		else{
			current_student++;
			current_pages=books[i];
			if(current_student>students){
				return false;
			}
		}
	}
	return true;
}


ll ReadPages(ll books[],ll n,ll m){
	ll s=0,e;
	ll sum=0;
	for(ll i=0;i<n;i++){
		sum+=books[i];
		s=max(s,books[i]);
	}
	e=sum;
	ll ans = 0;
	while(s<=e){
		ll mid=(s+e)/2;
		if(isValid(books,n,m,mid)){
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
	ll n,m;
	ll books[100001];

	cin>>n>>m;

	for(ll i=0;i<n;i++){
		cin>>books[i];
	}

	cout<<ReadPages(books,n,m)<<endl;


	return 0;
}