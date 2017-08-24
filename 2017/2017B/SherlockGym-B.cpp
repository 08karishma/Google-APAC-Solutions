#include <iostream>
#include <cstring>
#define MAX 100001
#define mod 1000000007
using namespace std;

long long dp1[MAX], dp2[MAX];

/* a function to compute (a^b)%c */
long long modulo(long long a,long long b,long long c){
    long long x=1,y=a; 
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%c;
        }
        y = (y*y)%c; // squaring the base
        b /= 2;
    }
    return x%c;
}

int main() {    
    int t; scanf("%d", &t);
    int cnt=1;
    while(t--){
        printf("Case #%d: ", cnt++);
        long long a, b, n, k; scanf("%lld%lld%lld%lld", &a, &b, &n, &k);

        memset(dp1, 0, sizeof dp1);
        memset(dp2, 0, sizeof dp2);

        for(long long i=1; i<=min(k,n); i++){
            long long r = modulo(i, a, k);
            long long x= (n-i)/k;
            dp1[r] += x+1;
            dp1[r] %= mod;
        }

        for(long long j=1; j<=min(k,n); j++){
            long long r = modulo(j, b, k);
            long long x = (n-j)/k;
            dp2[r] += x+1;
            dp2[r] %= mod;
        }

        long long ans = 0;
        for(int i=0; i<k; i++){
            // cout<<dp2[k-i]<<endl;
            ans += (dp1[i]*dp2[(k-i)%k])%mod;
            ans %= mod;
        }

        // cout<<ans<<endl;

        for(long long i=1; i<=min(k,n); i++){
            long long y = (modulo(i, a, k)+modulo(i, b, k))%k;
            if(y == 0){
                ans -= ((n-i)/k + 1);
                while(ans < 0) ans += mod;
            }
        } 

        printf("%lld\n", ans);
    }
    return 0;
}