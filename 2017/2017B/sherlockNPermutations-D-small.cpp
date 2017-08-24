#include <iostream>
#include <cstring>
#define MAX 5001
using namespace std;

long long fact[MAX];
long long m;
long long dp[MAX][MAX];

void findFacts(){
	fact[0]=(1%m);
	for(long long i=1; i<MAX; i++){
			fact[i] = (i%m)*(fact[i-1]);
			fact[i] %= m;
	}
}

long long h1(int n){ //no of permutations of n nos with 1 bucket
	if(n==1) return 1%m;
	if(dp[n][1]!=-1) return dp[n][1];
	long long ans = 0;
	long long temp;
	for(int i=1; i<=n-1; i++){
			// ans += i*h(i)*fact[n-i-1]
			temp = i;
			temp %= m;
			temp *= h1(i);
			temp %= m;
			temp *= fact[n-1-i];
			temp %= m;
			ans += temp;
			ans %= m;
	}
	return dp[n][1]=ans;
}

long long h2(int n, int b){ //no of permutations of n nos with b buckets
	if(b==1) return h1(n);
	if(dp[n][b]!=-1) return dp[n][b];
	long long ans = 0;
	for(int i=1; i<=n-b+1; i++){
			ans += ( h1(i)*h2(n-i, b-1) )%m;
			ans %= m;
	}
	return dp[n][b]=ans;
}

int main() {

	freopen("input.txt", "r", stdin); // redirects standard input
	freopen("output.txt", "w", stdout); // redirects standard output

	int t; scanf("%d", &t);
	int cnt=1;
	while(t--){
			int n; scanf("%d%lld", &n, &m);
			printf("Case #%d: ", cnt++);
			findFacts();
			memset(dp,-1,sizeof dp);
			long long ans = 0;
			for(int i=1; i<=n; i++){
				// cout<<(i*i)*h2(n, i)<<" ";
				long long temp = i;
				temp %= m; 
				temp *= i; 
				temp %= m;
				temp *= h2(n, i); 
				temp %= m;
				ans += temp;
				ans %= m;
			}
			printf("%d\n", ans);
	}
	return 0;
}