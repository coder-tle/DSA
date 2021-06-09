#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], bool visited [], int s){
	if(visited[s])
		return;
		
	visited[s] = true;
	// process node 's'
	cout<<s<<" ";
	for(auto u : adj[s])
	{
		dfs(adj, visited, u);
	}
	
}

int main(){
	
	// Number of nodes and edges
	int N, E;
	cin>>N>>E;
	
	// adjacency list
	vector<int> adj[N+1];
	// boolean array to mark visited nodes
	bool visited[N+1] = {false};
	int u, v;
	cout<<"Enter "<<E<<" node pair of graph\n";
	for(int i = 0; i<E; i++)
		{
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
	dfs(adj, visited, 1);
	
	
	
}
