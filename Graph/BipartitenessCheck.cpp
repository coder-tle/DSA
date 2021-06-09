#include<bits/stdc++.h>
using namespace std;

bool checkBipartite(vector<int> adj[], bool visited[], int color[], int x){
	
	visited[x] = true;
	color[x] = 0;
	
	queue<int> q;
	q.push(x);
	
	while(!q.empty()){
		int s = q.front(); q.pop();
		int clr = color[s];
		
		for(auto u : adj[s]){
			if(visited[u] ){
				if(color[u] == clr)
					return false;
				else
					continue;
			}
			visited[u] = true;
			color[u] = !color[s];
			q.push(u);
		}
	}
	return true;
	
	
}


int main(){
	
	int tc;
	cin>>tc;
	
	while(tc--){
		int n, e;
		
		cout<<"Enter number of nodes & edges of graph : \n";
		cin>>n>>e;
		
		vector<int> adj[n+1];
		int color[n+1] = {0};
		bool visited[n+1] = {false};
		
		cout<<"Enter "<<e<<" edges of the graph\n";
		int u, v;
		for(int i = 1; i<=e; i++)
		{
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		
		if(checkBipartite(adj, visited, color, 1)){
			cout<<"Graph is bipartite\n";
		}
		else
			cout<<"Graph is not bipartite\n";
			
	}
	return 0;
}
