#include<iostream>
#include<list>
using namespace std;

class Graph
{
	public:
		int V;
		list<int>*adj;
		Graph(int n)
		{
			V=n;
			adj=new list<int>[V];
		}
		void addEdge(int v, int w)
		{
			adj[v].push_back(w);
		}
		void BFS()
		{
			int selected[V];
			int i,s;
			for(i=0;i<V;i++) selected[i]=0;
			list<int>q;
			q.push_back(2); selected[2]=1;
			while(!q.empty())
			{
				s=q.front();
				cout<<s<<" ";
				q.pop_front();
				list<int>::iterator j;
				for(j=adj[s].begin();j!=adj[s].end();j++)
				{
					if(!selected[*j])
					{
						q.push_back(*j);
						selected[*j]=1;
					}
				}	
			}
		}
};

int main()
{
	Graph g(4);
	g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
    g.BFS();
}
