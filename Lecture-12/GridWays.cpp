// GridWays
#include <iostream>
using namespace std;

int ways(int i,int j,int dp[][10]){
	if(i==0&&j==0){
		dp[i][j] = 1;
		return 1;
	}
	if(i<0||j<0){
		return 0;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	int ans = ways(i-1,j,dp)+ways(i,j-1,dp);
	dp[i][j] = ans;
	return ans;
}

int bottomUp(int i,int j){
	int dp[10][10]={0};
	for(int k=0;k<=i;k++){
		for(int l=0;l<=j;l++){
			if(k==0||l==0){
				dp[k][l] = 1;
			}
			else{
				dp[k][l] = dp[k-1][l] + dp[k][l-1];
			}
		}
	}
	for(int k=0;k<=i;k++){
		for(int l=0;l<=j;l++){
			cout<<dp[k][l]<<" ";
		}
		cout<<endl;
	}
	return dp[i][j];
}


int main(){
	int i,j;
	cin>>i>>j;
	int dp[10][10];

	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			dp[i][j] = -1;
		}
	}


	cout<<ways(i,j,dp)<<endl;
	cout<<bottomUp(i,j)<<endl;

	return 0;
}