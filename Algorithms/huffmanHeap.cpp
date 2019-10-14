#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Input
{
  public:
    int freq;
    char ch;
    Input(int f, char c)
    {
      freq=f;
      ch=c;
    }
};

class Node
{
  public:
    int value;
    char cha;
    Node* left;
    Node* right;
    Node(int v, int c)
    {
      value=v;
      cha=c;
      left=right=NULL;
    }
};

class Code
{
  public:
    char ch;
    string str;
  Code(char c, string s)
  {
    ch=c;
    str=s;
  }
};

vector<Code*>codes;

void generateCodes(Node* root, string str)
{
  if(root==NULL)
  return;
  if(root->cha!='#')
  {
    codes.push_back(new Code(root->cha,str));
    
  }
  generateCodes(root->left,str+"0");
  generateCodes(root->right,str+"1");
}

vector<Node*> minHeap;

Node* top()
{
  Node* minNode=minHeap[0];
  int min=minHeap[0]->value;
  for(int i=1;i<minHeap.size();i++)
  {
    if(minHeap[i]->value<min)
    {
		min=minHeap[i]->value;
	    minNode=minHeap[i];
    }
  }
  return minNode;
}

void pop()
{
	Node* minNode=minHeap[0]; int min=0;
	for(int i=1;i<minHeap.size();i++)
	{
		if(minNode->value>minHeap[i]->value)
		{
			min=i;
			minNode=minHeap[i];
		}
	}
    minHeap.erase(minHeap.begin()+min);
}

void huffmanCoding(vector<Input*>inp, int n)
{
  int i;
  for(i=0; i<n; i++)
  {
    minHeap.push_back(new Node(inp[i]->freq, inp[i]->ch));
  }
  Node* l; Node* r; Node* newNode;
  while(minHeap.size()!=1)
  {
    l=top();
    pop();
    r=top();
    pop();
    newNode=new Node(l->value+r->value,'#');
    newNode->left=l;
    newNode->right=r;
    minHeap.push_back(newNode);
  }
  generateCodes(top(), "");
}

void decode(string s)
{
	string decode=""; 
	Node* currentNode=top();
	for (int i=0;i<s.size();i++) 
    { 
        if (s[i] == '0') 
           currentNode = currentNode->left; 
        else
           currentNode = currentNode->right; 
		    
        if (currentNode->left==NULL and currentNode->right==NULL) 
        { 
            decode += currentNode->cha; 
            currentNode = top(); 
        } 
    }
	cout<<"Decoded string "<<decode; 
}

int main()
{
  int n,i,f;
  char c;
  vector<Input*>inp;
  cout<<"Enter the number of characters"<<endl;
  cin>>n;
  cout<<"Enter freq and char for each"<<endl;
  for(i=0;i<n;i++)
  {
    cin>>c; cin>>f; 
    inp.push_back(new Input(f,c));
  }
  huffmanCoding(inp, n);
  cout<<"Codes with their corresponding characters"<<endl;
  for(i=0;i<n;i++)
  {
    cout<<codes[i]->ch<<" "<<codes[i]->str<<endl;
  }
  cout<<"Enter string to be encoded"<<endl;
  string s;
  cin>>s;
  string encoded="";
  for(i=0;i<s.length();i++)
  {
  	for(int j=0;j<n;j++)
  	{
  		if(s[i]==codes[j]->ch)
  		{
  			encoded+=codes[j]->str;
  			break;
		}
	}
  }
  cout<<"Encoded string "<<encoded<<endl;
  cout<<"Enter string to be decoded "<<endl;
  cin>>s;
  decode(s);
}
