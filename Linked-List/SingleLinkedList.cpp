
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

// Insertion in Singly Linked List

struct node * AddAtBeg(struct node *start, int data);
struct node * AddAtEnd(struct node *start, int data);
struct node * AddAfter(struct node *start, int data, int item);
struct node * AddBefore(struct node * start, int data, int item);
struct node * AddAtPos(struct node * start, int data, int pos);

struct node * DeleteNode(struct node * start, int data);
struct node * ReverseList(struct node * start);



int main()
{
	struct node * start = NULL;
	int choice, data, item, pos;
	
	while(1)
	{
		cout<<"1. Create Linked List\n";
		cout<<"2. Display List\n";
	    cout<<"3. Count nodes of List\n";
		cout<<"4. Search\n";
		cout<<"5. Add to empty list / Add at beginning\n";
		cout<<"6. Add at end\n";
		cout<<"7. Add after node\n";
		cout<<"8. Add before node\n";
		cout<<"9. Add at pos\n";
		cout<<"10. Delete\n";
		cout<<"11. Reverse\n";
		cout<<"12. Quit\n\n";
		
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
			cout<<"Enter the element to be inserted : ";
			cin>>data;
			start = AddAtBeg(start, data);
			break;
		case 6:
			cout<<"Enter the element to be inserted : ";
			cin>>data;
			start = AddAtEnd(start, data);
			break;
		case 7 :
			cout<<"Enter the element to be inserted : ";
			cin>>data;
			cout<<"Enter the element after which to insert : ";
			cin>>item;
			start = AddAfter(start, data, item);
			break;
		case 8 :
			cout<<"Enter the element to be inserted : ";
			cin>>data;
			cout<<"Enter the element before which to insert : ";
			cin>>item;
			start = AddBefore(start, data, item);
			break;
			
		case 9:
			cout<<"Enter the element to be inserted : ";
			cin>>data;
			cout<<"Enter the position at which to insert : ";
			cin>>pos;
			start = AddAtPos(start, data, pos);
			break;
		case 10: 
			cout<<"Enter the element to be deleted : ";
			cin>>data;
			start = DeleteNode(start, data);
			break;
		
		case 11:
			start = ReverseList(start);
			break;
		case 12:
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


struct node * AddAtBeg(struct node *start, int data)
{
	struct node * temp;
	if(start == NULL)
	{
		temp = new node;
		temp->data = data;
		temp->link = NULL;
		start = temp;
		return start;
	}
	
	temp = new node;
	temp->data = data;
	temp->link = start;
	start = temp;
	return start;
	
}

struct node * AddAtEnd(struct node * start, int data)
{
	struct node * temp ;
	temp = start;
	
	if(start == NULL)
	{
		temp = new node;
		temp->data = data;
		temp->link = NULL;
		start = temp;
		return start;
	}
	
	while(temp->link != NULL)
	{
		temp = temp->link;
			
	}
	
	temp->link = new node;
	temp->link->data = data;
	temp->link->link = NULL;
	return start;
	
	
}

struct node * AddAfter(struct node * start, int data, int item)
{
	struct node * temp;
	temp = start;
	
	
	// This is doing add before
	//while( ( temp->link != NULL ) && (temp->link->data != item) )
	//{
		//temp = temp->link;
	//}
	
	// Simply search the node which has value == item
	struct node * p;
	while(temp != NULL)
	{
		if(temp->data == item)
		{
				p = new node;
				p->data = data;
				
				p->link = temp->link;
				temp->link = p;
				// break;
				return start;
		}
		temp = temp->link;
	}
	//p = new node;
	//p->data = data;
	//p->link = temp->link;
	//temp->link = p;
	cout<<item<<" is not present in the list\n";
	return start;
}
struct node * AddBefore(struct node * start, int data, int item)
{
	struct node * temp, * p;
	temp = p = start;
	
	if(start == NULL)
	{
		cout<<"List is empty\n";
		return start;
	}
	else if(start->data == item)
	{
		temp = new node;
		temp->data = data;
		temp->link = start;
		start = temp;
		return start;
	}
	else{
		// doubt on why p->link is used 
		while(p->link != NULL)// p!= NULL is not used because we are checking for one node ahead
		{
			if(p->link->data == item)
			{
				temp = new node;
				temp->data = data;
				temp->link = p->link;
				p->link = temp;
				return start;
			}
			p = p->link; 
		}
	}
	cout<<item<<" is not present in the list\n";
	return start;
}


struct node * AddAtPos(struct node * start, int data, int pos)
{
	if(start == NULL)
	{
		cout<<"List is empty\n";
		return start;
	}
	
	struct node * temp, *p;
	
	p = start;
	
	for(int i = 1; i<=pos-1 && p!= NULL; i++)
	{
		p = p->link;
	}
	
	if(p != NULL)
	{
		temp = new node;
		temp->data = data;
		temp->link = p->link;
		p->link = temp;
	}
	else
	{
		cout<<"There are less than "<<pos<<" elements\n";
	}
	return start;
}


struct node * DeleteNode(struct node * start, int data)
{
	if(start == NULL)
	{
		cout<<"List is empty\n";
		return start;
	}
	struct node * temp, * p;
	
	// Deletion in beginning of list
	if(start->data == data)
	{
			temp = start;
			start = start->link;
			// free(temp); // it gave error 
			delete temp;
			return start;
	}
	
	p = start;
	
	while(p->link != NULL)
	{
		if(p->link->data == data)
		{
			temp = p->link;
			p->link = temp->link;
			delete temp;
			return start;
		}
		p = p->link;
	}
	
	cout<<"Element not found in the list\n";
	return start;
}

struct node * ReverseList(struct node * start)
{
	struct node * prev, * curr, * next;
	prev = NULL;
	curr = start;
	
	while(curr != NULL)
	{
		next = curr->link;
		curr->link = prev;
		prev = curr;
		curr = next;
	}
	start = prev;
	
	return start;
	
}
