#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
#define f first
#define s second
#define pii pair<int,int>
#define mod 1000000007
using namespace std;

string s;
long long dp[51][51][51][51][51];

long long helper(int i, int a, int b, int c, int d){
	if(i==s.length() && a==c && b==d && a!=0 && b!=0) return 1;
	if(i==s.length()) return 0;

	if(dp[i][a][b][c][d]!=-1) return dp[i][a][b][c][d];

	int ans = helper(i+1, a, b, c, d);
	if(s[i]=='a'){
		if(b==0 && c==0 && d==0) {
			ans += helper(i+1, a+1, b, c, d);
			ans %= mod;
		}
		else if(a!=0 && b!=0 && a==c && b==d){
			ans += helper(i+1, 1, 0, 0, 0);
		}
	}
	else if(s[i]=='b'){
		if(a!=0 && c==0 && d==0){
			ans += helper(i+1, a, b+1, c, d);
			ans %= mod;
		}
	}
	else if(s[i]=='c'){
		if(a!=0 && b!=0 && d==0 && a!=c){
			ans += helper(i+1, a, b, c+1, d);
			ans %= mod;
		}
	}
	else{
		if(a!=0 && b!=0 && c!=0 && a==c){
			ans += helper(i+1, a, b, c, d+1);
			ans %= mod;
		}
	}
	return dp[i][a][b][c][d]=ans;
}

int main() {
	freopen("inputf.in", "r", stdin); // redirects standard input
	freopen("outputf.in", "w", stdout); // redirects standard output

	int t; scanf("%d", &t);
	int cnt=1;

	while(t--){
		// cerr<<t<<endl;
		printf("Case #%d: ", cnt++);
		cin>>s;
		memset(dp, -1, sizeof dp);
		cout<<helper(0,0,0,0,0)<<endl;
	}										
	return 0;	
}