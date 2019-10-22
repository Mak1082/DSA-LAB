#include<iostream>
using namespace std;

const int n=9;

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

void printDist(int dist[], int source[])
{
    int i,j;
    cout<<"Start \t End \t Distance \t Path"<<endl;
    for(i=1;i<n;i++)
    {
        cout<<"0 \t "<<i<<"\t "<<dist[i]<<"\t\t";
        printPath(source,i);
    }
}

void dijkstra(int graph[n][n])
{
    int dist[n], i,j,u, selected[n], source[n];
    for(i=0;i<n;i++)
    {
        dist[i]=10000000;
        selected[i]=0;
    }
    source[0]=-1;
    dist[0]=0;
    for(int i; i<n; i++)
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
    printDist(dist, source);
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
    dijkstra(graph);
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

