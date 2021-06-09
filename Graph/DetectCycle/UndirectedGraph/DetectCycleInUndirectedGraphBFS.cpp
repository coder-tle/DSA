#include<bits/stdc++.h>
using namespace std;


int N = 10005;
bool visited[10005];
vector<int> adj[10005];

bool isCycle(int x){
	visited[x] = true;
	
	queue<pair<int, int>> q;
	q.push({x, -1});
	
	while(!q.empty()){
		pair<int, int> s = q.front();
		q.pop();
		
		int node = s.first, prev = s.second;
		
		for(auto u : adj[node]){
			if(visited[u] && prev != u)
				return true;
			else if(visited[u] && prev == u)
				continue;
			visited[u] = true;
			q.push({u, node});
		}
	}
		return false;
}
bool checkCycle(int n){
	for(int i=1; i<=n; i++){
		if(!visited[i]){
			if(isCycle(i))
				return true;
				//cout<<"cycle exists\n";
		}
	}
	return false;
}
int main(){
	
	int n, e;
	cout<<"Enter number of nodes and edges of graph:\n";
	cin>>n>>e;
	
	cout<<"According to formula : ";
	if(e <= n-1) 
		cout<<"Cycle is not present\n";
	else
		cout<<"Cycle is present\n";
	
	int u, v;
	cout<<"Enter "<<e<<" edges of graph\n";
	
		
	for(int i = 1; i<=e; i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	if(checkCycle(n) == true)
		cout<<"cycle exists"<<endl;
	else
		cout<<"cycle does not exists\n";
	return 0;
}

