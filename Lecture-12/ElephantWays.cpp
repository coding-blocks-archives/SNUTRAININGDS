// ElephantWays
#include <iostream>
using namespace std;
int ways(int i,int j){
	// base case
	if(i==0&&j==0){
		return 1;
	}
	// recursive case
	int ans = 0;
	for(int k=0;k<i;k++){
		ans += ways(k,j);
	}
	for(int k=0;k<j;k++){
		ans += ways(i,k);
	}
	return ans;
}

int topDown(int i,int j,int dp[][10]){
	// base case
	if(i==0&&j==0){
		dp[i][j] = 1;
		return 1;
	}
	// recursive case
	if(dp[i][j]!=0){
		return dp[i][j];
	}
	int ans = 0;
	for(int k=0;k<i;k++){
		ans += topDown(k,j,dp);
	}
	for(int k=0;k<j;k++){
		ans += topDown(i,k,dp);
	}
	dp[i][j] = ans;
	return ans;
}

int bottomUp(int i,int j){
	int dp[10][10]={0};

	dp[0][0]=1;
	int x = 1;
	for(int k=1;k<=j;k++){
		dp[0][k] = x;
		x=x*2;
	}
	x = 1;
	for(int k=1;k<=i;k++){
		dp[k][0] = x;
		x=x*2;
	}

	for(int k=1;k<=i;k++){
		for(int l=1;l<=j;l++){
			int ans=0;
			for(int m=0;m<k;m++){
				ans += dp[m][l];
			}
			for(int m=0;m<l;m++){
				ans += dp[k][m];
			}
			dp[k][l] = ans;
		}
	}
	for(int k=0;k<=i;k++){
		for(int l=0;l<=j;l++){
			cout<<dp[k][l]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	return dp[i][j];
}

int main(){
	int i,j;
	cin>>i>>j;
	int dp[10][10]={0};
	cout<<ways(i,j)<<endl;
	cout<<topDown(i,j,dp)<<endl;
	cout<<bottomUp(i,j)<<endl;



	return 0;
}