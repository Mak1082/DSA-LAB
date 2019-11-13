#include <iostream>
#include<vector>
using namespace std;

class Edge
{
  public:
    int src,dest,wt;
    Edge(int se,int de,int we)
    {
      src=se;
      dest=de;
      wt=we;
    }
};

void printDistance(int dist[], int v)
{
  cout<<"Vertex\tDistance from Source"<<endl;
  for(int i=0;i<v;i++)
  {
    cout<<i<<"\t  \t"<<dist[i]<<endl;
  }
}

void bellmanFord(vector<Edge*>graph, int v, int e)
{
  int i,j,src1,dest1,wt1;
  int dist[v];
  for(i=0;i<v;i++) dist[i]=100000;
  //Assuming source vertex to be zero
  dist[0]=0;
  graph[0]->src=0;
  for(i=0;i<v-1;i++)
  {
    for(j=0;j<e;j++)
    {
      src1=graph[j]->src;
      dest1=graph[j]->dest;
      wt1=graph[j]->wt;
      if(dist[src1]+wt1<dist[dest1])
      {
        dist[dest1]=wt1+dist[src1];
      }
    }
  }

  /*Checking for negative edge cycle
  If the distances change after the above process then there exists a negative edge cycle.*/
  bool flag=false; 
  for(j=0;j<e;j++)
  {
      src1=graph[j]->src;
      dest1=graph[j]->dest;
      wt1=graph[j]->wt;
      if(dist[src1]+wt1<dist[dest1])
      {
        cout<<"There exists a negative edge cycle"<<endl;
        flag=true;
        break;
      }
  }
  printDistance(dist,v);
  if(flag)
  cout<<"Since there exists a negative edge cycle so the above distances are not true as bellman ford does not work with graphs containing negative edge cycle."<<endl;
}

int main()
{
  vector<Edge*>graph;
  int i,j,v,e,se,de,we;
  cout<<"Enter no. of vertices and no. of edges"<<endl;
  cin>>v>>e;
  for(i=0;i<e;i++)
  {
    cout<<"Enter source, destination and weight of edge"<<i<<endl;
    cin>>se>>de>>we;
    Edge* temp=new Edge(se,de,we);
    graph.push_back(temp);
  }
  bellmanFord(graph,v,e);
}
