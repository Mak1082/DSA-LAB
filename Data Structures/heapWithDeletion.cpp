#include<iostream>
using namespace std;


int parentIndex(int index)
{
	return (index/2); 
}

int leftChild(int index)
{
	return (2*index);
}

int rightChild(int index)
{
	return (2*index+1);
}

int hasLeftChild(int index,int size)
{
	return (leftChild(index)<=size);
}

int hasRightChild(int index,int size)
{
	return (rightChild(index)<=size);
}

int hasParent(int index)
{
	return (parentIndex(index)>0);
}

void heapifyMin(int* minH,int size)
{
	int index=size;
	while(hasParent(index) && minH[parentIndex(index)]>minH[index])
	{
		swap(minH[parentIndex(index)],minH[index]);
		index=parentIndex(index);
	}
}

void heapifyMax(int* minH, int size)
{
	int index=size;
	while(hasParent(index)&&(minH[parentIndex(index)]<minH[index]))
	{
		swap(minH[parentIndex(index)],minH[index]);
		index=parentIndex(index);
	}
}

void insertMin(int* H, int pos, int item)
{
	H[pos]=item;
	heapifyMin(H,pos);
}

void insertMax(int* H,int pos, int item)
{
	H[pos]=item;
	heapifyMax(H,pos);
}

void display(int *minH,int pos)
{
	for(int i=1;i<=pos;i++)
	{
		cout<<minH[i]<<" ";
	}
}

void displayInOrder(int *H, int size)
{
    int i,j,index;
    for(i=size;i>1;i--)
    {
		swap(H[1],H[i]);    	
    	j=1,index=0;
    	do
    	{
    		index=2*j;
    		if(H[index]<H[index+1]&&index<(i-1))
    			index++;
    		if(H[j]<H[index] && index<i)
    			swap(H[j],H[index]);
    		j=index;
		}while(index<i);
	}
	for(i=1;i<=size;i++)
	{
		cout<<H[i]<<" ";
	}
}

void displayInOrderMin(int *H, int size)
{
    int i,j,index;
    for(i=size;i>1;i--)
    {
		swap(H[1],H[i]);    	
    	j=1,index=0;
    	do
    	{
    		index=2*j;
    		if(H[index]>H[index+1]&&index<(i-1))
    			index++;
    		if(H[j]>H[index] && index<i)
    			swap(H[j],H[index]);
    		j=index;
		}while(index<i);
	}
	for(i=1;i<=size;i++)
	{
		cout<<H[i]<<" ";
	}
}

void pop(int* minH, int size)
{
	swap(minH[1],minH[size]);
	int index=1;
	size--;
	while((hasLeftChild(index,size) && minH[index]>minH[leftChild(index)]) || (hasRightChild(index,size) && (minH[index]>minH[rightChild(index)])))
	{
		if(hasLeftChild(index,size) && minH[index]>minH[leftChild(index)])
		{
			swap(minH[index],minH[leftChild(index)]);
			index=leftChild(index);
		}
		else if(hasRightChild(index,size) &&(minH[index]>minH[rightChild(index)]))
		{
			swap(minH[index],minH[rightChild(index)]);
			index=rightChild(index);
		}
	}
	cout<<"After deleting root element"<<endl;
	for(int i=1;i<=size;i++)
	{
		cout<<minH[i]<<" ";
	}
}

int main()
{
	int *minHeap=new int[100];
	int *maxHeap=new int[100];
	int n,x;
	cout<<"Enter the number of elements\n";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	    cout<<"Enter element\n";
	    cin>>x;
	    insertMax(maxHeap,i,x);
	    insertMin(minHeap,i,x);
	}
	cout<<"Min Heap:\n";
	display(minHeap,n);
	cout<<"\nMax Heap:\n";
	display(maxHeap,n);
	cout<<"\nIn Sorted Order:\n";
	displayInOrder(maxHeap,n);
	cout<<"\nIn Sorted Order:\n";
	displayInOrderMin(minHeap,n);
	cout<<"X"<<maxHeap[1];
	pop(maxHeap,n);
}
