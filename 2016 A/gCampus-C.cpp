#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#define f first
#define s second
#define ll long long
using namespace std;

int n, m;
vector<pair<int, ll>> adj[101]; 
int source[10001], destiny[10001], cost[10001];
ll dis[101][101];

void dijkstra(int s){
	int vis[n];
	memset(vis, 0, sizeof vis);
	for(int i=0; i<n; i++) dis[s][i]=LLONG_MAX;
	dis[s][s]=0;
	priority_queue<pair<ll, int>> q; //-dis, vertice, road no
	q.push({0, s});
	while(!q.empty()){
		pair<ll, int> p = q.top();
		q.pop();
		int u=p.s;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0; i<adj[u].size(); i++){
			int v = adj[u][i].f;
			if(!vis[v] && dis[s][v] > dis[s][u]+adj[u][i].s){
				dis[s][v] = dis[s][u]+adj[u][i].s;
				q.push({-dis[s][v], v});
			}
		}
	}

}

int main() {
	// freopen("inputf.in", "r", stdin); // redirects standard input
	// freopen("outputf.in", "w", stdout); // redirects standard output

	int t; scanf("%d", &t);
	int cnt=1;
	while(t--){

		cerr<<t<<endl;

		printf("Case #%d:\n", cnt++);
		scanf("%d%d", &n, &m);
		// memset(roads, false, sizeof roads);
		for(int i=0; i<n; i++){
			adj[i].clear();
		}
		for(int i=0; i<m; i++){
			int u, v; ll c; scanf("%d%d%lld", &u, &v, &c);
			adj[u].push_back({v, c});
			adj[v].push_back({u, c});
			source[i]=u;
			destiny[i]=v;
			cost[i]=c;
		}
		for(int i=0; i<n; i++){
			dijkstra(i);
		}
		for(int i=0; i<m; i++){
			if(dis[source[i]][destiny[i]]!=cost[i]) printf("%d\n", i);
		}
	}										
	return 0;	
}