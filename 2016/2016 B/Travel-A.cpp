#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#define f first
#define s second
#define pii pair<int,int>
#define INF INT_MAX
using namespace std;

int N, M;
int graph[24][501][501];

int dijkstra(int D, int S){
	int vis[N];
	memset(vis, 0, sizeof vis);
	int dis[N];
	for(int i=0; i<N; i++) dis[i]=INF;
	dis[0]=S;
	priority_queue<pair<int,int>> q;
	q.push({-S, 0});
	while(!q.empty()){
		pair<int,int> p = q.top();
		q.pop();
		int u=p.s;
		int cost = -p.f;
		if(vis[u]) continue;
		vis[u]=1;
		if(u==D) return cost;
		for(int v=0; v<N; v++){
			if(graph[cost%24][u][v]==INF) continue;
			if(!vis[v] && dis[v] > dis[u]+graph[cost%24][u][v]){
				dis[v] = dis[u]+graph[cost%24][u][v];
				q.push({-dis[v], v});
			}
		}
	}
	return dis[D];
}

int main() {
	freopen("inputf.in", "r", stdin); // redirects standard input
	freopen("outputf.in", "w", stdout); // redirects standard output

	int t; scanf("%d", &t);
	int cnt=1;
	while(t--){
		cerr<<t<<endl;
		printf("Case #%d: ", cnt++);
		int K;
		scanf("%d%d%d", &N, &M, &K);

		//initialize
		for(int i=0; i<24; i++){
			for(int j=0; j<N; j++){
				for(int k=0; k<N; k++){
					graph[i][j][k] = (j==k) ? 0:INF;
				}
			}
		}

		while(M--){
			int u, v; scanf("%d%d", &u, &v);
			u--; v--;
			for(int i=0; i<24; i++){
				scanf("%d", &graph[i][u][v]);
				graph[i][v][u] = graph[i][u][v];
			}
		}

		while(K--){
			int D, S;
			scanf("%d%d", &D, &S);
			D--;
			int ans = dijkstra(D, S);
			if(ans==INF) ans=-1;
			else ans -= S;
			printf("%d ", ans);
		}	
		printf("\n");
		
	}										
	return 0;	
}