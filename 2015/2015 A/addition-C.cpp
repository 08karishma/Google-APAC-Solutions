#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <queue>
#define MAX 20010
#define s second
#define f first
using namespace std;

vector<pair<long long, int>> adj[MAX];
int nodes;

long long bfs(int source, int dest){
    int vis[2*nodes];
    memset(vis, 0, sizeof vis);
    long long dis[2*nodes];
    int level[2*nodes];
    memset(level, -1, sizeof level);
    queue<int> q;
    dis[source]=0;
    level[source]=0;
    q.push(source);
    while(!q.empty()){
        int u=q.front(); q.pop();
        if(vis[u]==1) continue;
        vis[u]=1;
        if(u==dest) return dis[u];
        for(int i=0; i<adj[u].size(); i++){
            int v= adj[u][i].s;
            if(vis[v]==0){
                q.push(v);
                if(level[u]%2==0) dis[v] = dis[u]+adj[u][i].f;
                else dis[v] = dis[u]-adj[u][i].f;
                level[v] = level[u]+1;
            }
        }
    }
    return -1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int t; cin>>t;
    int cnt=1;
    while(t--){
        int n; cin>>n;
        cout<<"Case #"<<cnt++<<":"<<endl;
        unordered_map<string, int> mp;
        vector<pair<long long, int>> adj_temp[MAX];
        double vals[MAX];
        for(int i=0; i<MAX;i++) vals[i]=200001;
        int cnt=0;
        while(n--){
            string s; cin>>s;
            int i=0;
            while(s[i]!='+') i++;
            string s1 = s.substr(0, i);
            int j=i+1;
            while(s[i]!='=') i++;
            string s2 = s.substr(j, i-j);
            long long val = stol(s.substr(i+1, s.length()-i-1));
            if(mp.find(s1)==mp.end()) mp[s1]=cnt++;
            if(mp.find(s2)==mp.end()) mp[s2]=cnt++;
            adj_temp[mp[s1]].push_back({val, mp[s2]});
            adj_temp[mp[s2]].push_back({val, mp[s1]});
            if(mp[s1]==mp[s2]){
                vals[mp[s1]] = (double)val/(double)2;
            }
            // cout<<s1<<" "<<s2<<" "<<val<<endl;
        }

        nodes = mp.size();
        //form bipartite graph from this
        for(int i=0; i<2*nodes; i++) adj[i].clear();
        for(int i=0; i<nodes; i++){
            for(int j=0; j<adj_temp[i].size(); j++){
                long long val = adj_temp[i][j].f;
                int k = adj_temp[i][j].s;
                adj[i].push_back({val, k+nodes});
                adj[i+nodes].push_back({val, k});
            }
        }

        int q; cin>>q;
        while(q--){
            string s; cin>>s;
            int i=0;
            while(s[i]!='+') i++;
            string s1 = s.substr(0, i);
            string s2 = s.substr(i+1, s.length()-i-1);
            if(mp.find(s1)==mp.end()) continue;
            if(mp.find(s2)==mp.end()) continue;
            if(vals[mp[s1]]!=200001 && vals[mp[s2]]!=200001){
                cout<<s<<"="<<vals[mp[s1]]+vals[mp[s2]]<<endl;
                continue;
            }
            long long ans = bfs(mp[s1], mp[s2]+nodes);
            if(ans!=-1){
                cout<<s<<"="<<ans<<endl;
            }
        }
    }
    return 0;
}