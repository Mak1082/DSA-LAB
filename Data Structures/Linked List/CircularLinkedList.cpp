#include<iostream>
using namespace std;

struct Node{
	int age;
	string name;
	struct Node* next;
};

void pushStart(int x,string n,struct Node *l)
{
struct Node *tmpcell;
tmpcell = new Node;
tmpcell->age = x;
tmpcell->name=n;
struct Node* p=l->next;
if(l->next!=NULL)
{
tmpcell->next=l->next;
l->next=tmpcell;
}
else{
tmpcell->next = l;
l->next = tmpcell;
}
}

void display(struct Node* l)
{
struct Node* p=l->next;
cout<<"Names are:\n";
do
{
cout<<p->name<<"\n";
p=p->next;
}while(p!=l);
cout<<"Ages are:\n";
p=p->next;
while(p!=l)
{
	cout<<p->age<<"\n";
	p=p->next;
}
}

void pushEnd(int x, string n, struct Node* l)
{
struct Node* tmpcell= new Node;
tmpcell->age=x; tmpcell->name=n;
struct Node* p=l->next;
if(l->next!=NULL)
{
	while(p->next!=l) p=p->next;
	tmpcell->next=l;
	p->next=tmpcell;
}
else{
l->next=tmpcell;
tmpcell->next=l;
}
}

int main()
{
struct Node* l= new Node;
l->next=NULL;
pushStart(10,"Mayank",l);
pushStart(11,"Swapnil",l);
pushStart(12,"Apratim",l);
pushStart(13,"Abhishek",l);
pushEnd(14,"Ameesh",l);
display(l);
}

