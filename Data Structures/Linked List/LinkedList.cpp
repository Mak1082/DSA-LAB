#include<iostream>
using namespace std;

struct Node
{
int e;
struct Node *next;
};

void insertAtBeginning(int x,struct Node *l)
{
struct Node *tmpcell;
tmpcell = new Node;
if (tmpcell == NULL)
cout<<"Memory Out of space\n";
else
{
tmpcell->e = x;
tmpcell->next = l->next;
l->next = tmpcell;
}
}

void display(struct Node *l)
{
cout<<"the List element are :: ";
struct Node *p= l->next;
while (p!= NULL)
{
cout<< p->e << "->";
p= p->next;
}
}

main()
{
int x,pos,ch,i;
struct Node *l,*p;
l=new Node;
l->next =NULL;
p = l;
cout<<"Linked List Implementation\n\n";
do
{
cout<<"\n1.Insert at Beginning, 2.Insert at End, 3.Display, 4.Exit \n ";
cin>>ch;
switch(ch)
{
case 1:
p=l;
cout<<"Enter the element to be inserted : ";
cin >> x;
insertAtBeginning(x,l);
break;
/*case 2:
cout<<"Enter value to be inserted: ";
cin>>x;
insertAtEnd(x,l);
break;
*/

case 3:
display(l);
}
}
while(ch<4);

}
