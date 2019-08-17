// LCS
#include <iostream>
using namespace std;

int LCS(string s1,string s2){
	int dp[10][10]={0};
	int m = s1.size();
	int n = s2.size();

	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0||j==0){
				dp[i][j] = 0;
			}
			else if(s1[i-1]==s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}	
	int index = dp[m][n];
	char *lcs = new char[index+1];
	lcs[index] = '\0';
	index--;
	int i=s1.size();
	int j=s2.size();
	while(index>=0){
		if(s1[i-1]==s2[j-1]){
			// cout<<s1[i-1]<<endl;
			lcs[index] = s1[i-1];
			i--;
			j--;
			index--;
		}
		else if(dp[i-1][j]>dp[i][j-1]){
			i--;
		}
		else{
			j--;
		}
	}
	cout<<lcs<<endl;

	return dp[m][n];
}

int main(){
	string s1 = "acdbcaad";
	string s2 = "cbcad";
	
	cout<<LCS(s1,s2)<<endl;

	return 0;
}