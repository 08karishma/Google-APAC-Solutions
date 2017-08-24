#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#define f first
#define s second
#define MAX 201
using namespace std;

int sold[MAX][2]; //sold[i][0]=attack stats of i
vector<pair<int,int>> attack, defence;
int dp[MAX][MAX][2];
int n;

bool helper(int ep1, int ep2, int turn){
	//turn==0 for Alice
	if(ep1>=n && ep2>=n) return false; //no soldier to choose
	if(dp[ep1][ep2][turn]!=-1) return dp[ep1][ep2][turn];

	bool temp=true;
	for(int i=ep1; i<n && temp; i++){
		int ind = attack[i].s;
		// cout<<ind<<endl;
		pair<int, int> p=make_pair(sold[ind][0], n);
		int newep1 = upper_bound(attack.begin(), attack.end(), p)-attack.begin();
		p.f = sold[ind][1];
		int newep2 = upper_bound(defence.begin(), defence.end(), p)-defence.begin();
		temp = helper(newep1, max(newep2, ep2), turn^1);
	}
	for(int i=ep2; i<n && temp; i++){
		int ind = defence[i].s;
		pair<int, int> p=make_pair(sold[ind][0], n);
		int newep1 = upper_bound(attack.begin(), attack.end(), p)-attack.begin();
		p.f = sold[ind][1];
		int newep2 = upper_bound(defence.begin(), defence.end(), p)-defence.begin();
		temp = helper(max(newep1, ep1), newep2, turn^1);
	}
	return dp[ep1][ep2][turn] = (!temp);
}

int main() {
	int t; scanf("%d", &t);
	int cnt=1;
	while(t--){
		printf("Case #%d: ", cnt++);

		attack.clear();
		defence.clear();
		memset(dp, -1, sizeof dp);

		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%d%d", &sold[i][0], &sold[i][1]);
			attack.push_back({sold[i][0], i});
			defence.push_back({sold[i][1], i});
		}
		sort(attack.begin(), attack.end());
		sort(defence.begin(), defence.end());

		bool ans = helper(0, 0, 0);
		if(ans) printf("YES\n");
		else printf("NO\n");

	}
	return 0;	
}