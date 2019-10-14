#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;


class Code
{
	public:
		int freq;
		char ch;
		Code(int f, char c)
		{
			freq=f;
			ch=c;
		}
};

struct Node
{
	char cha;
	int value;
	Node* left;
	Node* right;
	Node(char c, int val)
	{
		cha=c;
		value=val;
		left=right=NULL;
	}
};

struct compare 
{ 
    bool operator()(Node* l, Node* r) 
    { 
        return (l->value > r->value); 
    } 
};

vector<Code*>freque;
map<char, string>codes;

priority_queue<Node*, vector<Node*>, compare> minHeap;


void generateCodes(struct Node* root, string str)
{
	if(root==NULL)
		return;
    if (root->cha != '$') 
        codes[root->cha]=str; 
    generateCodes(root->left, str + "0"); 
    generateCodes(root->right, str + "1");
}

void printCodes(struct Node* root, string str)
{
	if (root!=NULL) 
        return; 
    if (root->cha != '$') 
        cout << root->cha << ": " << str << "\n"; 
    printCodes(root->left, str + "0"); 
    printCodes(root->right, str + "1");
}

void huffmanCoding(vector<Code*>arr2, int n)
{
	struct Node *left, *right, *top;
	int i;
	for(i=0;i<n;i++)
	{
		minHeap.push(new Node(arr2[i]->ch,arr2[i]->freq));
	}
	while(minHeap.size()!=1)
	{
		left=minHeap.top();
		minHeap.pop();
		right=minHeap.top();
		minHeap.pop();
		top=new Node('$',left->value+right->value);
		top->left=left;
		top->right=right;
		minHeap.push(top);
	}
	generateCodes(top, "");
}

int main()
{
	int n,i,f; char c;
	cout<<"Enter no. of characters"<<endl;
	cin>>n;
	cout<<"Enter character and its frequency"<<endl;
	for(i=0; i<n; i++)
	{
		cin>>c; cin>>f;
		Code* temp=new Code(f,c);
		freque.push_back(temp);
	}
	huffmanCoding(freque, n);
	for(auto v=codes.begin(); v!=codes.end(); v++)
	{
		cout<<v->first<<" "<<v->second<<endl;
	}
}
