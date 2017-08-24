#include <iostream>
#include <cstring>

using namespace std;

int main() {	
	int t; scanf("%d", &t);
	int cnt=1;
	while(t--){
		printf("Case #%d: ", cnt++);
		int l, r; scanf("%d%d", &l, &r);
    long long x=(long long)min(l,r);
    long long ans = (x*(x+1))/2;
    printf("%lld\n", ans);
	}
	return 0;
}