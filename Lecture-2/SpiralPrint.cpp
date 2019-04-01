// SpiralPrint
#include <iostream>
using namespace std;

int main(){
	int a[][4]={
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};
	int r,c;
	cin>>r>>c;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	int sr=0;
	int er=r-1;
	int sc=0;
	int ec=c-1;


	while(sr<=er && sc<=ec){
		for(int i=sc;i<=ec;i++){
			cout<<a[sr][i]<<" ";
		}
		sr++;
		for(int i=sr;i<=er;i++){
			cout<<a[i][ec]<<" ";
		}
		ec--;
		if(sr<er){
			for(int i=ec;i>=sc;i--){
				cout<<a[er][i]<<" ";
			}
			er--;
		}
		if(sc<ec){
			for(int i=er;i>=sr;i--){
				cout<<a[i][sc]<<" ";
			}
			sc++;
		}
	}
	cout<<endl;











	return 0;
}