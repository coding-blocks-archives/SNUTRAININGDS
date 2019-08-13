// Nstairs
// Fibo
#include <iostream>
using namespace std;

int TopDown(int n,int k,int *dp){
	if(n==0){
		dp[n] = 1;
		return 1;
	}
	if(n<0){
		return 0;
	}
	if(dp[n]!=-1){
		return dp[n];
	}

	int ans = 0;
	for(int i=1;i<=k;i++){
		ans += TopDown(n-i,k,dp);
	}
	dp[n] = ans;
	return ans;
}
int Nstairs(int n,int k){
	if(n==0){
		return 1;
	}
	if(n<0){
		return 0;
	}


	int ans = 0;
	for(int i=1;i<=k;i++){
		ans += Nstairs(n-i,k);
	}
	return ans;
}

int BottomUp(int n,int k){
	int *dp = new int[n+1];
	dp[0] = 1;

	for(int i=1;i<=n;i++){
		int ans = 0;
		for(int j=1;j<=k;j++){
			if(i-j>=0){
				ans += dp[i-j];	
			}
		}
		dp[i] = ans;
	}
	// for(int i=0;i<=n;i++){
	// 	cout<<dp[i]<<" ";
	// }
	// cout<<endl;
	return dp[n];
}

int FastStairs(int n,int k){
	int *dp = new int[n+1];
	dp[0]=dp[1] = 1;
	for(int i=2;i<=n;i++){
		if(i-k-1>=0){
			dp[i] = 2*dp[i-1]-dp[i-k-1];
		}
		else{
			dp[i] = 2*dp[i-1];
		}
	}
	return dp[n];
}


int main(){
	int n,k=100000;
	cin>>n;
	int arr[100000];
	for(int i=0;i<100000;i++){arr[i]=-1;}	

	cout<<FastStairs(n,k)<<endl;
	cout<<TopDown(n,k,arr)<<endl;
	cout<<BottomUp(n,k)<<endl;
	cout<<Nstairs(n,k)<<endl;












	return 0;
}