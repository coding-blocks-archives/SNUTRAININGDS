// MinSteps
#include <iostream>
#include <climits>
using namespace std;

int minSteps(int n){
	// Base case
	if(n==1){
		return 0;
	}

	// Recursive case
	int op1,op2,op3;
	op1 = op2 = op3 = INT_MAX;
	if(n%3 == 0){
		op1 = minSteps(n/3)+1;
	}
	if(n%2 == 0){
		op2 = minSteps(n/2)+1;
	}
	op3 = minSteps(n-1)+1;
	return min(op1,min(op2,op3));
	
	
}


int minSteps1(int n,int *arr){
	// Base case
	if(n==1){
		arr[n] = 0;
		return 0;
	}
	if(arr[n]!=-1){
		return arr[n];
	}
	// Recursive case
	int op1,op2,op3;
	op1 = op2 = op3 = INT_MAX;
	if(n%3 == 0){
		op1 = minSteps1(n/3,arr)+1;
	}
	if(n%2 == 0){
		op2 = minSteps1(n/2,arr)+1;
	}
	op3 = minSteps1(n-1,arr)+1;
	int ans =  min(op1,min(op2,op3));
	arr[n] = ans;
	return ans;
}

int bottomUp(int n){
	int *arr = new int[n+1];
	arr[1] = 0;

	for(int i=2;i<=n;i++){
		int op1,op2,op3;
		op1=op2=op3 = INT_MAX;
		if(i%3==0){
			op1 = arr[i/3]+1;
		}
		if(i%2==0){
			op2 = arr[i/2]+1;
		}
		op3 = arr[i-1]+1;
		arr[i] = min(op1,min(op2,op3));
	}
	return arr[n];
}

int main(){
	int n;
	cin>>n;
	int arr[100000];
	for(int i=0;i<100000;i++){arr[i]=-1;}

	cout<<minSteps1(n,arr)<<endl;
	cout<<bottomUp(n)<<endl;
	cout<<minSteps(n)<<endl;
	


	return 0;
}