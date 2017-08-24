#include <iostream>
#include <vector>
#include <cstring>
#include <math.h>
#include <unordered_map>
#include <algorithm>
#include <climits>
#define f first
#define s second
#define MAXN 15
#define MAXK 11
#define ll long long
#define INF -1e+16
#define MOD 1000000007
using namespace std;

ll dp[10001];
string W;

ll helper(int i){
    if(i==W.length()) return 1;
    ll &ans = dp[i];
    if(ans==-1){
        char c1 = W[i];
        char c2 = (i-1>=0) ? W[i-1] : c1;
        char c3 = (i+1<W.length()) ? W[i+1] : c1;
        ll n = 1;
        if(c2!=c1) n++;
        if(c3!=c1 && c3!=c2) n++;
        ans = n*helper(i+1);
        ans %= MOD;
    }
    return ans;
}

int main()
{

    freopen("inputf.in", "r", stdin); // redirects standard input
    freopen("outputf.in", "w", stdout); // redirects standard output
    std::ios::sync_with_stdio(false);
    int t; cin>>t;
    int cnt=1;
    while(t--){
        cerr<<"case "<<cnt<<endl;
        cout<<"Case #"<<cnt++<<": ";
        memset(dp, -1, sizeof dp);
        cin>>W;
        cout<<helper(0)<<endl;
    }
    return 0;
}
