#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#define mod 1000000007
using namespace std;

map<string, long long> vocab;
long long dp[4001];
string str;

int main() {

	std::ios::sync_with_stdio(false);

	freopen("inputf.in", "r", stdin); // redirects standard input
	freopen("outputf.in", "w", stdout); // redirects standard output

	int t; cin>>t;
	int cnt=1;
	while(t--){
		cout<<"Case #"<<cnt++<<": ";
		int v, s; cin>>v>>s;
		vocab.clear();
		// if(cnt==15) cout<<v<<" "<<s<<endl;
		while(v--){
			string temp; cin>>temp;
			// if(cnt==15) cout<<temp<<endl;
			sort(temp.begin(), temp.end());
			vocab[temp]+=1;
		}
		while(s--){
			str="";
			cin>>str;
			memset(dp, 0, sizeof dp);
			dp[str.length()]=1;
			for(int i=str.length()-1; i>=0; i--){
				dp[i]=0;
				string cur;
				int freq[26];
				memset(freq, 0, sizeof freq);
				for(int j=i; j<str.length(); j++){
					freq[str[j]-'a']++;
					cur="";
					for(int k=0; k<26; k++){
						if(freq[k]!=0) cur.append(freq[k], 'a'+k);
					}
					if(vocab.find(cur)!=vocab.end()){
						dp[i] += vocab[cur]*dp[j+1];
						dp[i] %= mod;
					}
				}	
			}
			cout<<dp[0]<<" ";
		}
		cout<<endl;
	}
	return 0;	
}