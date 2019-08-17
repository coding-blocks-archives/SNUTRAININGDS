// MinCost
#include <iostream>
using namespace std;

int MinCost(int i,int j,int cost[][4],int dp[][10]){
	// Base case
	if(i==0&&j==0){
		dp[i][j] = cost[i][j];
		return cost[i][j];
	}
	if(i<0||j<0){
		return 0;
	}
	if(dp[i][j]!=0){
		return dp[i][j];
	}
	if(i==0 && j>0){
		dp[i][j] = cost[i][j] + MinCost(i,j-1,cost,dp);
		return dp[i][j];
	}
	else if(i>0 && j==0){
		dp[i][j] = cost[i][j] + MinCost(i-1,j,cost,dp);
		return dp[i][j];
	}
	else{
		int op1 = cost[i][j] + MinCost(i-1,j,cost,dp);
		int op2 = cost[i][j] + MinCost(i,j-1,cost,dp);
		dp[i][j] = min(op1,op2);
		return dp[i][j];
	}
}






int main(){
	int cost[][4]={
		{1,1,1,5},
		{4,8,1,6},
		{3,4,1,1},
		{1,2,10,1}
	};
	int dp[10][10]={0};
	int i,j;
	cin>>i>>j;

	cout<<MinCost(i,j,cost,dp)<<endl;
	// for(int i=0;i<4;i++){
	// 	for(int j=0;j<4;j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	return 0;
}
