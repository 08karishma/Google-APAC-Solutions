#include <iostream>
#include <climits>
#include <cstring>
#include <algorithm>
#define f first
#define s second
#define MAX 3001
using namespace std;

int R, C, K;
int mons[MAX][MAX];
int dp[MAX][MAX][8];

int dfs(int x, int y, int type){
	if(x<0 || y<0 || x>=R || y>=C) return 0;
	if(mons[x][y]==1) return 0;
	if(dp[x][y][type]!=-1) return dp[x][y][type];
	int ans;
	if(type==0){
		ans = 1+dfs(x-1, y, 1);
		ans = min(ans, 1+dfs(x-1, y-1, 0));
		ans = min(ans, 1+dfs(x, y-1, 7));
	}
	else if(type==1){
		ans = 1+dfs(x-1, y, 1);
	}
	else if(type==2){
		ans = 1+dfs(x-1, y, 1);
		ans = min(ans, 1+dfs(x-1, y+1, 2));
		ans = min(ans, 1+dfs(x, y+1, 3));
	}
	else if(type==3){
		ans = 1+dfs(x, y+1, 3);
	}
	else if(type==4){
		ans = 1+dfs(x+1, y, 5);
		ans = min(ans, 1+dfs(x, y+1, 3));
		ans = min(ans, 1+dfs(x+1, y+1, 4));
	}
	else if(type==5){
		ans = 1+dfs(x+1, y, 5);
	}
	else if(type==6){
		ans = 1+dfs(x+1, y, 5);
		ans = min(ans, 1+dfs(x+1, y-1, 6));
		ans = min(ans, 1+dfs(x, y-1, 7));	
	}
	else{
		ans = 1+dfs(x, y-1, 7);
	}
	return dp[x][y][type]=ans;
}

int main() {
	int t; scanf("%d", &t);
	int cnt=1;
	while(t--){
		printf("Case #%d: ", cnt++);
		scanf("%d%d%d", &R, &C, &K);
		memset(mons, 0, sizeof mons);
		while(K--){
			int x, y; scanf("%d%d", &x, &y);
			mons[x][y]=1;
		}

		memset(dp, -1, sizeof dp);
		long long sqs=0;
		//find all odd sized sqs
		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++){
				if(mons[i][j]==1) continue;

				int temp = dfs(i-1, j-1, 0);
				temp = min(temp, dfs(i-1, j, 1));
				temp = min(temp, dfs(i-1, j+1, 2));
				temp = min(temp, dfs(i, j-1, 7));
				temp = min(temp, dfs(i, j+1, 3));
				temp = min(temp, dfs(i+1, j-1, 6));
				temp = min(temp, dfs(i+1, j, 5));
				temp = min(temp, dfs(i+1, j+1, 4));

				int odd_size =1+(2*temp);
				sqs += (long long)((odd_size+1)/2);
			}
		}

		// find all even sized sqs
		for(int i=0; i<R-1; i++){
			for(int j=0; j<C-1; j++){
				if(mons[i][j]==1 || mons[i+1][j]==1 || mons[i][j+1]==1 || mons[i+1][j+1]==1)
					continue;
				int temp = dfs(i, j, 0);
				temp = min(temp, dfs(i, j+1, 2));
				temp = min(temp, dfs(i+1, j+1, 4));
				temp = min(temp, dfs(i+1, j, 6));

				int even_size = 2*(temp);
				sqs += (long long)(even_size/2);
			}
		}

		printf("%lld\n", sqs);

	}
	return 0;	
}