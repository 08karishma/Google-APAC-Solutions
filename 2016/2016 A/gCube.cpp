#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <math.h>
using namespace std;

int main() {
	// freopen("inputf.in", "r", stdin); // redirects standard input
	// freopen("outputf.in", "w", stdout); // redirects standard output

	int t; scanf("%d", &t);
	int cnt=1;
	while(t--){

		cerr<<t<<endl;

		printf("Case #%d:\n", cnt++);
		int n, m; scanf("%d%d", &n, &m);
		double loglen[n];
		long long temp;
		scanf("%lld", &temp);
		loglen[0] = log2(temp);
		for(int i=1; i<n; i++){
			scanf("%lld", &temp);
			loglen[i] = loglen[i-1]+log2(temp);
		}
		while(m--){
			int l, r; scanf("%d%d", &l, &r);
			double logvol = (l==0) ? loglen[r] : loglen[r]-loglen[l-1];

			double loga = logvol/(r-l+1);
			double a = pow(2.0, loga);
			// cout<<vol<<endl;
			printf("%0.9f\n", a);
		}
	}										
	return 0;	
}