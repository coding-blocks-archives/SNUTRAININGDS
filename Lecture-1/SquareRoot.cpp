#include <iostream>
using namespace std;

int main(){
	float i=0;
	int key;
	cin>>key;
	float inc=0.1;
	int precision=3;

	int current_precision=0;

	while(current_precision<=precision){

		while(i*i<=key){
			i=i+inc;
		}
		i=i-inc;
		inc=inc/10;
		current_precision++;
	}


	cout<<i<<endl;

	return 0;
}