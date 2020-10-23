
// Program of single linked list

#include<iostream>
using namespace std;

// Self referential structure
struct node{
		int data;
		struct node * link;
};


struct node * CreateList(struct node * start);
void Display(struct node * start);
// void Count(struct node * start);

int main()
{
	struct node * start = NULL;
	int choice;
	
	while(1)
	{
		cout<<"1. Create Linked List\n";
		cout<<"2. Display List\n";
		// cout<<"3. Count nodes of List\n";
		cout<<"4. Quit\n";
		
		cout<<"Enter your choice : ";
		cin>>choice;
		
		switch(choice)
		{
		case 1:
			start = CreateList(start);
			break;
		case 2:
			Display(start);
			break;
		// case 3:
		//	Count(start);
		//	break;
		case 4:
			exit(1);
		default :
			cout<<"Wrong choice\n";
		}
		
	}
	
	return 0;
}
struct node * CreateList(struct node * start)
{
	int n, info;
	cout<<"Enter number of nodes you want in the list\n";
	cin>>n;
	struct node * temp = NULL;
	
	for(int i = 1; i<=n; i++)
	{
		cin>>info;
		if(i == 1)
		{
			start = new node;
			start->data = info;
			start->link = NULL;
			temp = start;
		}
		else
		{
			temp->link = new node;
			temp = temp->link;
			temp->data = info;
			temp->link = NULL;
		}
	}
	return start;
}

void Display(struct node * start)
{
		if(start == NULL)
		{
			cout<<"List is empty\n";
			return;
		}
		
		struct node * temp;
		temp = start;
		cout<<"List is :\n";
		while(temp != NULL)
		{
			cout<<temp->data<<" ";
			temp = temp->link;
		}
		cout<<"\n\n";
		
}



