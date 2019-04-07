// FirstAndLast7
#include <iostream>
using namespace std;

int first7(int a[],int n,int i){
	if(i==n){
		return -1;
	}

	if(a[i]==7){
		return i;
	}

	int ChoteWaleKaAns=first7(a,n,i+1);
	return ChoteWaleKaAns;
}

int last7(int a[],int n,int i){
	if(i==n){
		return -1;
	}

	if(a[i]==7){
		int chota7=i;

		int AageWala7=last7(a,n,i+1);
		if(AageWala7>chota7){
			return AageWala7;
		}
		else{
			return chota7;
		}
	}

	int ChoteWaleKaAns=last7(a,n,i+1);
	return ChoteWaleKaAns;
}

int StringToInt(char a[],int n){
	if(n==0){
		return 0;
	}

	int last_digit=a[n-1]-'0';

	return StringToInt(a,n-1)*10+last_digit;

}

int main(){
	int a[]={1,3,4,7,6,7,7,7,7,8};
	int n=sizeof(a)/sizeof(int);

	cout<<first7(a,n,0)<<endl;
	cout<<last7(a,n,0)<<endl;
	cout<<StringToInt("1234",4)<<endl;

	return 0;
}