#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int r, c;
int grid[101][101];
int vis[101][101];

void dfs(int x, int y){
    if(x<0 || y<0 || x>=r || y>=c) return;
    if(vis[x][y]==1 || grid[x][y]==0) return;
    vis[x][y]=1;
    dfs(x-1, y);
    dfs(x, y+1);
    dfs(x, y-1);
    dfs(x+1, y);
}

int main()
{
    std::ios::sync_with_stdio(false);
    int t; cin>>t;
    int cnt=1;
    while(t--){

        cout<<"Case #"<<cnt++<<": "<<endl;
        cin>>r>>c;
        for(int i=0; i<r; i++){
            string s; cin>>s;
            for(int j=0; j<c; j++){
                grid[i][j] = (s[j]=='0') ? 0: 1;
            }
        }

        int m; cin>>m;
        while(m--){
            char ch; cin>>ch;
            if(ch=='M'){
                int x, y, z; cin>>x>>y>>z;
                grid[x][y] = z;
            }
            else{
                memset(vis, 0, sizeof vis);
                int ans = 0;
                for(int i=0; i<r; i++){
                    for(int j=0; j<c; j++){
                        if(grid[i][j]==1 && !vis[i][j]){
                            ans++;
                            dfs(i, j);
                        }
                    }
                }
                cout<<ans<<endl;
            }
        }

    }
    return 0;
}
