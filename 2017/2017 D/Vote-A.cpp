#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#define MAX 2001
using namespace std;

int N, M;
double dp[MAX][MAX];

double helper(int a, int b){
	if(a==N && b==M) return 1;
	if(dp[a][b]!=-1) return dp[a][b];
	double ans = 0;
	if(a<N) ans += ((double)(N-a)/(double)(N+M-a-b))*helper(a+1, b);
	if(b+1<a && b<M) ans += ((double)(M-b)/(double)(N+M-a-b))*helper(a, b+1);
	return dp[a][b]=ans;
}

int main() {
	int t; scanf("%d", &t);
	int cnt=1;
	while(t--){
		printf("Case #%d: ", cnt++);
		scanf("%d%d", &N, &M);
		for(int i=0; i<=N; i++){
			for(int j=0; j<=M; j++){
				dp[i][j]=-1;
			}
		}
		printf("%0.8f\n", helper(0,0));
	}
	return 0;	
}