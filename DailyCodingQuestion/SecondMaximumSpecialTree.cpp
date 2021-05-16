#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node * left;
	struct Node * right;
	
	Node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};

void SecondLargestValue(struct Node * temp,  int * res){
		if(temp == NULL ||  ( temp->left == NULL && temp->right == NULL) )
			return ;
			
		* res = max ( min ( temp->left->data, temp->right->data) , * res );
		
		if(temp->left->data > temp->right->data)
			SecondLargestValue(temp->left,  res);
		else
			SecondLargestValue(temp->right,  res);
	
}
int main(){
	
	struct Node * root, * temp = NULL;
	
	int max_ , res ;
	
	root = new Node(9);
	
	root->left = new Node(6);
	root->right = new Node(9);
	
	root->left->left = new Node(6);
	root->left->right = new Node(4);
	root->right->left = new Node(4);
	root->right->right = new Node(9);
	
	root->right->right->left = new Node(7);
	root->right->right->right = new Node(9);
	
	
	SecondLargestValue(root,  &res);
	
	cout<<res<<"\n";
}
