#include<stdio.h>  

struct Node 
{ 
    int key; 
    struct Node *left, *right, *parent; 
}; 
  
// A utility function to create a new BST Node 
struct Node *newNode(int item) 
{ 
    struct Node *temp =  malloc(sizeof(struct Node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    temp->parent = NULL; 
    return temp; 
} 
  
// A utility function to do inorder traversal of BST 
void inorder(struct Node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("Node : %d, ", root->key); 
        if (root->parent == NULL) 
          printf("Parent : NULL \n"); 
        else
          printf("Parent : %d \n", root->parent->key); 
        inorder(root->right); 
    } 
} 
  
/* A utility function to insert a new Node with 
   given key in BST */
struct Node* insert(struct Node* node, int key) 
{ 
    /* If the tree is empty, return a new Node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
    {
        struct Node *lchild = insert(node->left, key); 
        node->left  = lchild; 
  
        // Set parent of root of left subtree 
        lchild->parent = node; 
    }
    else if (key > node->key) 
    { 
        struct Node *rchild = insert(node->right, key); 
        node->right  = rchild; 
  
        // Set parent of root of right subtree 
        rchild->parent = node; 
    } 
  
    /* return the (unchanged) Node pointer */
    return node; 
} 

struct Node* maximum(struct Node* x) 
{
	while(x->right!=NULL) x=x->right;
	return x;
}

struct Node* predecessor(struct Node* x)
{
	if(x->left!=NULL) return maximum(x->left);
	else
	{
		struct Node* y=x->parent;
		while(y!=NULL && x==y->left)
		{
			x=y;
			y=y->parent;
		}
		return y;
	}
}

struct Node* minimum(struct Node* x)
{
	while(x->left!=NULL) x=x->left;
	return x;
}

struct Node* successor(struct Node* x)
{
	struct Node* y;
	if(x->right!=NULL)
	return minimum(x->right);
	else
	{
		struct Node* y=x->parent;
		while(y!=NULL && x==y->right)
		{
			x=y;
			y=y->parent;
		}
		return y;
	}
}

void treeSearch(struct Node* root, int x)
{
	struct Node* p=root;
	while(p!=NULL && p->key!=x)
	{
		if(x>p->key) p=p->right;
		else if(x<p->key) p=p->left;
	}
	if(p!=NULL) printf("Found");
	else printf("\nNot Found");	
	//return p;
}
  
// Driver Program to test above functions 
void main() 
{ 
    /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 */
    struct Node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
    // print iNoder traversal of the BST 
    inorder(root); 
    struct Node* tmp=malloc(sizeof(struct Node));
    root=root->left;
    printf("%d ",root->key);
    tmp=successor(root);
    printf("Successor %d ",tmp->key);
    tmp=predecessor(root);
    printf("Predecessor %d ",tmp->key);
} 
