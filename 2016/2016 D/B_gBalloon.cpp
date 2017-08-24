#include <iostream>
#include <vector>
#include <cstring>
#include <math.h>
#include <climits>
using namespace std;

int mod(int n){
    if(n<0) return -n;
    return n;
}

int N, M;
int heights[101], x[101];
int vel[1001];
int dp[101][10001];

int helper(int cur, int energy){
    if(cur==N) return 0;

    if(dp[cur][energy]!=-1) return dp[cur][energy];

    int ans = INT_MAX;
    for(int h=0; h<M; h++){
        if(vel[h]==0) continue;
        if(x[cur]>0 && vel[h]>0) continue;
        if(x[cur]<0 && vel[h]<0) continue;

        int temp = mod(h-heights[cur]);
        if(temp>energy) continue;
        int temp_ans = helper(cur+1, energy-temp);

        if(temp_ans!=INT_MAX){
            int cur_time = ceil((double)mod(x[cur])/mod(vel[h]));
            ans = min(ans, max(cur_time, temp_ans));
        }
    }
    return dp[cur][energy] = ans;
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
        int Q;
        cin>>N>>M>>Q;
        for(int i=0; i<M; i++) cin>>vel[i];
        for(int i=0; i<N; i++) cin>>x[i]>>heights[i];

        int ans = helper(0, Q);
        if(ans==INT_MAX) cout<<"IMPOSSIBLE"<<endl;
        else cout<<ans<<endl;
    }

    return 0;
}
    