#include<iostream>
using namespace std;

const int n=6;

int minKey(int key[], int selected[])
{
	int i,j, min=10000000,min_index;
	for(i=0;i<n;i++)
	{
		if(selected[i]==0 && key[i]<min)
		{
			min=key[i]; min_index=i;
		}
	}
	return min_index;
}

void printMST(int graph[n][n], int parent[])
{
	cout<<"Edge\tWeight"<<endl;
	for(int i=1;i<n;i++)
	{
		cout<<parent[i]<<"->"<<i<<"\t  "<<graph[i][parent[i]]<<endl;
	}
}

void MSTPrim(int graph[n][n])
{
	int parent[n];
	int key[n];
	int selected[n];
	parent[0]=-1;
	int i,j,k,u;
	for(i=0;i<n;i++)
	{
		key[i]=10000000;
		selected[i]=0;	
	}
	key[0]=0;
	for(i=1;i<n;i++)
	{
		u=minKey(key,selected);
		selected[u]=1;
		for(j=0;j<n;j++)
		{
			if(graph[u][j] && selected[j]==0 &&graph[u][j]<key[j])
			{
				parent[j]=u; key[j]=graph[u][j];
			}
		}
	}
	cout<<"Parent array:"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<parent[i]<<" ";
	}
	cout<<endl;
	printMST(graph,parent);
}
int main()
{
	int i,j;
	int graph[n][n] = { { 0, 3, 0, 1, 0, 0 }, 
                        { 3, 0, 1, 3, 0, 0 }, 
                        { 0, 1, 0, 1, 5, 4 }, 
                        { 1, 3, 1, 0, 6, 0 }, 
                        { 0, 0, 5, 6, 0, 2 }, 
                        { 0, 0, 4, 0, 2, 0 },};
    MSTPrim(graph);
    for(i=0;i<6;i++)
    {
    	for(j=0;j<6;j++)
    	{
    		cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
    return 0;
}
