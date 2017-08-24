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
        ll N, K; cin>>N>>K;
        ll li[4][N];
        for(int j=0; j<4; j++){
            for(int i=0; i<N; i++){
                cin>>li[j][i];    
            }
        }

        ll ans = 0;

        unordered_map<ll, ll> mp1, mp2;
        for(int a=0; a<N; a++){
            mp1[K^li[0][a]] += 1LL;
        }

        for(int b=0; b<N; b++){
            for(auto it=mp1.begin(); it!= mp1.end(); it++){
                mp2[ (it->f) ^ li[1][b] ] += (it->s);
            }
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                ll x = li[2][i]^li[3][j];
                if(mp2.find(x)!=mp2.end()){
                    ans += mp2[x];
                }
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}
