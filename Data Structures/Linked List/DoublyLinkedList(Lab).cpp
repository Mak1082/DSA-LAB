#include<iostream>
using namespace std;

struct Node;
typedef struct Node *ptrtonode;
typedef ptrtonode List;
typedef ptrtonode Position;

struct Node
{
int e;
struct Node* next;
struct Node* prev;
};

void insertAtBeginning(int x,struct Node* l)
{
struct Node* tmpCell;
struct Node* p;
tmpCell = new Node;
tmpCell->e = x;
tmpCell->next=l->next;
tmpCell->prev=l;
if(l->next!=NULL)
{
	l->next->prev=tmpCell;
}
l->next = tmpCell;
}

void insertAtEnd(int x,struct Node* l)
{
struct Node* newNode=new Node;
struct Node* currentNode = l->next;
while(currentNode->next!=NULL){
    currentNode=currentNode->next;
}
newNode->next=NULL; newNode->e=x; newNode->prev=currentNode;
currentNode->next=newNode;
}

void display(struct Node* l)
{
cout<<"the List element are :: ";
struct Node* p= l->next;
while (p!= NULL)
{
cout<< p->e << "->";
p= p->next;
}
cout<<"\n";
}

bool exists(struct Node* l, int x)
{
struct Node* p;
p=l->next;
while(p!=NULL)
{
if(p->e==x) return true;
p=p->next;
}
return false;
}

void deleteX(struct Node* l, int x)
{
	struct Node* p=l->next;
	while(p->e!=x && p!=NULL)
	{
		p=p->next;
	}
	if(p->next!=NULL){
	p->prev->next=p->next;
	p->next->prev=p->prev;
	}
	else p->prev->next=NULL;
}

void displayReverse(struct Node* l)
{
	struct Node* p=l->next;
	while(p->next!=NULL)
	{
	p=p->next;
	}
	while(p->prev!=NULL)
	{
	cout<<p->e<<"->";
	p=p->prev;
	}
	cout<<"\n";
}

void insertSecondLast(struct Node* l, int x)
{
	struct Node* p=l->next;
	while(p->next->next!=NULL)
	{
	p=p->next;
	}
	struct Node* tmpCell;
	tmpCell=new Node;
	tmpCell->e=x;
	tmpCell->next=p->next;
	tmpCell->prev=p;
	p->next->prev=tmpCell;
	p->next=tmpCell;
}

int main()
{
int x,pos,ch,i;
struct Node* l;
l=new Node;
l->next =NULL;
struct Node* p = l;
cout<<"Doubly Linked List Implementation\n\n";
do
{
cout<<"\n1.Insert at Beginning, 2.Insert at End, 3.Delete 4.Display, 5.Display Reverse, 6.Exit \n ";
cin>>ch;
switch(ch)
{
case 1:
	p=l;
	cout<<"Enter the element to be inserted: ";
	cin >> x;
	insertAtBeginning(x,l);
	break;
case 2:
	p=l;
	cout<<"Enter element to be inserted: ";
	cin>>x;
	insertAtEnd(x,l);
	break;
case 3:
	cout<<"Enter value to be deleted: ";
	cin>>x;
	deleteX(l,x);
	break;
case 4:
	display(l);
	break;
case 5:
	displayReverse(l);
	break;
}
}
while(ch<6);
cout<<"Enter value: ";
cin>>x;
if(exists(l,x)==true)
{
insertSecondLast(l,x);
deleteX(l,x);
display(l);
}
else cout<<"\nValue does not exist\n";
}

