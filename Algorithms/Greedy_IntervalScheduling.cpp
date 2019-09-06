#include<iostream>
#include<vector>
using namespace std;

//Assuming that n is always greater than k.

void maximumBookings(vector<int>arr,vector<int>depart,int k,int n)
{
	int i,j;
	int t1,t2;
	//Sorting according to departure date.
	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(depart[j]>depart[j+1])
			{
				t1=depart[j];
				depart[j]=depart[j+1];
				depart[j+1]=t1;
				t2=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=t2;
			}
		}
	}
	cout<<"Arrival: ";
	for(i=0;i<n;i++) cout<<arr[i]<<" ";
	cout<<"\nDeparture: ";
	for(i=0;i<n;i++) cout<<depart[i]<<" ";
	cout<<"\nCustomer order for maximum utilization of rooms: ";
	cout<<"\n1 ";
	k=k-1; int m=0,c=0;
	for(i=1;i<n;i++)
	{
		if(arr[i]>=depart[m] || k>0)
		{
			
			cout<<i+1<<" ";
			k=k-1; c=1;
		}
		else if(k>0)
		{
			cout<<i+1<<" "; k=k-1;
		}
		if(arr[i]>=depart[m]) k=k+1;
		if(c==1) m=i;
		c=0;
	}
}

int main()
{
	cout<<"Enter no. of bookings"<<endl;
	int i,j,n,k,x,y;
	cin>>n;
	cout<<"Enter no. of hotel rooms"<<endl;
	cin>>k;
	vector<int> arr; vector<int>depart;
	for(i=0;i<n;i++)
	{
		cout<<"Enter arrival and departure date of "<<"customer "<<(i+1)<<endl;
		cin>>x;
		cin>>y;
		arr.push_back(x);
		depart.push_back(y);
	}
	maximumBookings(arr,depart,k,n);
}
