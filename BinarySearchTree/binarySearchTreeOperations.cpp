#include<bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	struct Node * left , * right;
	
	Node(int data){
		val = data;
		left = right = NULL;	
	}
};

void inOrderTraversal(struct Node* ptr){
	if(ptr){
		inOrderTraversal(ptr->left);
		cout<<ptr->val<<" ";
		inOrderTraversal(ptr->right);
	}
}
struct Node * minNonRecursive(struct Node * ptr){
	if(ptr == NULL)
		return NULL;
	
	while(ptr->left != NULL)
		ptr = ptr->left;
	
	return ptr;
}

struct Node * minRecursive(struct Node * ptr){
	if(ptr==NULL)
	return NULL;
	
	if(ptr->left)
		return minRecursive(ptr->left);
	return ptr;
}

struct Node * maxNonRecursive(struct Node * ptr){
	if(ptr == NULL)
		return NULL;
	
	while(ptr->right != NULL)
		ptr = ptr->right;
	
	return ptr;
}

struct Node * maxRecursive(struct Node * ptr){
	if(ptr==NULL)
	return NULL;
	
	if(ptr->right)
		return maxRecursive(ptr->right);
	return ptr;
}


struct Node * searchNonRecursive(struct Node * ptr, int sKey){
	if(ptr==NULL)
		return NULL;
		
	while(ptr!=NULL){
		if( sKey > ptr->val){
			ptr = ptr->right;
		}
		else if(sKey < ptr->val){
			ptr = ptr->left;
		}
		else if(sKey == ptr->val)
			return ptr;
		}
		return NULL;
	
}
//Note : during insertion makes sure to check 
// that tree may be empty i.e., first node is being 
// inserted so, root node may change thus, we return
// root pointer 

struct Node* insertNonRecursive(struct Node * root, int key){
	struct Node * ptr = root, * prev = NULL;
	
	//search node & mainter pointer to prev node i.e, parent
	while(ptr!=NULL){
		prev = ptr;
		if(key<ptr->val)
			ptr = ptr->left;
		else if(key>ptr->val)
			ptr = ptr->right;
		else if(key == ptr->val)
			return root;
	}
	
	if(prev !=NULL){ // tree is non empty
		if(key < prev->val)
			prev->left  = new Node(key);
		else 
			prev->right = new Node(key);
	}
	else if(prev == NULL)
	root = new Node(key);
	
	return root;
}

// leaf node
struct Node* case_a(struct Node * root, struct Node * par, struct Node * ptr){
	if(par == NULL) // delete root node & tree has only one node
		root = NULL;
		
	else if(ptr == par->left)
		par->left = NULL;
	else 
		par ->right = NULL;
	
	delete ptr;
	
	return root;	
}



// one child node 
struct Node * case_b(struct Node* root, struct Node * par, struct Node * ptr){
	struct Node * child;
	
	if(ptr->left != NULL)
		child = ptr->left;
	else if(ptr->right != NULL)
		child = ptr->right;
	
	if(par->left == ptr)
		par->left = child;
	else if(par->right == ptr)
		par->right = child;
		
	delete ptr;
	
	return root;
}

// two child node
struct Node * case_c(struct Node * root, struct Node * par, struct Node * ptr){
	struct Node * succ, *parsucc;
	
	// ptr is the node to be deleted
	// find inorder successor of ptr 
	
	parsucc = ptr;
	succ = ptr->right;
	
	while(succ->left != NULL)
	{
		parsucc = succ;
		succ = succ->left;
	}
	
	ptr->val = succ->val;
	
	if(succ->left == NULL && succ->right == NULL)
		root = case_a(root, parsucc, succ);
	else 
		root = case_b(root, parsucc, succ);
		
	return root;
	
}

struct Node * delNonRecursive(struct Node * root, int dKey){
	struct Node * par, * ptr;
	ptr = root;
	par = NULL;
	
	while(ptr!=NULL){
		if(dKey == ptr->val)
			break;
		par = ptr;
		
		if(dKey < ptr->val)
			ptr = ptr->left;
		else 
			ptr = ptr->right;
		
	}
	
	if(ptr==NULL)
		cout<<dKey<<" is not present in the tree\n";
	else if(ptr->left !=NULL && ptr->right != NULL) // 2 child exists
		root = case_c(root, par, ptr);
	else if(ptr->left != NULL ) // 1 child
		root = case_b(root, par, ptr);
	else if(ptr->right != NULL)
		root = case_b(root, par, ptr);
	else // no child
		root = case_a(root, par, ptr);
		
	return root;
	
}


 
int main(){
	struct Node * root;
	
	root = new Node(67);
	root->right = new Node(80);
	root->left = new Node(34);
	
	root->left->left = new Node(12);
	root->left->right = new Node(45);
	
	root->left->right->left  = new Node(38);
	root->left->right->right = new Node(60);
	
	root->right->left = new Node(78);
	root->right->right = new Node(95);
	root->right->left->right = new Node(79);
	
	
	//								67
	//					34					80
	//			12			45		78			95
	//						38	60		79		
	//
	//
	//
	
	inOrderTraversal(root);
	
	struct Node  * searchNode = searchNonRecursive(root, 12);
	if(searchNode != NULL)
		cout<<"\nElement found\n";
	else
		cout<<"\nElement not found\n";
		
	cout<<minRecursive(root)->val<<endl;
	
	cout<<maxRecursive(root)->val<<endl;
	cout<<maxNonRecursive(root)->val<<endl;
	
	
	root = insertNonRecursive(root, 1);
	
	inOrderTraversal(root);
	
	cout<<"\nCreate BST , enter number of nodes of BST : ";
	struct Node * root2  = NULL;
	
	int n;
	cin>>n;
	int t;
	for(int i  = 0; i<n; i++){
		cin>>t;
		root2 = insertNonRecursive(root2, t);
	}
	inOrderTraversal(root2);
	cout<<endl;
	
	
	root = delNonRecursive(root, 67);
	inOrderTraversal(root);
	return 0;
}
