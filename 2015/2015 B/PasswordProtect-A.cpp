#include<iostream>
#include <cstring>
#include <math.h>
#define MAX 101
using namespace std;

const long long mod = 1000000007;
long long fact[MAX];

/* This function calculates (a^b)%c */
long long moduloPower(int a,int b,int c){
    long long x=1,y=a; // long long is taken to avoid overflow of intermediate results
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%c;
        }
        y = (y*y)%c; // squaring the base
        b /= 2;
    }
    return x%c;
}

void findAllFacts(){
	fact[0]=1;
	for(long long i=1; i<MAX; i++) {
			fact[i] = (fact[i-1]%mod)*(i%mod);
			fact[i]%=mod;
	}
}

long long ncr(int n, int r){
	long long ans = fact[n];
	ans *= moduloPower(fact[n-r], mod-2, mod);
	ans %= mod;
	ans *= moduloPower(fact[r], mod-2, mod);
	ans %= mod;
	return ans;
}

int main(){
	int t; scanf("%d", &t);
	int cnt=1;
	findAllFacts();
	while(t--){
			int m, n; scanf("%d%d", &m, &n);
			long long ans=0;
			for(int k=0; k<m; k++){
				long long temp = ncr(m, k);
				temp *= moduloPower(m-k, n, mod);
				temp%=mod;
				if(k%2==0) ans+=temp;
				else ans-=temp;
				while(ans<0) ans+=mod;
				ans %= mod;
			}
			printf("Case #%d: %lld\n", cnt++, ans%mod);		
	}
	return 0;
}