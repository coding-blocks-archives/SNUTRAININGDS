// N_Queen
#include <iostream>
using namespace std;

bool isSafe(int board[][10],int i,int j,int n){
	// check row and columns
	for(int k=0;k<n;k++){
		if(board[k][j] || board[i][k]){
			return false;
		}
	}
	// Check for diagnols 
	int k=i;
	int l=j;

	// Check the right diagnol
	while(k>=0 && l<n){
		if(board[k][l]){
			return false;
		}
		k--;
		l++;
	}
	// Check the left diagnol
	k=i;
	l=j;
	while(k>=0 && l>=0){
		if(board[k][l]){
			return false;
		}
		k--;
		l--;
	}

	// If queen is no where then return that
	// the location is safe to put the queen
	// i.e return true;
	return true;

}


bool NQueen(int board[][10],int i,int n){
	// base case
	if(i==n){
		// Print the board
		for(int k=0;k<n;k++){
			for(int l=0;l<n;l++){
				cout<<board[k][l]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return false;
	}

	// Recursive case
	for(int j=0;j<n;j++){
		if(isSafe(board,i,j,n)){
			// If it is safe to put then place the
			// Queen
			board[i][j]=1;
			bool KyaBaakiRakhPaaye=NQueen(board,i+1,n);
			if(KyaBaakiRakhPaaye){
				return true;
			}
			// Remove the placed Queen
			board[i][j]=0;
		}		

	}
	return false;
}


int main(){
	int board[10][10];
	int n;
	cin>>n;

	NQueen(board,0,n);

	return 0;
}
