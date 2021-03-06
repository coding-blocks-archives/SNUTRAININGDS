#include <iostream>
using namespace std;

int LCS(string s1,string s2){
	int dp[100][100];
	int i,j;
	int m = s1.size();
	int n = s2.size();

	for(i = 0; i <= m ; i++){
		for(j = 0; j <= n; j++){
			if(i==0||j==0){
				dp[i][j] = 0;
			}
			else if(s1[i-1] == s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}

	int index = dp[m][n];
	char* lcs = new char[index];
	i = s1.size();
	j = s2.size();
	lcs[index] = '\0';
	index--;

	while(i>0 && j>0){
		if(s1[i-1] == s2[j-1]){
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
	string a= "abacc";
	string b= "aabccs";

	cout<<LCS(a,b)<<endl;

	return 0;
}