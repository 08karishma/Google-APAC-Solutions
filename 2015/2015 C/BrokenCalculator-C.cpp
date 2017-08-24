#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

int calc[10];
long long dp[1000001];

long long dig(int n){
    if(n==0) return 1;
    int ans = 0;
    while(n>0){
        ans++; n/=10;
    }
    return (long long)ans;
}

int check(int n){
    if(n==0) return calc[0];
    while(n>0){
        if(calc[n%10]==0) return 0;
        n/=10;
    }
    return 1;
}

long long helper(int num){
    if(check(num)) {
        return dig(num)+1;
    }
    if(dp[num]!=-1) return dp[num];
    long long ans = LLONG_MAX;
    long long temp;
    for(int i=2; i<=sqrt(num); i++){
        if(num%i == 0){
            if(check(i)){
                temp = helper(num/i);       
                if(temp!=LLONG_MAX) ans = min(ans, dig(i)+1+temp);
            }
            if(num/i != i && check(num/i)){
                temp = helper(i);
                if(temp != LLONG_MAX) ans=min(ans, dig(num/i)+1+temp);
            }

        }
    }
    return dp[num]=ans;
}

int main()
{
    int t; scanf("%d", &t);
    int cnt=1;
    while(t--){
        printf("Case #%d: ", cnt++);
        for(int i=0; i<10; i++){
            scanf("%d", &calc[i]);
        }
        memset(dp, -1, sizeof dp);
        int x;
        scanf("%d", &x);
        long long ans = helper(x);
        if(ans!=LLONG_MAX)
            printf("%lld\n", ans);
        else printf("Impossible\n");
    }
    return 0;
}
