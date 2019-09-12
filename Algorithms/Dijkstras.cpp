#include<iostream>
using namespace std;

const int n=9;

//Picking the smaller vertex from the vertices not yet included.
int min(int dist[], int selected[], int n)
{
	int min=10000000; int min_index;
	for(int i=0;i<n;i++)
	{
		if(selected[i]==0 && dist[i]<=min)
		{
			min=dist[i]; min_index=i;
		}
	}
	return min_index;
}

void printPath(int parent[],int j)
{
	int path[n]; int i,m=0;
	for(i=0;i<n;i++) path[i]=-1;
	while(parent[j]!=-1)
	{
		//cout<<j<<" ";
		path[m++]=j;
		j=parent[j];
	}
	cout<<j<<"->";
	for(i=n-1;i>=0;i--)
	if(path[i]!=-1)
	cout<<path[i]<<"->";
	cout<<endl;
}

void print(int dist[], int n, int parent[])
{
	cout<< "Vertex \t    Distance \tPath\n";
	for(int i=1;i<n;i++)
	{
		cout<<"0->"<<i<<"\t\t"<<dist[i]<<"\t";
		printPath(parent,i);
	}

}

void dijkstra(int graph[n][n], int src)
{
	int i,j;
	int parent[n];
	int dist[n]; int selected[n];
	for(int i=0;i<n;i++)
	{
		dist[i]=10000000;
		selected[i]=0;
	}
	parent[0]=-1;
	dist[src]=0;
	for(i=0;i<n-1;i++)
	{
		int u=min(dist,selected,n);
		selected[u]=1;
		for(j=0;j<n;j++)
		{
			if(!selected[j] && graph[u][j] && dist[u]!=10000000 && dist[u]+graph[u][j]<dist[j])
			{
				dist[j]=dist[u]+graph[u][j];
				parent[j]=u;
			}
		}
	}
	print(dist,n,parent);	
}


int main()
{
	int i,j;
	/*cout<<"Enter no. of nodes "<endl;
	cin>>n;
	int graph[n][n];
	cout<<"Create the graph"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"Enter connections of "<<i<<endl;
		for(j=0;j<n;j++)
		{
			cin>>graph[i][j];
		}
	}*/
	int graph[n][n] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
    dijkstra(graph,0);
    return 0;
	//dijkstra(graph,n,0); 
}
