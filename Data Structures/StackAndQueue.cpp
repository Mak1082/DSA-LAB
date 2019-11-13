#include<iostream>
using namespace std;

struct Node;
typedef struct Node *ptrtonode;
typedef ptrtonode List;
typedef ptrtonode Position;

struct Node
{
char e;
Position next;
};

void push(char x,List stack)
{
Position tmpcell;
tmpcell = new Node;
tmpcell->e = x;
tmpcell->next = stack->next;
stack->next = tmpcell;
}

Position pop(List stack)
{
	Position tmpCell=new Node;
	tmpCell=stack->next;
	if(stack->next->next!=NULL)
	stack->next=stack->next->next;
	else
	stack->next=NULL;
	return tmpCell;
}

void enqueue(char x,List queue)
{
	Position newNode=new Node;
	newNode->next=NULL; newNode->e=x;
	if(queue->next!=NULL)
	{
		Position currentNode = queue->next;
		while(currentNode->next)
		{
	    	currentNode=currentNode->next;
		}
		currentNode->next=newNode;
	}
else{
	queue->next=newNode;
}
}


void display(List queue)
{
cout<<"PostFix Expression: ";
Position p= queue->next;
while (p!= NULL)
{
cout<< p->e;
p= p->next;
}
cout<<"\n";
}

main()
{
int x,pos,i;
char ch;
Position tmp=new Node;
List stack; List queue;
stack=new Node;
queue=new Node;
queue->next=NULL;
stack->next =NULL;
Position p1=stack->next;
string s;
cout<<"Enter expresssion: ";
cin>>s;
for(i=0;i<s.length();i++)
{
ch=s[i];
x=(int)ch;
if(x>64 && x<91) enqueue(s[i],queue);
else if(ch=='*' || ch=='+' || ch=='-' || ch=='/')
{
	if(stack->next==NULL) push(s[i],stack);
	else
	{
		if(ch=='*' || ch=='/')
		{
			if((stack->next->e)=='+' || (stack->next->e)=='-')
			push(s[i],stack);
			else if((stack->next->e)=='*'||(stack->next->e)=='/')
			{
				tmp=pop(stack);
				enqueue(tmp->e, queue);
				push(s[i],stack);
			}
		}
		else if(ch=='+' || ch=='-')
		{
			if((stack->next->e)=='*' || (stack->next->e)=='/' || (stack->next->e)=='+'||(stack->next->e)=='-')
			{	
			tmp=pop(stack);
			push(ch,stack);
			enqueue(tmp->e, queue);
		}
		if(stack->next==NULL)
		{
			push(ch,stack);
		}
		}
	}
}
}
while(stack->next!=NULL)
{
tmp=pop(stack);
enqueue(tmp->e,queue);
}
display(queue);
}
