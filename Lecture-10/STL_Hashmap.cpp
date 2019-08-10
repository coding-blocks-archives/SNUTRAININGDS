// Hashmap_STL
#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

class Fruit{
	int price;
	string color;
	string shape;
	int sweetness;

	void Print(){
		cout<<"Price : "<<price<<endl;
		cout<<"Color : "<<color<<endl;
		cout<<"Shape : "<<shape<<endl;
		cout<<"Sweet : "<<sweetness<<endl<<endl;
	}
public:

	Fruit(int p,string c,string s,int sw){
		price = p;
		color = c;
		shape = s;
		sweetness = sw;
	}

	friend ostream& operator<<(ostream &os,Fruit f);
};

ostream& operator<<(ostream &os,Fruit f){
	f.Print();
	return os;
}


int main(){

	map<string,Fruit> h;

	Fruit a(100,"yellow","Round",80);
	Fruit b(150,"Red","Round",60);
	Fruit c(40,"Green","Oval",70);
	// cout<<a<<b<<c;
	
	h.insert(make_pair("Mango",a));
	h.insert(make_pair("Apple",b));
	h.insert(make_pair("PineApple",c));

	for(auto node:h){
		cout<<node.first<<endl<<node.second;
	}











	// map<string,int> h; 

	// pair<string,int> p;
	// p.first = "Mango";
	// p.second= 100;

	// h.insert(p); // insertion in unordered_map

	// // Insertion - 2nd way
	// h.insert(make_pair("Apple",150));
	// // Insertion - 3rd way
	// h["PineApple"] = 20;
	// h["Kiwi"] = 40;

	// // for each loop
	// for(auto node:h){
	// 	cout<<node.first<<","<<node.second<<endl;
	// }






	return 0;
}