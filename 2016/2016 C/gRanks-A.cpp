#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<string, vector<long long>> mp;
long long S[101];

int main() {
	freopen("inputf.in", "r", stdin); // redirects standard input
	freopen("outputf.in", "w", stdout); // redirects standard output

	int t; scanf("%d", &t);
	int cnt=1;
	while(t--){

   		// cerr << "testCase: " << t << "\n";
		printf("Case #%d:\n", cnt++);
		mp.clear();
		int P; scanf("%d", &P);
		for(int i=0; i<P; i++){
			scanf("%lld", &S[i]);
		}
		int N; scanf("%d", &N);
		for(int i=0; i<N; i++){
			long long W; scanf("%lld", &W);
			for(int j=0; j<P; j++){
				string s; cin>>s;
				mp[s].push_back(S[j]*W);
			}
		}
		int M; scanf("%d", &M);
		vector<pair<long long, string>> players;
		unordered_map<string, vector<long long>>::iterator it;

		for(it=mp.begin(); it!=mp.end(); it++){
			long long pts=0;
			sort((it->second).begin(), (it->second).end());
			int count=0;
			for(int i=(it->second).size()-1; i>=0 && count<M; i--){
				pts += (it->second)[i]; count++;
			}
			// cout<<pts<<" "<<(it->first)<<endl;
			players.push_back({-pts, (it->first)});
		}

		sort(players.begin(), players.end());
		int rank=1;
		for(int i=0; i<players.size(); i++){
			if(i!=0 && players[i].first!=players[i-1].first) rank=(i+1);
			printf("%d: ", rank);
			cout<<players[i].second<<endl;
		}
	}
	return 0;	
}