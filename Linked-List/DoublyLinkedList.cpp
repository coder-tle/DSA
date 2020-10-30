// C++ Program for implementation of 
// Doubly Linked List with its operation

#include<bits/stdc++.h>
using namespace std;

struct node{
	struct node * prev;
	int info;
	struct node * next;
};

int main()
{
	int choice, data, item;
	struct node * start = NULL;
	
	while(1)
	{
		cout<<"1. Create List\n";
		cout<<"2. Display\n";
		cout<<"10. Quit\n";
		
		cout<<"Enter your choice : ";
		cin>>choice;
	
	
	switch(choice)
	{
		case 1:
		break;
		
		case 2: 
		break;
		
		case 10:
		exit(1);//Whit
		
		default :
			cout<<"Wrong choice\n\n";
		
	}
	
	} // End of while loop
}
