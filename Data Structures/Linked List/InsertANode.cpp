#include<iostream>
using namespace std;

struct Node;
typedef struct Node *ptrtonode; 
typedef ptrtonode List;
typedef ptrtonode Position;

struct Node
{
int e;
Position next;
};

void insertAtBeginning(int x,List l)
{
Position tmpcell=new Node;
tmpcell->e = x;
tmpcell->next = l->next;
l->next = tmpcell;
}

void display(List l)
{
cout<<"The List element are :: ";
Position p= l->next;
while (p!= NULL)
{
cout<< p->e << "->";
p= p->next;
}
cout<<"\n";
}

void insertAtEnd(int x,List l)
{
Position newNode=new Node;
Position currentNode = l->next;
while(currentNode->next!=NULL){
    currentNode=currentNode->next;
}
newNode->next=NULL; newNode->e=x;
currentNode->next=newNode;
}

void insertAfterX(List l, int x, int y)
{
	Position tmpCell=new Node;
	Position currentNode=new Node;
	currentNode=l->next;
	while(currentNode->e!=x)
	{
		currentNode=currentNode->next;
	}
	tmpCell->e=y; tmpCell->next=currentNode->next;
	currentNode->next=tmpCell;
}

void insertBeforeIndex(List l, int index, int y)
{
	Position tmpCell=new Node;
	Position currentNode=new Node;
	currentNode=l->next;
	int i=0;
	while(i!=(index-1))
	{
		currentNode=currentNode->next;
		i++;
	}
	tmpCell->e=y; tmpCell->next=currentNode->next;
	currentNode->next=tmpCell;
}

void deleteAtIndex(List l, int index)
{
	if(l->next!=NULL)
	{
	
		Position currentNode=new Node;
		Position tmpCell=new Node;
		currentNode=l->next;
		int i=0;
		if(index!=0)
		{
			while(i!=(index-1))
			{
				currentNode=currentNode->next;
				i++;
			}
			tmpCell=currentNode->next;
			currentNode->next=currentNode->next->next;
			free(tmpCell);
		}
		else
		{
			tmpCell=l->next;
			l->next=tmpCell->next;
		}
	}
	else
	{
		cout<<"List is empty";
	}
}

void findAndReplace(List l, int x, int y)
{
	Position tmpCell=new Node;
	Position currentNode=new Node;
	currentNode=l->next;
	while(currentNode->next->e!=x)
	{
		currentNode=currentNode->next;
	}
	tmpCell->e=y; tmpCell->next=currentNode->next->next;
	currentNode->next=tmpCell;
}

void deleteMultipleOccurences(List l, int x)
{
	Position currentNode=new Node;
	Position tmpCell=new Node;
	currentNode=l->next; int c=0;
	if(currentNode->e==x)c++;
	while(currentNode->next!=NULL)
	{
		if(currentNode->next->e==x)
			c++;
		if(c>1 && currentNode->next->e==x)
		{
			tmpCell=currentNode->next;
			if(currentNode->next->next!=NULL)
			currentNode->next=currentNode->next->next;
			else
			currentNode->next=NULL;
			free(tmpCell);
		}
		currentNode=currentNode->next;
	}
}

void countNumberOfOccurences(List l, int x)
{
	int c=0;
	Position p=l->next;
	while(p!=NULL)
	{
		if(p->e==x)
		c++;
		p=p->next;
	}
	cout<<"Number of occurences: "<<c<<endl;
}

void reverse(List l)
{
	Position p=l->next;
	Position second=p->next;
	while(second!=NULL)
	{
		Position temp=second->next;
		second->next=p;
		p=second;
		second=temp;
	}
	l->next->next=NULL;
	l->next=p;
}

int main()
{
int x,pos,ch,i;
List l;
l=new Node;
l->next =NULL;
List p = l;
cout<<"Linked List Implementation\n\n";
do
{
cout<<"\n1.Insert at Beginning, 2.Insert at End, 3.Display, 4.Insert After a Node, 5.Insert Before Index, 6.Delete Node, 7.Find and Replace,8.Delete Multiple occurences of a value,9.Count Multiple occurences, 10.Exit \n ";
cin>>ch;
switch(ch)
{
case 1:
	p=l;
	cout<<"Enter the element to be inserted : ";
	cin >> x;
	insertAtBeginning(x,l);
	break;

case 2:
	cout<<"Enter value to be inserted: ";
	cin>>x;
	insertAtEnd(x,l);
	break;

case 3:
	display(l);
	break;

case 4:
	cout<<"Enter value to be inserted ";
	cin>>x;
	cout<<"\nEnter value after which node is to be inserted ";
	cin>>i;
	insertAfterX(l,i,x);
	break;
	
case 5:
	cout<<"Enter value to be inserted ";
	cin>>x;
	cout<<"\nEnter index ";
	cin>>i;
	insertBeforeIndex(l,i,x);
	break;
	
case 6:
	cout<<"Enter index of node to be deleted ";
	cin>>i;
	deleteAtIndex(l,i);
	break;
	
case 7:
	cout<<"Enter value of node to be replaced and the value to be inserted ";
	int y;
	cin>>y;
	cin>>x;
	findAndReplace(l,y,x);
	break;

case 8:
	cout<<"Enter value ";
	int m;
	cin>>m;
	deleteMultipleOccurences(l,m);
	break;
case 9:
	cout<<"Enter value ";
	cin>>x;
	countNumberOfOccurences(l,x);
	break;
}
}
while(ch<10);
reverse(l); 
cout<<"Reversed List\n";
display(l);
}
