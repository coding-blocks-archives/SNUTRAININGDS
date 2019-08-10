#include <iostream>
using namespace std;
class node{
public:
	int data;
	node* left;
	node* right;
	node(int d):data(d),left(NULL),right(NULL){}
};

node* ArrayToBST(int *arr,int s,int e){
	if(s>e){
		return NULL;
	}

	int mid = (s+e)/2;
	node* root = new node(arr[mid]);
	root->left = ArrayToBST(arr,s,mid-1);
	root->right = ArrayToBST(arr,mid+1,e);
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

int main(){
	node* root = NULL;
	int arr[]={1,3,4,5,6,7,8,9,10,11,12,13};
	int n = sizeof(arr)/sizeof(int);

	root = ArrayToBST(arr,0,n-1);

	return 0;
}