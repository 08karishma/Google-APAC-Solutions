//SOURCE: https://www.linkedin.com/pulse/code-jam-round-c-apac-test-2016-ggames-yingwu-zhu
// The key here is view each permutation is at the bottom level of a full complete tree. 
// We assign node id to each elf with noOfElves-1+i for elf i in the permutation 
// (the first elf is index 0). Then elf is parent is (i-1)/2. /
// For two elves i and j, we can easily determine at which round they will probably play. 
#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;

int friends[20][20];
int N;

int meetRound(int u, int v) {
    int r = 1;
    while ((u-1)/2 != (v-1)/2) {
        r++;
        u = (u-1)/2;
        v = (v-1)/2;
    }
    return r;
}

int test(vector<int> confg){
	for(int i=0; i<confg.size(); i++){
		for(int j=0; j<confg.size(); j++){
			int p1=confg[i]; int p2 = confg[j];
			if(friends[p1][p2]!=-1) {
				if(meetRound(confg.size()+i-1, confg.size()+j-1) <= friends[p1][p2]) return 0;
			}
		}
	}
	return 1;
}

int solve(){
	vector<int> confg;
   for(int i=0; i<(1<<N); i++){
       confg.push_back(i);
    }
    do {
    	if(test(confg)==1) return 1;
    } while (next_permutation(confg.begin(), confg.end()));
	return 0;
}


// //FOR LARGE
bool ok(int mask) {
    for(int i=0; i<16; i++){
    	if ((1<<i)&mask){
    		for(int j=0; j<16; j++){
    			if (i != j && ((1<<j)&mask)){
    				if(friends[i][j]>=3) return false;
    			}
    		}
    	}
    }
    return true;
}

int helper(int mask){
	vector<int> confg;
    for(int i=0; i<16; i++){
        if ((1<<i)& mask)
            confg.push_back(i);
    }
    do {
    	if(test(confg)==1) return 1;
    } while (next_permutation(confg.begin(), confg.end()));
    return 0;
}


int solve2(){
	set<int> half;
    int MM = (1<<16) - 1; //MM-mask = (~mask)
    for(int mask=1; mask<(1<<16); mask++) {
        if (__builtin_popcount(mask) != 8 || half.count(mask))
            continue;
        if(ok(mask) && ok(~mask)){
        	half.insert(mask);
        	half.insert(~mask); //bitwise not
        }
    }
    while (!half.empty()) {
        int m1 = *half.begin();
        half.erase(half.begin());
        int m2 = ~m1;
        half.erase(m2);
        if (helper(m1) && helper(m2))
            return 1;
    }
    return 0;
}

int main() {
	freopen("inputf.in", "r", stdin); // redirects standard input
	freopen("outputf.in", "w", stdout); // redirects standard output

	int t; scanf("%d", &t);
	int cnt=1;
	while(t--){


   		cerr << "testCase: " << t << "\n";
		printf("Case #%d: ", cnt++);
		int M;
		scanf("%d%d", &N, &M);

		memset(friends, -1, sizeof friends);

		int maxmki=-1;
		while(M--){
			int ei, ki, bi; scanf("%d%d%d", &ei, &ki, &bi);
			maxmki = max(maxmki, ki);
			while(bi--){
				int f; scanf("%d", &f);
				friends[ei-1][f-1]=ki;
			}
		}

		if(maxmki>=N){
			printf("NO\n"); continue;
		}

		int ans =  (N<4) ? solve() : solve2();
		if(ans) printf("YES\n");
		else printf("NO\n");

	}
	return 0;	
}