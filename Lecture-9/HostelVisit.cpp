// HostelVisit
#include <iostream>
#include <queue>
using namespace std;
#define ll long long

ll int RocketDistance(ll x,ll y){
	return x*x+y*y;
}

int main(){
	priority_queue<ll> h;
	ll q,k,type;
	cin>>q;
	cin>>k;
	ll count=0;
	while(q--){
		cin>>type;
		if(type==1){
			ll x,y;
			cin>>x>>y; // Input Hostel Co-ordinates
			ll RD = RocketDistance(x,y);
			if(count==k){
				if(RD<h.top()){
					h.pop();
					h.push(RD);
				}
			}
			else{
				h.push(RD);
				count++;
			}
		}
		else{ // for type : 2 query
			cout<<h.top()<<endl;
		}	
	}



	return 0;
}