// CurrencyExchange
#include <iostream>
using namespace std;

int MinCoins(int amount,int *coins,int n,int *arr){
	if(amount == 0){
		arr[amount]= 0;
		return 0;
	}
	if(arr[amount]!=-1){
		return arr[amount];
	}

	int ans = INT_MAX;
	for(int i=0;i<n;i++){
		if(amount>=coins[i]){
			int chotaAns = MinCoins(amount-coins[i],coins,n,arr);
			if(chotaAns!=INT_MAX){
				ans = min(ans,chotaAns+1);
			}
		}
	}
	arr[amount] = ans;
	return ans;
}

int BottomUp(int amount,int* coins,int n){
	int *arr=new int[amount+1]; 
	for(int i=0;i<=amount;i++){
		arr[i] = INT_MAX;
	}
	arr[0] = 0;
	for(int rupay = 1;rupay<=amount;rupay++){
		for(int i=0;i<n;i++){
			if(rupay>=coins[i]){
				arr[rupay] = min(arr[rupay],arr[rupay-coins[i]]+1);
			}
		}
	}
	for(int i=0;i<=amount;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return arr[amount];
}


int main(){
	int coins[] = {1,2,5,10};
	int n = sizeof(coins)/sizeof(int);
	int amount;
	cin>>amount;
	int arr[100000];
	for(int i=0;i<100000;i++){arr[i]=-1;}
	
	cout<<MinCoins(amount,coins,n,arr)<<endl;
	cout<<BottomUp(amount,coins,n)<<endl;



	return 0;
}