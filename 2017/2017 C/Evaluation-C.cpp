#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <unordered_map>
#define f first
#define s second
#define MAX 1001
using namespace std;

unordered_map<string, int> mp;
vector<int> arguments;
unordered_map<int,int> assignments;
vector<int> adj[50*MAX];
int inDeg[50*MAX];
int nv; //no of variables

int main() {
	int t; scanf("%d", &t);
	int cnt=1;
	while(t--){
		printf("Case #%d: ", cnt++);
		
		mp.clear();
		arguments.clear();
		assignments.clear();
		memset(inDeg, 0, sizeof inDeg);
		for(int i=0; i<50*MAX; i++) adj[i].clear();

		int n; scanf("%d", &n);
		int nv=0;
		while(n--){
			string s; cin>>s;
			string var1, var2;
			int i=0;
			while(s[i]!='=') i++;
			var1 = s.substr(0, i);
			if(mp.find(var1)==mp.end()) mp[var1]=nv++;
			assignments[mp[var1]]=1;
			while(s[i]!='(') i++;
			i++;
			while(i<s.length()){
				int j=i;
				while(s[i]!=',' && s[i]!=')') i++;
				var2 = s.substr(j, i-j);
				if(var2.empty()) break;
				if(mp.find(var2)==mp.end()) mp[var2]=nv++;

				arguments.push_back(mp[var2]);
				adj[mp[var2]].push_back(mp[var1]);
				inDeg[mp[var1]]+=1;

				i++;
			}
		} 

		int flag1=1;
		for(int i=0; i<arguments.size() && flag1; i++){
			if(assignments.find(arguments[i]) == assignments.end()){
				flag1=0;
			}
		}
		if(!flag1) {
			printf("BAD\n"); continue;
		}

		int removed=0;
		//topologic sort
		while(1){
			int flag=0;
			for(int i=0; i<nv; i++){
				if(inDeg[i]==0){
					for(int j=0; j<adj[i].size(); j++){
						inDeg[adj[i][j]]--;
					}
					inDeg[i]=-1;
					flag=1;
					removed++;
				}
			}
			if(flag==0) break;
			if(removed==nv) break;
		}

		if(removed==nv) printf("GOOD\n");
		else printf("BAD\n");

	}
	return 0;	
}