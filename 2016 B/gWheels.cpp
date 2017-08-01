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

int main() {
	freopen("inputf.in", "r", stdin); // redirects standard input
	freopen("outputf.in", "w", stdout); // redirects standard output

	int t; scanf("%d", &t);
	int cnt=1;
	while(t--){
		cerr<<t<<endl;
		printf("Case #%d:\n", cnt++);
		int Np, Ne, Nt;
		scanf("%d%d%d", &Np, &Ne, &Nt);
		long long pGears[Np], eGears[Ne], tGears[Nt];
		for(int i=0; i<Np; i++) scanf("%lld", &pGears[i]);
		for(int i=0; i<Ne; i++) scanf("%lld", &eGears[i]);
		for(int i=0; i<Nt; i++) scanf("%lld", &tGears[i]);

		map<int, int> mp1;

		int M; scanf("%d", &M);
		while(M--){
			mp1.clear(); 
			// cerr<<"1"<<endl;
			long long p, q; scanf("%lld%lld", &p, &q);
			long long gcd = __gcd(p, q);
			p/=gcd; q/=gcd;
			for(int i=0; i<Np; i++){
				for(int j=0; j<Ne; j++){
					int key = pGears[i]*eGears[j];
					// cerr<<i<<","<<j<<" ";
					mp1[key]=j;
				}
			}//cout<<endl;
			bool isPoss=false;
			for(int i=0; i<Nt; i++){
				for(int j=0; j<Ne; j++){
					long long key = p*tGears[i]*eGears[j];
					if(key%q!=0) continue;
					key /= q;
					if(mp1.find(key)!=mp1.end()){
						if(mp1[key]!=j) isPoss=true;
					}
				}
			}		
			if(isPoss) printf("Yes\n");
			else printf("No\n");
		}
	}										
	return 0;	
}