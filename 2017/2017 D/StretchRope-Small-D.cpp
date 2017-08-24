#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#define INF LLONG_MAX
using namespace std;

int N, M, L;
int B[1001], A[1001];
long long P[1001], dp[1001][10001];

long long helper(int i, int l){
	if(i==N) return INF;
	if(dp[i][l]!=-1) return dp[i][l];
	long long ans = helper(i+1, l);
	if(A[i]>l) return dp[i][l]=ans;
	if(A[i]<=l && B[i]>=l) return dp[i][l]=min(ans, P[i]);
	for(int j=A[i]; j<=B[i]; j++){
		long long x=helper(i+1, l-j);
		if(x!=INF) ans = min(ans, P[i]+x);
	}
	return dp[i][l]=ans;
}	

int main() {
	freopen("inputf.in", "r", stdin); // redirects standard input
	freopen("outputf.in", "w", stdout); // redirects standard output

	int t; scanf("%d", &t);
	int cnt=1;
	while(t--){

    cerr << "testCase: " << t << "\n";
		printf("Case #%d: ", cnt++);
		scanf("%d%d%d", &N, &M, &L);
		for(int i=0; i<N; i++){
			scanf("%d", &A[i]);
			scanf("%d", &B[i]);
			scanf("%lld", &P[i]);
		}
		memset(dp, -1, sizeof dp);
		long long ans = helper(0, L);
		if(ans > M) printf("IMPOSSIBLE\n");
		else printf("%lld\n", ans);
	}
	return 0;	
}