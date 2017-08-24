#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#define mod 1000000007
using namespace std;

unordered_map<string, long long> vocab;
unordered_map<string, long long> dp[4001];
string str;

long long helper(int i, string prev_word){

	if(i==str.length() && prev_word=="") return 1;
	if(i==str.length()) return 0;

	if(dp[i].find(prev_word)!=dp[i].end()) {
		return dp[i][prev_word];
	}

	string org_prev_word = prev_word;
	prev_word.append(1, str[i]);
	sort(prev_word.begin(), prev_word.end());

	long long ans=0;
	if(vocab.find(prev_word)!=vocab.end()){
		ans += vocab[prev_word]*helper(i+1, "");
		ans %= mod;
	}
	ans += helper(i+1, prev_word);
	ans %= mod;
	
	return dp[i][org_prev_word] = ans;
}

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
			for(int i=0; i<=str.length(); i++){
				dp[i].clear();
			}
			cout<<helper(0, "")<<" ";
		}
		cout<<endl;
	}
	return 0;	
}