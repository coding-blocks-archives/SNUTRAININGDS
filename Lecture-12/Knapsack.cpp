// Knapsack
#include <iostream>
using namespace std;

int Knapsack(int *price,int* wt,int capacity,int n){
	if(n==0||capacity==0){
		return 0;
	}
	int op1=INT_MIN,op2=INT_MIN;
	if(wt[n-1]<=capacity){
		op1 = price[n-1] + Knapsack(price,wt,capacity-wt[n-1],n-1);
	}
	op2 = 0 + Knapsack(price,wt,capacity,n-1);
	return max(op1,op2);
}

int topDown(int *price,int* wt,int capacity,int n,int dp[][10]){
	if(n==0||capacity==0){
		dp[n][capacity] = 0;
		return 0;
	}
	if(dp[n][capacity]!=0){
		return dp[n][capacity];
	}
	int op1=INT_MIN,op2=INT_MIN;
	if(wt[n-1]<=capacity){
		op1 = price[n-1] + Knapsack(price,wt,capacity-wt[n-1],n-1);
	}
	op2 = 0 + Knapsack(price,wt,capacity,n-1);
	dp[n][capacity] = max(op1,op2);
	return max(op1,op2);
}

int bottomUp(int *price,int* wt,int capacity,int N){
	int dp[10][10]={0};
	for(int n=0;n<=N;n++){
		for(int c=0;c<=capacity;c++){
			if(n==0||c==0){
				dp[n][c] = 0;
			}
			else{
				int op1=INT_MIN,op2=INT_MIN;
				if(wt[n-1]<=c){
					op1=price[n-1]+dp[n-1][c-wt[n-1]];
				}
				op2 = 0 + dp[n-1][c];
				dp[n][c] = max(op1,op2);
			}
		}
	}
	for(int n=0;n<=N;n++){
		for(int c=0;c<=capacity;c++){
			cout<<dp[n][c]<<" ";
		}
		cout<<endl;
	}	
	return dp[N][capacity];
}

int main(){
	int price[]={3,4,4,4};
	int wt[]={1,4,5,2};
	int n=sizeof(price)/sizeof(int);
	int capacity = 6;
	cout<<Knapsack(price,wt,capacity,n)<<endl;
	int dp[10][10]={0};
	cout<<topDown(price,wt,capacity,n,dp)<<endl;

	cout<<bottomUp(price,wt,capacity,n)<<endl;

	return 0;
}