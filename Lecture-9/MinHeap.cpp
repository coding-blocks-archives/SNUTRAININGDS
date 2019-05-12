// MinHeap
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Minheap{
	vector<int> v;
	
	void heapify(int indx){
		int left = 2*indx;
		int right = left+1;
		int min_indx = indx;

		if(left<v.size() && v[left]<v[min_indx]){
			min_indx = left;
		}
		if(right<v.size() && v[right]<v[min_indx]){
			min_indx = right;
		}

		if(min_indx != indx){
			swap(v[min_indx],v[indx]);
			heapify(min_indx);
		}
	}


public:

	Minheap(){
		v.push_back(-1); 
	}

	void push(int d){
		v.push_back(d);

		int indx = v.size()-1;
		int parent = indx/2;
		while(indx>1 && v[parent]>v[indx]){
			swap(v[parent],v[indx]);
			indx=parent;
			parent=parent/2;
		}
	}

	int top(){
		return v[1];
	}

	void pop(){
		int last = v.size()-1;

		swap(v[1],v[last]);
		v.pop_back(); // This will remove the last element or
		// the minimum element 
		heapify(1);
	}

	bool empty(){
		return v.size()==1;
	}

};

class MeraComparator{
public:
	bool operator()(int a,int b){
		return a>b;
	}
};

void PrintHeap(priority_queue<int,vector<int>,MeraComparator> h){
	while(!h.empty()){
		cout<<h.top()<<",";
		h.pop();
	}
	cout<<endl;
}

int main(){
	// Minheap h;
	priority_queue<int,vector<int>,MeraComparator> h;

	int n;
	int k;
	cin>>k;
	int count=0; // To find how many elements have been
	// inserted in the heap are they >=k or <k
	while(1){
		cin>>n;

		// if(count<k)
		if(n==-1){
			PrintHeap(h);
		}
		else if(count<k){
			h.push(n);
			count++;
		}
		else if(n>h.top()){
			h.pop();
			h.push(n);
		}




	}



	// h.push(10);
	// h.push(5);
	// h.push(4);
	// h.push(-10);
	// h.push(100);
	// h.push(2);
	// h.push(-1);

	// while(!h.empty()){
	// 	cout<<h.top()<<endl;
	// 	h.pop();
	// }




	return 0;
}