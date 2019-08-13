// Fibo
#include <iostream>
using namespace std;

int fibo(int n){
	if(n==1||n==0){
		return n;
	}
	return fibo(n-1)+fibo(n-2);
}

int fibo1(int n,int *arr){
	if(n==1||n==0){
		arr[n] = n;
		return n;
	}
	// Before calculating the ans check
	if(arr[n]!=-1){
		return arr[n];
	}

	int ans =fibo1(n-1,arr)+fibo1(n-2,arr);
	arr[n] = ans; // Before return store the answer
	return ans;
}

int bottomUp(int n){
	int *arr = new int[n+1];

	arr[0] = 0;
	arr[1] = 1;

	for(int i=2;i<=n;i++){
		arr[i] = arr[i-1]+arr[i-2];
	}
	return arr[n];
}

int main(){
	int n;
	cin>>n;
	int arr[100000];
	for(int i=0;i<100000;i++){arr[i]=-1;}

	cout<<fibo1(n,arr)<<endl;
	cout<<bottomUp(n)<<endl;
	cout<<fibo(n)<<endl;

	return 0;
}