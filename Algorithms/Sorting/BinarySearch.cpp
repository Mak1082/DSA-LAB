#include<iostream>
using namespace std;

void iterativeSearch(int a[], int n, int data)
{
	int l=0, r=n-1, m=(l+r)/2;
	while(a[m]!=data && l!=r)
	{
		if(data<a[m])
			r=m-1;
		else
			l=m+1;
		m=(l+r)/2;
	}
	if(a[m]==data)cout<<"Found at index = "<<m<<endl;
	else cout<<"Not found"<<endl;
}

void recursiveSearch(int a[], int l,int r, int data)
{
	int m=(l+r)/2;
	if(a[m]==data)
	{
		cout<<"Found at index: "<<m<<endl;
		return;
	}
	else if(l!=r)
	{
		if(data<a[m])
		recursiveSearch(a,l,m-1,data);
		else
		recursiveSearch(a,m+1,r,data);
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
	cout<<"Enter data to be searched\n";
	int x;
	cin>>x;
	recursiveSearch(arr,0,n-1,x);
}
