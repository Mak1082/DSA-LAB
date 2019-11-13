#include<iostream>
using namespace std;

const int n=9;

int find(int i, int *parent)
{
	while(i!=parent[i])
		i=parent[i];
	return i;
}

void takeUnion(int i, int j, int* parent)
{
	int a=find(i, parent);
	int b=find(j, parent);
	parent[a]=b;
}

void MSTKruskal(int graph[n][n])
{
	int i,j,a,b,edges=0,min, min_cost=0;
	int parent[n];
	for(i=0;i<n;i++) parent[i]=i;
	cout<<"Edge\tCost"<<endl;
	while(edges!=n-1)
	{
		cout<<"\nParent Array: "<<endl;
		for(i=0;i<n;i++) cout<<parent[i]<<" ";
		cout<<endl;
	    min=10000000;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(find(i,parent)!=find(j,parent) && graph[i][j] && graph[i][j]<min)
				{
					min=graph[i][j];
					a=i; b=j;
				}
			}
		}
	    edges++;
		takeUnion(a,b,parent);
		cout<<a<<"->"<<b<<"\t"<<min<<endl;
		min_cost=min_cost+min;
	}
	cout<<"Minimum cost = "<<min_cost;	
}

int main()
{
	int graph[n][n] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
	
	MSTKruskal(graph); 
    return 0;
}
