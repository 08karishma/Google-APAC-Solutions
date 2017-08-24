#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
	freopen("inputf.in", "r", stdin); // redirects standard input
	freopen("outputf.in", "w", stdout); // redirects standard output

	int t; scanf("%d", &t);
	int cnt=1;
	while(t--){

   		// cerr << "testCase: " << t << "\n";
		printf("Case #%d: ", cnt++);
		int N; scanf("%d", &N);

		long long left=-1; long long right=LLONG_MAX;

		int done=0;
		for(int i=0; i<N; i++){
			long long P, K; scanf("%lld%lld", &P, &K);
			if(done) continue;
			if(P==0) {
				left = max(100*K+1, left);
				continue;
			}
			else if(P==100){
				left = K; right = K; done=1;
			}
			long long l = (100*K)/(P+1) + 1;
			long long h = (100*K)/P;
			
			// cout<<low<<" "<<high<<endl;
			// cout<<l<<" "<<h<<endl;
			left = max(l, left);
			right = min(h, right);
		}

		// cout<<endl<<left<<" "<<right<<endl;
		if(left!=right) printf("-1\n");
		else printf("%lld\n", left);
	}
	return 0;	
}