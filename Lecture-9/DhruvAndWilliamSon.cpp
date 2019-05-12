// DhruvAndWilliamSon
#include <iostream>
#include <queue>
using namespace std;
#define ll long long 

class MeraComparator{
public:
	bool operator()(int a,int b){
		return a>b;
	}
};


int main(){
	priority_queue<int,vector<int>,MeraComparator> minh;
	priority_queue<int,vector<int>,MeraComparator> maxh;


	ll int q;
	ll int count=0;
	int a[100001]={0};
	cin>>q;

	while(q--){

		string s;

		while(!minh.empty() && a[minh.top()]<=0){
			minh.pop();
		}

		while(!maxh.empty() && a[(-1)*maxh.top()]<=0){
			maxh.pop();
		}


		cin>>s;

		if(s=="CountHigh"){
			if(count==0){
				cout<<"-1"<<endl;
			}
			else{
				ll int el = -1*maxh.top();
				cout<<a[el]<<endl;
			}

		}
		else if(s=="CountLow"){
			if(count==0){
				cout<<"-1"<<endl;
			}
			else{
				ll int el = minh.top();
				cout<<a[el]<<endl;
			}
		}
		else if(s=="Push"){
			ll int n;
			cin>>n;
			a[n]++;
			minh.push(n);
			maxh.push(-1*n);
			count++;

		}
		else{ // s=="Diff"
			if(count==0){
				cout<<"-1"<<endl;
			}
			else{
				int n1 = minh.top();
				int n2 = -1*maxh.top();

				if(n1!=n2){
					a[n1]--;
					count--;
				}
				a[n2]--;
				count--;

				cout<<n2-n1<<endl;
			}
		}









	}





	return 0;
}