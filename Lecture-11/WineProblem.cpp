// WineProblem
#include <iostream>
using namespace std;
int WineProblem(int *wine,int day,int i,int j){
	if(i>j){
		return 0;
	}

	int op1 = wine[i]*day + WineProblem(wine,day+1,i+1,j);
	int op2 = wine[j]*day + WineProblem(wine,day+1,i,j-1);
	return max(op1,op2);
}

int TopDown(int *wine,int day,int i,int j,int dp[100][100]){
	if(i>j){
		dp[i][j] = 0;
		return 0;
	}
	if(dp[i][j]!=0){
		return dp[i][j];
	}

	int op1 = wine[i]*day + TopDown(wine,day+1,i+1,j,dp);
	int op2 = wine[j]*day + TopDown(wine,day+1,i,j-1,dp);
	dp[i][j] = max(op1,op2);
	return dp[i][j];
}

int main(){
	int wine[]={2,3,5,1,4};
	int n=sizeof(wine)/sizeof(int);
	int dp[100][100]={0};


	cout<<WineProblem(wine,1,0,n-1)<<endl;
	cout<<TopDown(wine,1,0,n-1,dp)<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	return 0;
}