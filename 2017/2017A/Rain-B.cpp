#include <iostream>
#define MAX 51
#include <cstring>
using namespace std;

int h[MAX][MAX];
int r, c;
int vis[MAX][MAX];

int dfs(int x, int y){

	if(x==0 || x==r-1 || y==0 || y==c-1) return h[x][y];
	vis[x][y]=1;
	int newh;
	int bound=1999;
	for(int dx=-1; dx<=1; dx++){
		for(int dy=-1; dy<=1; dy++){
			if(abs(dx)==abs(dy)) continue;
			int x1 = x+dx; 
			int y1 = y+dy;
			if(h[x1][y1]<=h[x][y]) {
				if(vis[x1][y1]==1) continue;
				bound = min(bound, dfs(x1, y1));
			}
			else bound = min(bound, h[x1][y1]);
		}
	}
	return max(bound, h[x][y]);
}

int main() {
	int t; scanf("%d", &t);
	int cnt=1;
	while(t--){
			printf("Case #%d: ", cnt++);
			scanf("%d%d", &r, &c);
			for(int i=0; i<r; i++){
				for(int j=0; j<c; j++){
					scanf("%d", &h[i][j]);
				}
			}
			int ans=0;
			while(1){
				int temp_ans=0;
				for(int i=0; i<r; i++){
					for(int j=0; j<c; j++){
						memset(vis, 0, sizeof vis);
						int newh = dfs(i, j);
						// cout<<newh<<" ";
						temp_ans += newh-h[i][j];
						h[i][j]=newh;
					}//cout<<endl;
				}//cout<<endl;
				ans += temp_ans;
				if(temp_ans==0) break;
			}
			printf("%d\n", ans);
	}
	return 0;	
}