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
	Position tmpcell;
	tmpcell = new Node;
	tmpcell->e = x;
	tmpcell->next = l->next;
	l->next = tmpcell;
}

void display(List l)
{
cout<<"the List element are :: ";
Position p= l->next;
while (p!= NULL)
{
cout<< p->e << "->";
p= p->next;
}
cout<<"\n";
}

void findEvenOdd(List l)
{
	List even,odd;
	even=new Node;
	odd=new Node;
	even->next=NULL;
	odd->next=NULL;
	Position tmpCell=l->next;
	while(tmpCell!=NULL)
	{
		if((tmpCell->e)%2==0)
		{
			insertAtBeginning(tmpCell->e,even);
		}
		else
		{
			insertAtBeginning(tmpCell->e,odd);
		}
		tmpCell=tmpCell->next;
	}
	cout<<"Even elements\n";
	display(even);
	cout<<"Odd elements\n";
	display(odd);
}

int main()
{
	int i,x;
	List l;
	l=new Node;
	l->next =NULL;
	List p = l;
	cout<<"Enter 10 values\n";
	for(i=0;i<10;i++)
	{
		cin>>x;
		insertAtBeginning(x,l);
	}
	cout<<"Your list elements are:\n";
	display(l);
	findEvenOdd(l);
}
