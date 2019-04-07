// TOH.cpp
#include <iostream>
using namespace std;

void toh(int n,char source,char helper,char dest){
	if(n==0){
		return;
	}

	// Recursive
	toh(n-1,source,dest,helper);
	cout<<"Take disk "<<n<<" from "<<source<<" to "<<dest<<endl;
	toh(n-1,helper,source,dest);

}


int main(){
	int n;
	cin>>n;

	toh(n,'A','B','C');

	return 0;
}