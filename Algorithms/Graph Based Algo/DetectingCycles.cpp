#include<iostream> 
#include<list> 
using namespace std; 

class Graph 
{ 
    public:
	int V;  
	
	list<int> *adj; 
	
	Graph(int V)
	{ 
		this->V = V; 
		adj = new list<int>[V]; 
	} 
	
	void addEdge(int v, int w) 
	{ 
		adj[v].push_back(w);
		adj[w].push_back(v);  
	}  
	
	bool checkCyclic(int v, bool visited[], int parent)
	{
		visited[v]=true;
		list<int>::iterator i; 
	    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
	    { 
	        if (!visited[*i]) 
	        { 
	           if (checkCyclic(*i, visited, v)) 
	              return true; 
	        } 
	        else if (*i != parent) 
	           return true; 
	    } 
	    return false;
	}

	bool isCyclic() 
	{  
		bool *visited = new bool[V]; 
	for (int i = 0; i < V; i++) 
		visited[i] = false; 
 
	for (int u = 0; u < V; u++) 
		if (!visited[u])  
		if (checkCyclic(u, visited, -1)) 
			return true; 

	return false;  
	} 
};


int main() 
{ 
	Graph g(5); 
    g.addEdge(1, 0); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(0, 3); 
    g.addEdge(3, 4); 

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
