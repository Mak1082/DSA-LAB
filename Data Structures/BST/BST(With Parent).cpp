#include<iostream>
using namespace std;

struct Node
{
       int data;
       struct Node *right,*left,*parent;
};

struct Node* newNode(int x)
{
       struct Node* temp=new Node;
       temp->data=x;
       temp->right=NULL; temp->left=NULL;
       temp->parent=NULL;
       return temp;
}

struct Node* insert(struct Node* root, int x)
{
	if(root==NULL) return newNode(x);
	if(x>root->data)
	{
		struct Node* rchild=insert(root->right,x);
		root->right=rchild;
		rchild->parent=root;
	}
	else if(x<root->data)
	{
		struct Node* lchild=insert(root->left,x);
		root->left=lchild;
		lchild->parent=root;
	}
	return root; 
}

void inOrder(struct Node* root)
{
	if(root!=NULL)
	{
		inOrder(root->left);
		cout<<root->data<<" ";
		if(root->parent!=NULL) cout<<"Parent: "<<root->parent->data<<"\n ";
		else cout<<"Parent: NULL\n";
		inOrder(root->right);		
	}
}

int main()
{
	struct Node* root=new Node;
	root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80);
    inOrder(root);
}
