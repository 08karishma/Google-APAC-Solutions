#include <iostream>
#include <vector>
#include <cstring>
#include <math.h>
#include <map>
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
map<ll, double> res;

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
        res[X]=1;

        for(int i=0; i<N; i++){
            map<ll, double> temp;
            temp.insert(res.begin(), res.end());
            res.clear();
            for(auto it = temp.begin(); it!=temp.end(); ++it){
                ll cur = (it->f);
                double prob = (it->s);
                res[cur&K] += prob*A;
                res[cur|K] += prob*B;
                res[cur^K] += prob*C;
            }
        }

        double ans = 0;
        for(auto it = res.begin(); it!=res.end(); ++it){
            ans += ((double)(it->f))*(it->s);
        }
        printf("%0.10f\n", ans);
    }
    return 0;
}
