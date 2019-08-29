#include<iostream>
using namespace std;

int partition(int a[],int left, int right, int pivot)
{
	while(left<=right)
	{
		while(a[left]<pivot)
			left++;
		while(a[right]>pivot)
			right--;
		if(left<=right)
		{
			swap(a[left],a[right]);
			left++;
			right--;
		}
	}
	return left;
}

void quickSort(int a[], int left ,int right)
{
	if(left>=right) return;
	int pivot=a[(left+right)/2];
	int index=partition(a,left,right,pivot);
	quickSort(a,left,index-1);
	quickSort(a,index,right);
}

void display(int a[], int n)
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
	int arr[n];
	cout<<"Enter elements\n";
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	quickSort(arr,0,n-1);
	display(arr,n);
}
