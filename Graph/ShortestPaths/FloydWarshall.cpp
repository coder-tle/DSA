#include<bits/stdc++.h>
using namespace std;

int main(){
	int tc;
	cin>>tc;
	
	while(tc--){
		cout<<"Enter number of nodes of undirected graph:\n";
		int n;
		cin>>n;
		int adj[n+1][n+1];
		
		for(int i = 0; i<=n; i++){
			for(int j = 0; j<=n; j++)
				adj[i][j] = 0;
		}
		cout<<"Enter number of edges of undirected graph:\n";
		int e;
		cin>>e;
		
		int u, v, w;
		
		cout<<"Enter edges along with its weight:\n";
		for(int i = 0; i<e; i++){
			cin>>u>>v>>w;
			adj[u][v] = w;
			adj[v][u] = w;
			
		}
		int dis[n+1][n+1] ;
		
		// create distance matrix
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=n; j++){
				if(i==j)
					dis[i][j] = 0;
				else if(adj[i][j])
					dis[i][j] = adj[i][j];
				else
					dis[i][j] = INT_MAX/2;
			}
		}
		
		// N rounds of iteration to create distance matrix
		
		for(int r = 1; r<=n; r++){
			for(int i = 1; i<=n; i++){
				for(int j =1; j<=n; j++){
					dis[i][j] = min(dis[i][j] , dis[i][r] + dis[r][j]);
				}
			}
		}
		
		// display final distance matrix
		for(int i = 1; i<=n; i++)
		{
			for(int j = 1; j<=n; j++){
				cout<<dis[i][j]<<" ";
			}
			cout<<endl;
		}
		
		
		cout<<endl<<endl;
	}
	
	
	
	
}
