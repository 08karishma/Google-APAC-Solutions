//We only need to keep track of visited nodes in dijkstra if there are negative edges,
//since otherwise the condition dis[next]>dis[cur]+cost will never hold true for already
//visited nodes
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define f first
#define s second
#define pip pair<int, pair<int,int>>
#define pp pair<pair<int,int>, pair<int,int>>
#define INF 2147483647
#define MAX 101
#define MAX_STAT 1001
using namespace std;

int N, max_stat;
int numStations[MAX], waitTimes[MAX];
vector<pip> graph[MAX][MAX_STAT];
int sx, sy, dx, dy; //source and dest

int dijkstra(){
    int dis[2][N+1][max_stat+1];
    for(int i=1; i<=N; i++){
        for(int j=1; j<=max_stat; j++){
            dis[0][i][j] = INF;
            dis[1][i][j] = INF;
        }
    }
    dis[0][sx][sy]=0;
    priority_queue<pp> q;
    q.push({{0,-1}, {sx, sy}});
    while(!q.empty()){
        pp p = q.top();
        q.pop();
        int from=p.f.s, cur_dis = -p.f.f, cur_x = p.s.f, cur_y = p.s.s;
        int flag = (from==cur_x);
        // cout<<(p.f.s==p.s.f)<<" "<<p.s.f-1<<" "<<p.s.s-1<<endl;
        if(cur_x==dx && cur_y==dy) return cur_dis;
        for(int i=0; i<graph[cur_x][cur_y].size(); i++){
            int next_x = graph[cur_x][cur_y][i].s.f;
            int next_y = graph[cur_x][cur_y][i].s.s;
            int next_dis = graph[cur_x][cur_y][i].f;
            int flag1 = (next_x==cur_x);
            if(!flag && flag1) next_dis += waitTimes[cur_x];
            if(dis[flag1][next_x][next_y] > next_dis+dis[flag][cur_x][cur_y]){
                dis[flag1][next_x][next_y] = next_dis+dis[flag][cur_x][cur_y];
                q.push({{-dis[flag1][next_x][next_y],cur_x} ,{next_x, next_y}});
            }
        }
    }
    return dis[0][dx][dy];
}

int main()
{
    int t; scanf("%d", &t);
    int cnt=1;
    while(t--){
        printf("Case #%d:\n", cnt++);
        for(int i=1; i<MAX; i++){
            for(int j=1; j<MAX_STAT; j++){
                graph[i][j].clear();
            }
        }
        scanf("%d", &N);
        max_stat=0;
        for(int i=1; i<=N; i++){
            scanf("%d", &numStations[i]);
            max_stat = max(max_stat, numStations[i]);
            scanf("%d", &waitTimes[i]);
            for(int j=1; j<numStations[i]; j++){
                int time; scanf("%d", &time);
                graph[i][j].push_back({time, {i,j+1}});
                graph[i][j+1].push_back({time, {i,j}});
            }
        }
        int m; scanf("%d", &m);
        for(int i=0; i<m; i++){
            int i1, j1, i2, j2, time;
            scanf("%d%d%d%d%d", &i1, &j1, &i2, &j2, &time);
            // cout<<"i1="<<i1<<" j1="<<j1<<" i2="<<i2<<" j2="<<j2<<endl;
            graph[i1][j1].push_back({time, {i2, j2}});
            graph[i2][j2].push_back({time, {i1, j1}});
        }
        int q; scanf("%d", &q);
        while(q--){
            scanf("%d%d%d%d", &sx, &sy, &dx, &dy);
            int ans = dijkstra();
            if(ans==INF) ans=-1;
            printf("%d\n", ans);
        }
    }
    return 0;
}
