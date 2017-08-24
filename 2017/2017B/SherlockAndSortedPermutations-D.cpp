/*For each permutation, consider that you can insert a divider after position i if 
all numbers before i are smaller than i, and all numbers after position i are greater 
than i. All legal divisions into chunks are splitting numbers into groups according to 
a subset of these dividers: as we're only interested in the maximum division, we'll 
always pick them all.
Now note that within a permutation, as the number of dividers is f(n), it follows that
the number of pairs (a, b) such that 1 ≤ a, b ≤ n and a, b are both possible dividers
is exactly equal to f(n)2. Therefore, we can simply count, for each pair (a, b), in 
how many permutations it is a valid pair.
And this is easy to count: pair (a, b), a ≤ b, is valid in a! × (b - a)! × (n - b)! 
permutations. We should multiply this by 2 if a < b, because we the 
symmetric pair (b, a) is also valid.
*/

#include <iostream>
#include <cstring>
#define MAX 5001
using namespace std;

long long fact[MAX];

void findFacts(int mod){
    fact[0] = (1%mod);
    for(long long i=1; i<MAX; i++){
        fact[i] = (i%mod)*fact[i-1];
        fact[i] %= mod;
    }
}

int main() {    
    int t; scanf("%d", &t);
    int cnt=1;
    while(t--){
        printf("Case #%d: ", cnt++);
        int n, m; scanf("%d%d", &n, &m);
        findFacts(m);
        long long ans = 0;
        for(int a=1; a<=n; a++){
            for(int b=a; b<=n; b++){
                long long temp = 2*fact[a];
                temp %= m;
                temp *= fact[b-a];
                temp %= m;
                temp *= fact[n-b];
                temp %= m;
                ans += temp;
                ans %=  m;
            }
        }
        for(int a=1; a<=n; a++){
            long long temp = fact[a];
            temp %= m;
            temp *= fact[n-a];
            temp %= m;
            ans -= temp;
            while(ans<0) ans += m;
        }
        printf("%lld\n", ans);
    }
    return 0;
}