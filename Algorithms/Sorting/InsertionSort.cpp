#include<iostream>
using namespace std;

void insertionSort(int* a, int n)
{
	int i,j,key;
	for(i=1;i<n;i++)
	{
		key=a[i]; j=i-1;
		while(j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
	}
}

void display(int* a, int n)
{
	cout<<"Sorted Array is: \n";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}

int main()
{
	int i,n;
	cout<<"Enter no. of elements\n";
	cin>>n;
	int* arr=new int[n];
	cout<<"Enter elements\n";
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	insertionSort(arr,n);
	display(arr,n);
}
