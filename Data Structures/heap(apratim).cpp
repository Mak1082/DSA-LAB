#include<iostream>
using namespace std;

int parentindex(int index){
	return (index-1)/2;
}

int leftchildindex(int index){
	return 2*index+1;
}

int rightchildindex(int index){
	return 2*index+2;
}

int hasleftchild(int index,int size){
	return (leftchildindex(index)<size);
}

int hasrightchild(int index,int size){
	return (rightchildindex(index)<size);
}

int hasparent(int index,int size){
	return (parentindex(index)>=0);
}

void minheap(int* ptr,int size){
	int index=size-1;
	while(hasparent(index,size) && ptr[parentindex(index)]>ptr[index])
	{
		swap(ptr[parentindex(index)],ptr[index]);
		index=parentindex(index);
	}
}

void maxheap(int* ptr,int size){
	int index=size-1;
	while(hasparent(index,size) && ptr[parentindex(index)]<ptr[index])
	{
		swap(ptr[parentindex(index)],ptr[index]);
		index=parentindex(index);
	}
}

void add(int* ptr,int size,int item){
	ptr[size]=item;
	size++;
	minheap(ptr,size);
}

void addm(int* ptr,int size,int item){
	ptr[size]=item;
	size++;
	maxheap(ptr,size);
}

int main()
{
	int *heapmin=new int[100];
	int *heapmax=new int[100];
	int n;
	cout<<"Enter the number of elements in the heap: "<<endl;
	cin>>n;
	int item;
	for(int i=0;i<n;i++)
	{
        cout<<"Enter the element: "<<endl;
		cin>>item;
		add(heapmin,i,item);
		addm(heapmax,i,item);
		cout<<endl;
	}
	cout<<"Min Heap:";
	for(int i=0;i<n;i++)
	{
            cout<<heapmin[i]<<" ";
    }
    cout<<endl;
    cout<<"Max Heap:";
	for(int i=0;i<n;i++)
	{
            cout<<heapmax[i]<<" ";
    }
    cout<<endl;
	int m;
	cin>>m;
	return 0;
}

