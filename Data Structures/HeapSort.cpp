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

void heapify(int* minH,int size)
{
	int index=size;
	while(hasParent(index) && minH[parentIndex(index)]>minH[index])
	{
		swap(minH[parentIndex(index)],minH[index]);
		index=parentIndex(index);
	}
}

void insert(int* minH, int pos, int item)
{
	minH[pos]=item;
	heapify(minH,pos);
}

void display(int *minH,int pos)
{
	for(int i=1;i<=pos;i++)
	{
		cout<<minH[i]<<" ";
	}
}

void displayInOrder(int *minH, int size)
{
    int i;
    while(size!=0)
    {
        cout<<minH[1]<<" ";
        for(i=1;i<=size;i++)
        if((hasRightChild(i,size)&&hasLeftChild(i,size))&&(minH[rightChild(i)]<minH[leftChild(i)]))
        swap(minH[rightChild(i)],minH[leftChild(i)]);
        for(i=1;i<size;i++)
        {
            minH[i]=minH[i+1];
        }
        //cout<<"Min Heap\n";
        size--;
        //display(minH,size);
        heapify(minH,size);
    }
}

int main()
{
	int *minHeap=new int[100];
	int n,x;
	cout<<"Enter the number of elements\n";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	    cout<<"Enter element\n";
	    cin>>x;
	    insert(minHeap,i,x);
	}
	cout<<"Min Heap:\n";
	display(minHeap,n);
	cout<<"\nIn Sorted Order:\n";
	displayInOrder(minHeap,n);
}
