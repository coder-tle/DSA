// C++ Program for implementation of 
// Doubly Linked List with its operation

#include<bits/stdc++.h>
using namespace std;

struct node{
	struct node * prev;
	int info;
	struct node * next;
};

// Create Doubly Linked List
struct node * CreateList(struct node * start);

// Display 
void Display(struct node * start);


// Insertion function 
struct node * AddToEmptyList(struct node * start, int data);
struct node * AddAtBeginning(struct node * start, int data);
struct node * AddAtEnd(struct node * start, int data);

// Delete function
struct node * DeleteNode(struct node * start, int data);


int main()
{
	int choice, data, item;
	struct node * start = NULL;
	
	while(1)
	{
		cout<<"1. Create List\n";
		cout<<"2. Display\n";
		cout<<"3. Add to empty list\n";
		cout<<"4. Add at beginning\n";
		cout<<"5. Add at end\n";
		
		cout<<"8. Delete\n";
		cout<<"10. Quit\n";
		
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
			cout<<"Enter the element to be inserted : ";
			cin>>data;
			start = AddToEmptyList(start, data);
			break;
		case 4:
			cout<<"Enter the element to be inserted : ";
			cin>>data;
			start = AddAtBeginning(start, data);
			break;
		case 5:
			cout<<"Enter the element to be inserted : ";
			cin>>data;
			start = AddAtEnd(start, data);
			break;
			
		case 8:
			cout<<"Enter the element to be deleted : ";
			cin>>data;
			start = DeleteNode(start, data);
			break;
		case 10:
		exit(1);//Whit
		
		default :
			cout<<"Wrong choice\n\n";
		
	}
	
	} // End of while loop
}

void Display(struct node * start)
{
	struct node * temp = start;
	
	if(temp == NULL)
	{
		cout<<"List is empty\n";
		return ;
	}
	
	while(temp != NULL)
	{
		cout<<temp->info<<" ";
		temp = temp->next;
	}
	cout<<endl;
	return;
	
}



struct node * AddToEmptyList(struct node * start, int data)
{
	struct node * temp = new node;
	temp->info = data;
	temp->next = temp->prev = NULL;
	start = temp;
	return start;
}


struct node * AddAtBeginning(struct node * start, int data)
{
	struct node * temp = new node;
	temp->info = data;
	
	temp->next = start;
	temp->prev = NULL;
	start = temp;
	
	return start;
	
	
}

struct node * AddAtEnd(struct node * start, int data)
{
	struct node * temp, *p;
	temp = new node;
	temp->info = data;
	
	p = start;
	
	while(p->next != NULL)
	{
		p = p->next;
	}
	
	p->next = temp;
	temp->prev = p;
	temp->next = NULL;
	
	return start;
	
	
}
struct node * CreateList(struct node * start)
{
	struct node * temp;
	start = NULL;
	int n, data;
	
	cout<<"Enter number of nodes of the list : ";
	cin>>n;

	cout<<"Enter the value of nodes : ";
	cin>>data;
	
	start  = AddToEmptyList(start, data);
	
	for(int i = 2; i<=n; i++)
	{
		cin>>data;
		
		start = AddAtEnd(start, data);
	}
	return start;
}


struct node * DeleteNode(struct node * start, int data)
{
	struct node * temp, * p ;
	p = temp = start;
	
	if(start == NULL)
	{
		cout<<"List is empty\n";
		return start;
	}
	
	// One node
	if(start->next == NULL)
	{
		temp = start;
		start = start->next;
		delete temp;
		return start;
	}
	
	// delte first node
	if(start->info == data)
	{
		temp = start;
		start = start->next;
		start->prev = NULL;
		return start;
	}
	
	// delete  in-between
	
	while( temp != NULL)
	{
		if( temp->info == data )
		{
			// not end of list
			if(temp->next != NULL)
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
			}
			// node at end of the list
			else if(temp->next == NULL)
			{
				temp->prev->next = NULL;
			}
			return start;
		}
		temp = temp->next;
		
	}
	cout<<"Node with value "<<data<<" does not exist in the list\n";
	return start;
	
}

