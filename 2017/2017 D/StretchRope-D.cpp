#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#define INF LLONG_MAX
#define MAX 1001
#define LMAX 10001
using namespace std;

int N, M, L;
int B[MAX], A[MAX];
long long P[MAX], dp[MAX][LMAX];
long long tree[4*LMAX];
int idx;

void build(int node, int s, int e){
	if(s==e){
		tree[node] = dp[idx][s];
		return;
	}
	int m=(s+e)/2;
	build(2*node, s, m);
	build(2*node+1, m+1, e);
	tree[node] = min(tree[2*node], tree[2*node+1]);
}	

long long query(int node, int s, int e, int l, int r){
	if(e<l || s>r) return INF;
	if(s>=l && e<=r) return tree[node];
	int m=(s+e)/2;
	return min(query(2*node, s, m, l, r), query(2*node+1, m+1, e, l, r));
}

int main() {
	freopen("inputf.in", "r", stdin); // redirects standard input
	freopen("outputf.in", "w", stdout); // redirects standard output

	int t; scanf("%d", &t);
	int cnt=1;
	while(t--){

   		// cerr << "testCase: " << t << "\n";
		printf("Case #%d: ", cnt++);
		scanf("%d%d%d", &N, &M, &L);
		for(int i=0; i<N; i++){
			scanf("%d", &A[i]);
			scanf("%d", &B[i]);
			scanf("%lld", &P[i]);
		}

		for(int j=0; j<LMAX; j++) dp[N][j]=INF;
		
		for(int i=N-1; i>=0; i--){
			idx = i+1;
			build(1, 0, LMAX-1);
			for(int j=0; j<LMAX; j++){
				dp[i][j] = dp[i+1][j];
				if(A[i]<=j && B[i]>=j) dp[i][j] = min(dp[i][j], P[i]);
				else if(B[i]<j){
					// cout<<j-B[i]<<" "<<j-A[i]<<endl;
					long long x=query(1, 0, LMAX-1, j-B[i], j-A[i]);
					if(x!=INF) dp[i][j] = min(dp[i][j], P[i]+x);
				}
			}
		}

		long long ans = dp[0][L];
		if(ans > M) printf("IMPOSSIBLE\n");
		else printf("%lld\n", ans);
	}
	return 0;	
}