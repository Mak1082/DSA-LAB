#include<iostream>
using namespace std;

int qswaps=0,qcom=0,mswaps=0,mcom=0;
int partition(int a[],int left, int right, int pivot)
{
  
	while(left<=right)
	{
		while(a[left]<pivot)
		{	left++;
    qcom++;
    }
		while(a[right]>pivot)
		{	right--;
    qcom++;
    }
		if(left<=right)
		{
			swap(a[left],a[right]);
      qswaps++;
      qcom++;
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

void merge(int arr[],int l, int m, int r)
{
	int i,j,k,n1,n2;
	n1=m-l+1;
	n2=r-m;
	int L[n1], R[n2];
	for(i=0;i<n1;i++)
		L[i]=arr[l+i];
	for(j=0;j<n2;j++)
		R[j]=arr[m+1+j];
	i=0; j=0; k=l;
	while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++;
            mcom++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++;
            mcom++; 
        } 
        k++; mswaps++; 
    } 
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
}

void mergeSort(int a[], int l,int r)
{
	if(l<r)
	{
		int m=(l+r)/2;
		mergeSort(a,l,m);
		mergeSort(a,m+1,r);
		merge(a,l,m,r);
	}
}

void displayq(int a[], int n)
{
	cout<<"Sorted Array is: \n";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
  cout<<endl<<"Swaps = "<<qswaps<<endl<<"Comparisons =  "<<qcom<<endl;
}

void displaym(int a[], int n)
{
	cout<<"Sorted Array is: \n";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
  cout<<endl<<"Swaps = "<<mswaps<<endl<<"Comparisons =  "<<mcom<<endl;
}

int main()
{
	int i,n;
	cout<<"Enter no. of elements\n";
	cin>>n;
	int arr1[n],arr2[n];
	cout<<"Enter elements\n";
	for(i=0;i<n;i++)
	{
		cin>>arr1[i];
    arr2[i]=arr1[i];
	}
	quickSort(arr1,0,n-1);
  cout<<"Quick Sort\n";
	displayq(arr1,n);
  cout<<"Merge Sort\n";
  mergeSort(arr2,0,n-1);
  displaym(arr2,n);
}
