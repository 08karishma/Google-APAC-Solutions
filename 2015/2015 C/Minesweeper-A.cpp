//SOLUTION HERE - http://forthright48.blogspot.in/2015/08/spoj-lcmsum-lcm-sum.html
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAX 301
using namespace std;

vector<pair<int,int>> graph[MAX][MAX];
int vis[MAX][MAX];
char grid[MAX][MAX];
int n;

bool checkValid(int x, int y){
    if(x<0 || y<0 || x>=n || y>=n) return false;
    return true;
}

int neighbours(int x, int y){
    int ans=0;
    for(int dx=-1; dx<=1; dx++){
        for(int dy=-1; dy<=1; dy++){
            if(dx==0 && dy==0) continue;
            if(!checkValid(x+dx, y+dy)) continue;
            if(grid[x+dx][y+dy]=='*') ans++;
        }
    }
    return ans;
}

void dfs(int x, int y){
    vis[x][y]=1;
    for(int i=0; i<graph[x][y].size(); i++){
        int x1=graph[x][y][i].first;
        int y1=graph[x][y][i].second;
        if(!vis[x1][y1]) dfs(x1, y1);
    }
}

int main()
{
    int t; scanf("%d", &t);
    int cnt=1;
    while(t--){
        scanf("%d", &n);
        printf("Case #%d: ", cnt++);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                graph[i][j].clear();
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf(" %c", &grid[i][j]);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='*') {
                    // cout<<"* ";
                    continue;
                }
                // cout<<neighbours(i,j)<<" ";
                if(neighbours(i, j)==0){
                    for(int di=-1; di<=1; di++){
                        for(int dj=-1; dj<=1; dj++){
                            if(di==0 && dj==0) continue;
                            if(!checkValid(i+di, j+dj)) continue;
                            graph[i][j].push_back({i+di, j+dj});
                        }
                    }
                }
            }//cout<<endl;
        }
        memset(vis, 0, sizeof vis);
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='*' || neighbours(i,j)!=0) continue;
                if(!vis[i][j]){
                    ans++;
                    dfs(i, j);
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='*') continue;
                if(!vis[i][j]){
                    ans++;
                    dfs(i, j);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
