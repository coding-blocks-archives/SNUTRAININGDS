// WavePrint
#include <iostream>
using namespace std;

int main(){
	int a[][4]={
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}
	};
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int col=0;col<4;col++){
		if(col%2==0){
			for(int row=0;row<3;row++){
				cout<<a[row][col]<<" ";
			}
		}
		else{
			for(int row=2;row>=0;row--){
				cout<<a[row][col]<<" "; 
			}
		}
	}
	cout<<endl;

	return 0;
}
