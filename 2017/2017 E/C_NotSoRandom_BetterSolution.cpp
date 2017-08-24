#include <iostream>
using namespace std;
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <set>
#include <ctime>
#include <stack>
#include <list>
#include <cassert>
#include <iomanip>
#include <deque>
#include <sstream>
#include <fstream>
typedef pair<int,int> pii;
#define rep(i,j,n) for(i=j;i<n;i++)
#define pb push_back
#define ff first
#define ss second 
#define lli long long int
#define get getchar

inline int scan() {
    int n=0,s=1;
    char p=get();
    if(p=='-')  s=-1;
    while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
    if(p=='-') s=-1,p=get();
    while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
    return n*s;
}
lli mod = 1e9 + 7;
const int maxn = 1e5 + 100;
const int LOG = 31;
long double dp[maxn][LOG][2];
int main() {
        
    ios::sync_with_stdio(false);
    
    freopen ("inp.txt","r",stdin);
    freopen ("out.txt","w",stdout);
    cout << fixed << setprecision(10);
    int t; cin >> t;
    int ca = 0;
    while (t--) {
        ca++;
        lli n,x,k;
        long double a,b,c;
        cin >> n >> x >> k >> a >> b >> c;
        for (int i = 0; i < maxn; i++)
            for (int j = 0; j < LOG; j++)
                dp[i][j][0] = dp[i][j][1] = 0;

        for (int i = 0; i < LOG; i++)
            if (x&(1ll<<i))
                dp[0][i][1] = 1;
            else
                dp[0][i][0] = 1;

        long double ans = 0;
        for (int i = 0; i < LOG; i++) {
            for (int id = 0; id < n; id++) {
                for (int j = 0; j < 2; j++) {
                    if (k&(1ll<<i)) {
                        if (j) {
                            dp[id+1][i][1] += a*dp[id][i][1]/100.0;
                            dp[id+1][i][1] += b*dp[id][i][1]/100.0;
                            dp[id+1][i][0] += c*dp[id][i][1]/100.0;
                        } else {
                            dp[id+1][i][0] += a*dp[id][i][0]/100.0;
                            dp[id+1][i][1] += b*dp[id][i][0]/100.0;
                            dp[id+1][i][1] += c*dp[id][i][0]/100.0;
                        }
                    } else {
                        if (j) {
                            dp[id+1][i][0] += a*dp[id][i][1]/100.0;
                            dp[id+1][i][1] += b*dp[id][i][1]/100.0;
                            dp[id+1][i][1] += c*dp[id][i][1]/100.0;
                        } else {
                            dp[id+1][i][0] += a*dp[id][i][0]/100.0;
                            dp[id+1][i][0] += b*dp[id][i][0]/100.0;
                            dp[id+1][i][0] += c*dp[id][i][0]/100.0;
                        }

                    }

                }
            }
        }

        for (int i = 0; i < LOG; i++) {
            lli gg = 1ll<<i;
            long double g = gg;
            ans = ans + dp[n][i][1]*g;
        }

        cout << "Case #" << ca << ": " << ans << endl;
    }


    
    return 0;
        
}