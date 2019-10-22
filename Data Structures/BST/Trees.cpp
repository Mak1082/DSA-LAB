#include<iostream>
using namespace std;

struct Node
{
       int data;
       struct Node* right;
       struct Node* left;
};

struct Node* newNode(int x)
{
       struct Node* temp=new Node;
       temp->data=x;
       temp->right=NULL; temp->left=NULL;
       return temp;
}

struct Node* insert(struct Node* root, int x)
{
       if(root==NULL) return newNode(x);
       else{
            if(x<(root->data)) root->left=insert(root->left,x);
            else if(x>(root->data)) root->right=insert(root->right,x);
            }
       return root;
}

void inOrder(struct Node* root)
{
     if(root!=NULL)
     {
            inOrder(root->left);
            cout<<root->data<<" ";
            inOrder(root->right);
     }
}

void postOrder(struct Node* root)
{
    if(root!=NULL)
     {
            inOrder(root->left);
            inOrder(root->right);
            cout<<root->data<<" ";
     }
}

void preOrder(struct Node* root)
{
    if(root!=NULL)
     {
            cout<<root->data<<" ";
            inOrder(root->left);
            inOrder(root->right);
     }
}
struct Node * leftMost(struct Node* node) 
{  
    while (node->left != NULL) 
        node = node->left; 
    return node; 
}

struct Node* deleteNode(struct Node* root, int x)
{
	if(root==NULL) return root;
	if(root->data>x) root->left=deleteNode(root->left,x);
	else if(root->data<x) root->right=deleteNode(root->right,x);
	else{
		//No child
		if(root->left==NULL && root->right==NULL)
		{
			free(root);
			return NULL;
		}
		
		// 1 child
		else if(root->left==NULL)
		{
			struct Node* tmp=root->right;
			free(root);
			return tmp;
		}
		else if(root->right==NULL)
		{
			struct Node* tmp=root->left;
			free(root);
			return tmp;
		}
		
		//2 child
		struct Node* tmp=leftMost(root->right);
		root->data=tmp->data;
		root->right=deleteNode(root->right,tmp->data);
	}	
	return root;
}



int main()
{
	int ch,x; int i=1;
    struct Node* root=NULL;
    cout<<"Binary Tree Implementation:\n ";
    do
    {
    	cout<<"\n1.Insert, 2.PreOrder, 3.InOrder, 4.PostOrder, 5.Delete, 6.Exit\n";
    	cin>>ch;
    	switch(ch)
    	{
    		case 1:
				cout<<"\nEnter value: \n";
				cin>>x;
				if(i==1){
				root=insert(root,x); i++;}
				else insert(root,x); 
				break;
			case 2:
				cout<<"\nPreOrder Traversal\n";
				preOrder(root);
				break;
			case 3:
				cout<<"\nInOrder Traversal\n";
				inOrder(root);
				break;
			case 4:
				cout<<"\nPostOrder Traversal\n";
				postOrder(root);
				break;
			case 5:
				cout<<"\nEnter value to be deleted\n";
				cin>>x;
				deleteNode(root,x);
				break;
		}
	}while(ch<6);
}
