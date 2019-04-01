// BinarySearch_square
#include <iostream>
using namespace std;

int main(){
	int ans=-1;

	int n;
	cin>>n;

	int s=0;
	int e=n-1;
	int key=n;
	while(s<=e){
		int mid=(s+e)/2;
		if(mid*mid==key){
			ans=mid;
			break;
		}
		else if(mid*mid<key){
			ans=mid;
			s=mid+1;
		}
		else{
			e=mid-1;
		}
	}

	cout<<ans<<endl;




	return 0;
}