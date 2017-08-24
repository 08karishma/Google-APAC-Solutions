#include <iostream>
#include <cstring>
#include <vector>
#define INF 1000000000000000001
using namespace std;

long long dp[101][101];
string dp_str[201][201];
int n;

long long findNum(int o, int c){
	if(o==n && c==n) return 1;
	if(dp[o][c]!=-1) return dp[o][c];
	long long ans = 0;
	if(o<n){
		ans += findNum(o+1, c);
		if(ans>INF) ans=INF;
	}
	if(c<o){
		ans += findNum(o, c+1);
		if(ans>INF) ans=INF;
	}
	return dp[o][c]=ans;
}

string helper(int o, int c, long long k){
	if(o==n && c==n) return "";
	if(dp_str[o][c]!="*") return dp_str[o][c];
	long long num = findNum(o+1, c);
	if(k<=num) return dp_str[o][c] = "("+helper(o+1, c, k);
	else return dp_str[o][c] = ")"+helper(o, c+1, k-num);
}

int main() {
	std::ios::sync_with_stdio(false);
	int cnt=1;
	int t; cin>>t;
	while(t--){
		long long k;
		cin>>n>>k;
		memset(dp, -1, sizeof dp);
		for(int i=0; i<101; i++){
			for(int j=0; j<101; j++){
				dp_str[i][j]="*";
			}
		}
		cout<<"Case #"<<cnt++<<": ";
		if(k>findNum(0,0)) cout<<"Doesn't Exist!"<<endl;
		else cout<<"("+helper(1,0,k)<<endl;
	}
	return 0;
}
