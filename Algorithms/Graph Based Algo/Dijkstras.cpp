#include<iostream>
using namespace std;

const int n=4;

int min(int dist[], int selected[])
{
    int m=10000000, m_index;
    for(int i=0;i<n;i++)
    {
        if(selected[i]==0 && dist[i]<m)
        {
            m=dist[i]; m_index=i;
        }
    }
    return m_index;
}

void printPath(int source[], int j)
{
    int path[n]; int i,m=0;
    for(i=0;i<n;i++) path[i]=-1;
    while(source[j]!=-1)
    {
        path[m++]=j;
        j=source[j];
    }
    cout<<j<<"->";
    for(i=n-1;i>=0;i--)
    {
        if(path[i]!=-1)
        cout<<path[i]<<"->";
    }
    cout<<endl;
}

void printDist(int dist[], int source[],int src)
{
    int i,j;
    cout<<"Start \t End \t Distance \t Path"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<src<<" \t "<<i<<"\t "<<dist[i]<<"\t\t";
        printPath(source,i);
    }
}

void dijkstra(int graph[n][n], int src)
{
    int dist[n], i,j,u, selected[n], source[n];
    for(i=0;i<n;i++)
    {
        dist[i]=10000000;
        selected[i]=0;
    }
    source[src]=-1;
    dist[src]=0;
    for(int i=0; i<n; i++)
    {
        u=min(dist,selected);
        selected[u]=1;
        for(j=0;j<n;j++)
        {
            if(!selected[j] && graph[u][j] && dist[u]+graph[u][j]<dist[j])
            {
                dist[j]=dist[u]+graph[u][j];
                source[j]=u;
            }
        }
    }
    cout<<"Parent Array"<<endl;
    for(i=0;i<n;i++)
    {
    	cout<<i<<":"<<source[i]<<" , ";
	}
	cout<<endl;
    printDist(dist, source,src);
}

int main()
{
    int graph[n][n] = { { 0, 24, 3, 20  }, 
                        { 24, 0, 0, 0  }, 
                        { 3, 0, 0, 12 }, 
                        { 20, 0, 12, 0 }, 
                    	};
    cout<<"Enter source"<<endl;
    int src;
	cin>>src;
	dijkstra(graph,src);
    cout<<"\nGraph:"<<endl;
    for(int i=0;i<n;i++)
    {
      cout<<i<<": ";
      for(int j=0;j<n;j++)
      {
        cout<<graph[i][j]<<" ";
      }
      cout<<endl;
    }
    return 0;
}
