#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
#define f first
#define s second
#define pii pair<int,int>
#define INF INT_MAX
using namespace std;

int isPrime[201];

void sieve(){
	memset(isPrime, 1, sizeof isPrime);
	for(int i=2; i<201; i++){
		if(isPrime[i]){
			for(int j=i*i; j<201; j+=i){
				isPrime[j]=0;
			}
		}
	}
}

int game(long long n){ 
	int digSum=0;
	long long temp=n;
	while(temp>0){
		digSum += (temp%10LL);
		temp/=10LL;
	}

	//n is gnum, player looses
	if(digSum==1 || isPrime[digSum]) return 0; 
	//prime factorize 
	temp=n;
	while(temp%2LL==0){
		temp/=2LL;
	}
	if(temp!=n && game(temp)==0) return 1;

	for(long long i=3; i<=(long long)sqrt(n); i+=2){
		long long factor=1;
		while(temp%i == 0){
			temp/=i;
			factor*=i;
		}
		if(factor!=1) if(game(n/factor)==0) return 1;
	}
	if(temp>1) {
		if(game(n/temp)==0) return 1;
	}
	return 0;
}

int main() {
	freopen("inputf.in", "r", stdin); // redirects standard input
	freopen("outputf.in", "w", stdout); // redirects standard output

	int t; scanf("%d", &t);
	int cnt=1;
	sieve();

	while(t--){
		// cerr<<t<<endl;
		printf("Case #%d: ", cnt++);
		long long N; scanf("%lld", &N);
		int ans = game(N);
		if(ans==1) printf("Laurence\n");
		else printf("Seymour\n");

	}										
	return 0;	
}