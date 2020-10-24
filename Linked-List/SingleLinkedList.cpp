
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
void Count(struct node * start);
void Search(struct node * start, int data);


int main()
{
	struct node * start = NULL;
	int choice, data;
	
	while(1)
	{
		cout<<"1. Create Linked List\n";
		cout<<"2. Display List\n";
	    cout<<"3. Count nodes of List\n";
		cout<<"4. Search\n";
		cout<<"5. Quit\n";
		
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
	    case 3:
			Count(start);
			break;
		case 4:
			cout<<"Enter the element to be searched : ";
			cin>>data;
			Search(start, data);
			break;
		case 5:
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

void Count(struct node * start)
{
	struct node * temp = start;
	int counter = 0;
	
	while(temp != NULL)
	{
		temp = temp->link;
		counter++;
	}
	cout<<"Number of Nodes in Linked List : "<<counter<<endl;
	
}

void Search(struct node * start, int data)
{
	struct node * temp = start;
	bool found = false;
	while(temp != NULL)
	{
		if(temp->data == data)
		{
			found = true;
			break;
		}
		temp = temp->link;
	}
	
	if(found == true)
	cout<<"Node with info : "<<data<<" exists\n";
	else
	cout<<"Node with info : "<<data<<" does not exists\n";
	
	
}





