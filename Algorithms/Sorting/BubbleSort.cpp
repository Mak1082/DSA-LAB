#include<iostream>
using namespace std;

void bubbleSort(int* a, int n)
{
	int i,j; bool flag;
	for(i=0;i<n;i++)
	{
		flag=false;
		for(j=0;j<n-i;j++)
		{
			if(a[j+1]<a[j])
			{
				swap(a[j+1],a[j]); flag=true;
			}
		}
		if(flag==false) break;
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
	bubbleSort(arr,n);
	display(arr,n);
}
