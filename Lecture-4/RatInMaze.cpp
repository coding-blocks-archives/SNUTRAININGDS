// RatInMaze
#include <iostream>
using namespace std;

bool RatInMaze(char maze[][5],int sol[][10],int i,int j,int n,int m){
	if(i==n-1 && j==m-1){
		// Print the solution
		sol[i][j]=1;
		for(int k=0;k<n;k++){
			for(int l=0;l<m;l++){
				cout<<sol[k][l]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return false;
	}


	// Recursive case
	// Assume the current cell as a part of the solution
	sol[i][j]=1;
	

	// Then check righwards 
	if(j+1<m && maze[i][j+1]!='X'){
		bool KyaBaatBani=RatInMaze(maze,sol,i,j+1,n,m);
		if(KyaBaatBani){
			return true;
		}
	}
	// Then Check downwards
	if(i+1<n && maze[i+1][j]!='X'){
		bool KyaBaatBani=RatInMaze(maze,sol,i+1,j,n,m);
		if(KyaBaatBani){
			return true;
		}
	}
	// Assumed cell cannot be the part of the ans
	// make it zero and return false
	sol[i][j]=0;
	return false;
}


int main(){
	char maze[][5]={
		"OOOO",
		"OOXX",
		"OOOO",
		"XXOO"
	};

	int sol[10][10]={0};

	RatInMaze(maze,sol,0,0,4,4);

	return 0;
}			
			
			
			
