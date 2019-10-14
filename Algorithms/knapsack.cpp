#include<iostream>
#include<vector>
using namespace std;

void knapsackProblem(vector<double> profit,vector< double> wt, int n, int capacity)
{
	int i,j;
	vector<double>rt;
	for(i=0;i<n;i++)
	{
		rt.push_back(profit[i]/wt[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(rt[j+1]>rt[j])
			{
				swap(rt[j],rt[j+1]);
				swap(profit[j],profit[j+1]);
				swap(wt[j],wt[j+1]);
			}
		}
	}
	cout<<"Profit  Weight  Profit/Weight"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<profit[i]<<"  \t"<<wt[i]<<"\t  "<<rt[i]<<endl;
	}
	double money=0.0;
	for(i=0;i<n;i++)
	{
		if(wt[i]<=capacity)
		{
			money=money+profit[i];
			capacity=capacity-wt[i];
		}
		else
		{
			money=money+(capacity)*profit[i]/wt[i];
			break;
		}
	}
	cout<<"Total Profit = "<<money;
}

int main()
{
	int i,n,x1,x2,capacity;
	cout<<"Enter no. of objects"<<endl;
	cin>>n;
	vector<double> profit,wt;
	cout<<"For each object enter profit and then weight"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>x1;
		cin>>x2;
		profit.push_back(x1);
		wt.push_back(x2);
	}
	cout<<"Enter bag capacity"<<endl;
	cin>>capacity;
	knapsackProblem(profit,wt,n,capacity);
}
