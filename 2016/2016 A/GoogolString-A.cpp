#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <math.h>
using namespace std;

int helper(long long idx, long long k){
	if(k==1) return 0;
	long long i=idx-1;
	if(k==(1LL<<i)) return 0;
	if(k<(1LL<<i)) return helper(i, k);
	else{
		k -= ((1LL<<i)+1);
		return helper(i, (1LL<<i)-1-k)^1;
	}
}

int main() {
	// freopen("inputf.in", "r", stdin); // redirects standard input
	// freopen("outputf.in", "w", stdout); // redirects standard output

	int t; scanf("%d", &t);
	int cnt=1;
	while(t--){
		printf("Case #%d: ", cnt++);
		long long k; scanf("%lld", &k);
		long long i=log2(k+1);
		if((1LL<<i) < k+1) i++;
		printf("%d\n", helper(i, k));
	}										
	return 0;	
}