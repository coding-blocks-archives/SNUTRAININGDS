// Two_DArray
#include <iostream>
using namespace std;

int main(){
	int a[][3]={
		{1,2,3},
		{4,5,6},
		{7,8,9},
		{10,11,12}
	};
	int b[10][10]={0};
	// for(int row=0;row<4;row++){
	// 	for(int col=0;col<3;col++){
	// 		cout<<a[row][col]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>b[i][j];
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}	








	return 0;
}