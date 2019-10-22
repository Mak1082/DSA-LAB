#include<iostream>
using namespace std;

const int n=8;

int min(int a, int b)
{
  if(a<b) return a;
  else return b;
}

void printDistance(int graph[][n])
{
  int i,j;
  cout<<"Distance Matrix"<<endl;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(graph[i][j]<10000)
      cout<<graph[i][j]<<" ";
      else
      cout<<"INF"<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
  cout<<"Source  Destination  Distance"<<endl;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(graph[i][j]<10000)
      cout<<i<<"\t"<<j<<"\t"<<graph[i][j]<<endl;
      else
      cout<<i<<"\t"<<j<<"\t"<<"INF"<<endl;

    }
    cout<<endl;
  }
}

void floydAPSP(int graph[][n])
{
  int i,j,k;
  
  for(k=0;k<n;k++)
  {
    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
        graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
      }
    }
  }
  printDistance(graph);
}

int main()
{
  int INF=100000;

  int graph[n][n] = { 
                	{0,INF,INF,INF,INF,INF,INF,INF},
                    {INF,0,INF,INF,-1,INF,2,INF},
                    {INF,INF,0,INF,INF,INF,INF,-2},
                    {INF,INF,INF,0,3,INF,INF,2},
                    {INF,INF,INF,INF,0,7,INF,INF},
                    {INF,INF,INF,INF,INF,0,INF,INF},
                    {INF,INF,INF,INF,INF,INF,0,INF},
                    {1,INF,INF,INF,INF,3,4,0} };
  floydAPSP(graph);
}
