#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[], bool visited[], int distance[], int start){
	visited[start] = true;
	distance[start] = 0;
	
	queue<int> q;
	q.push(start);
	
	while(!q.empty()){
		int s = q.front();
		q.pop();
		
		// process node 's'
		cout<<s<<" ";
		
		// store adjacenet unvisited nodes of 's'
		// to queue
		for(auto u : adj[s]){
			if(visited[u])
				continue;
			visited[u] = true;
			distance[u] = distance[s]+1;
			q.push(u);
		}
		
	}
	cout<<endl;
	
	
}

int main(){
	cout<<"Enter number of nodes & edges: ";
	int N, E;
	cin>>N>>E;
	
	
	
	vector<int> adj[N+1];
	bool visited[N+1] = {false};
	int distance[N+1] = {0};
	
	
	cout<<"Enter node pair for "<<E<<" edges\n";
	int u, v;
	for(int i  = 1; i<=E; i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int start = 1;
	bfs(adj, visited, distance, start);
	
}
