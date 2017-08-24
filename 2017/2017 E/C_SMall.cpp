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

double A, B, C;
ll N, X, K;
vector<pair<ll, double>> res;

void btrack(int i, ll cur, double prob){
    if(i>=N){
        res.push_back({cur, prob});
        return;
    }
    btrack(i+1, cur&K, prob*A);
    btrack(i+1, cur|K, prob*B);
    btrack(i+1, cur^K, prob*C);
}

int main()
{

    freopen("inputf.in", "r", stdin); // redirects standard input
    freopen("outputf.in", "w", stdout); // redirects standard output
    // std::ios::sync_with_stdio(false);
    int t; cin>>t;
    int cnt=1;
    while(t--){
        cerr<<"case "<<cnt<<endl;
        cout<<"Case #"<<cnt++<<": ";
        res.clear();

        cin>>N>>X>>K>>A>>B>>C;
        A/=100.0; B/=100.0; C/=100.0;

        btrack(0, X, 1);
        double ans = 0;
        for(int i=0; i<res.size(); i++){
            ans += ((double)(res[i].f))*res[i].s;
        }
        printf("%0.10f\n", ans);
    }
    return 0;
}
