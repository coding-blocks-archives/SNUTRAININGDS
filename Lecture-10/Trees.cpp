// BinaryTrees
#include <iostream>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;

class node{
public:	
	int data;
	node* left;
	node* right;

	node(int d){
		data = d;
		left = right = NULL;
	}
};

node* InsertInBST(node* root,int data){
	if(root == NULL){
		root = new node(data);
		return root;
	}

	if(data<=root->data){
		root->left=InsertInBST(root->left,data);
	}
	else{
		root->right=InsertInBST(root->right,data);
	}
	return root;
}


node* BuildTree(){
	node* root=NULL;

	int data;
	cin>>data;

	while(data!=-1){
		root = InsertInBST(root,data);

		cin>>data;
	}
	return root;
}


void LevelOrderPrint(node* root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		node* temp = q.front();
		q.pop();
		if(temp==NULL){
			cout<<endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			cout<<temp->data<<" ";

			if(temp->left!=NULL){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}
	}
}

void FindDistance(node* root,int &min_hd,int &max_hd,int hd){
	if(root == NULL){
		return;
	}

	if(hd>max_hd){
		max_hd = hd;
	}
	if(hd<min_hd){
		min_hd = hd;
	}
	FindDistance(root->left,min_hd,max_hd,hd-1);
	FindDistance(root->right,min_hd,max_hd,hd+1);
}

void Print(node* root,int i,int hd){
	if(root == NULL){
		return;
	}
	if(i==hd){
		cout<<root->data<<" ";
	}
	Print(root->left,i,hd-1);
	Print(root->right,i,hd+1);
}

void PrintVerticalOrder(node* root){
	int min_hd = INT_MAX;
	int max_hd = INT_MIN;

	FindDistance(root,min_hd,max_hd,0);
	// cout<<min_hd<<" "<<max_hd<<endl;
	for(int i=min_hd;i<=max_hd;i++){
		Print(root,i,0);
		cout<<endl;
	}

}

int main(){
	node* root = NULL;

	root = BuildTree();
	// LevelOrderPrint(root);

	PrintVerticalOrder(root);

	return 0;
}