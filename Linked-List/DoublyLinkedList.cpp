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
struct node * AddAfter(struct node * start, int data, int item);
struct node * AddBefore(struct node * start, int data, int item);



// Delete function
struct node * DeleteNode(struct node * start, int data);

// Reverse function
struct node * ReverseList(struct node* start);


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
		cout<<"6. Add after\n";
		cout<<"7. Add before\n";
		cout<<"8. Delete\n";
		cout<<"9. Reverse\n";
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
		
		case 6:
			cout<<"Enter the element to be inserted : ";
			cin>>data;
			cout<<"Enter the element after which to insert : ";
			cin>>item;
			start = AddAfter(start,data, item);
			break;
			
		case 7:
			cout<<"Enter the element to be inserted : ";
			cin>>data;
			cout<<"Enter the element before which to insert : ";
			cin>>item;
			start = AddBefore(start, data, item);
			break;
			
		case 8:
			cout<<"Enter the element to be deleted : ";
			cin>>data;
			start = DeleteNode(start, data);
			break;
		
		case 9: 
			start = ReverseList(start);
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

struct node * ReverseList(struct node* start)
{
	if(start == NULL)
	return start;
	
	struct node * curr , * nextNode;
	curr = start;
	nextNode = curr->next;
	
	// condition needs to be checked
	while(nextNode->next != NULL)
	{
		nextNode = curr->next;
		curr->next = curr->prev;
		curr->prev = nextNode;
		curr = nextNode; 
	}
	
	curr->next = curr->prev;
	curr->prev = NULL;
	start = curr;
	
	return start;
	
	
}

struct node * AddAfter(struct node * start, int data, int item)
{
	struct node * p = start, *temp;
	
	while(p != NULL)
	{
		if(p->info == item)
		{
			temp = new node;
			temp->info = data;
			temp->prev = p;
			temp->next = p->next;
			if(p->next != NULL)
				p->next->prev = temp;
			p->next = temp;
			return start;
		}
		p = p->next;
		
	}
	
	cout<<item<<" is not present in the list\n";
	return start;
	
}

struct node * AddBefore(struct node * start, int data, int item)
{
	struct node * q = start, * temp;
	
	
	// Remember to consider base condition of empty list
	// and insertion before first node
	
	if(start == NULL)
	{
		cout<<"List is empty\n";
		return start;
	}
	
	if(start->info == item)
	{
		temp = new node;
		temp->info = data;
		
		temp->next = start;
		temp->prev = NULL;
		start->prev = temp;
		start = temp;
		return start;
	}
	
	while(q != NULL)
	{
		if(q->info == item)
		{
			temp = new node;
			temp->info = data;
			
			temp->prev = q->prev;
			temp->next = q;
			q->prev->next = temp;
			q->prev = temp;
			return start;
		}
		q = q->next;
	}
	
	cout<<item<<" is not present in the list\n";
	return start;
	
	
}
