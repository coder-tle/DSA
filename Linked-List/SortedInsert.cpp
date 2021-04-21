#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node * ptr;
	
	Node(int val){
		data = val;
		ptr = NULL;
	}
	
};
void ReleaseAllocatedMemory(struct Node * head){
		struct Node * prev = head;
		while(head!=NULL){
			prev = head;
			head = head->ptr;
			delete prev;
		}
}
struct Node * SortedInsert(struct Node * head, struct Node * a){
	if(head==NULL){
		head = a;
		return head;
	}
	else if(head->data > a->data ){ // you need to compare with data , head->data > a->data
		a->ptr = head;
		head = a;
		return head;
	}
	struct Node * temp = head, * prev;
	
	while(temp != NULL && temp->data < a->data){
		prev = temp;
		temp = temp->ptr;
	}
	
	prev->ptr = a;
	a->ptr = temp;
	return head;
}


void DisplayLL(struct Node * head){
	struct Node * temp = head;
	cout<<"Printing Linked List\n";
	while(temp != NULL){
		cout<<temp->data<<" ";
		// increment was missing
		temp = temp->ptr;
	}
	cout<<endl;
}
int main(){
		int n;
		cout<<"Enter number of nodes of linked list : \n";
		cin>>n;
		struct Node * head = NULL, * temp;
		int t;
		
		for(int i = 0; i<n; i++){
			cin>>t;
			
			temp = new Node(t);
			head = SortedInsert(head, temp);
			DisplayLL(head);
		}
		//delete head; // this just release s memory for the head node
		ReleaseAllocatedMemory(head);
		return 0;
}
