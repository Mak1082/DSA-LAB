#include<iostream>
#include<list>
using namespace std;

class Graph
{
  public:
  list<int>*adj;
  int V;
  
  Graph(int n)
  {
    V=n;
    adj=new list<int>[V];
  }

  void addEdge(int u, int v)
  {
    adj[u].push_back(v);
  }

  bool DFS(int visited[], int s)
  {
    int parent[V];
    for(int k=0;k<V;k++) parent[k]=-1;
    list<int>q;
    q.push_back(s);
    visited[s]=1;
    while(!q.empty())
    {
      s=q.front();
      q.pop_front();
      visited[s]=1;
      list<int>::iterator i;
      for(i=adj[s].begin();i!=adj[s].end();i++)
      {
        if(visited[*i]==0)
        {
          q.push_back(*i);
          visited[*i]=1;
          parent[*i]=s;
        }
        else if(parent[*i]!=s) return true;
      }
    }
    return false;
  }

  bool isCyclic()
  {
    int visited[V]; int i;
    for(i=0;i<V;i++) visited[i]=0;
    return DFS(visited,0);
//    Traversing from all vertices is not necessary for connected graphs
//	for(i=0;i<V;i++)
//    {
//      if(!visited[i] && DFS(visited,i))
//      return true;
//    }
    return false;
  }
};

int main()
{
	Graph g(6); 
    g.addEdge(0, 1); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(3, 4); 
    g.addEdge(4, 5);  

	list<int>::iterator j;
	cout<<"Connections:"<<endl;
	for(int i=0;i<5;i++)
	{
	    cout<<i<<":";
	    for( j=g.adj[i].begin();j!=g.adj[i].end();j++)
	    {
	        cout<<*j<<" ";
	    }
	    cout<<endl;
	}
	g.isCyclic()? cout << "Graph contains cycle\n": 
                   cout << "Graph doesn't contain cycle\n";
				   
	Graph g2(3); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2);
	
	cout<<"Connections:"<<endl;
	for(int i=0;i<3;i++)
	{
	    cout<<i<<":";
	    for( j=g2.adj[i].begin();j!=g2.adj[i].end();j++)
	    {
	        cout<<*j<<" ";
	    }
	    cout<<endl;
	}
    g2.isCyclic()? cout << "Graph contains cycle\n": 
                   cout << "Graph doesn't contain cycle\n";   

	return 0;
}
