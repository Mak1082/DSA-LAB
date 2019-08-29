#include<iostream>
using namespace std;

void selectionSort(int* a, int n)
{
	int i,j,min;
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min]) min=j;
		}
		swap(a[i],a[min]);
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
	selectionSort(arr,n);
	display(arr,n);
}
