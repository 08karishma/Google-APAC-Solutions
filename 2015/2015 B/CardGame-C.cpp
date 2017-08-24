#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
using namespace std;

int cards[101];
int dp[101][101];
int n, k;
unordered_map<int, vector<int>> occ;

int helper(int i, int j){
    if(j<i) return 0;
    if(j-i<=1) return j-i+1;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans = 1+helper(i+1, j);
    for(int iter=0; iter<(int)occ[cards[i]+k].size(); iter++){
        for(int iter1=0; iter1<(int)occ[cards[i]+k+k].size(); iter1++){
            int idx1 = occ[cards[i]+k][iter];
            int idx2 = occ[cards[i]+k+k][iter1];
            if(idx2<=idx1 || idx2>j || idx1<=i) continue;
            if(helper(i+1, idx1-1)==0 && helper(idx1+1, idx2-1)==0){
                ans = min(ans, helper(idx2+1, j));
            }
        }
    }
    return dp[i][j]=ans;
}

int main()
{
    int t; scanf("%d", &t);
    int cnt=1;
    while(t--){
        printf("Case #%d: ", cnt++);
        memset(dp, -1, sizeof dp);
        occ.clear();
        scanf("%d%d", &n, &k);
        for(int i=0; i<n; i++){
            scanf("%d", &cards[i]);
            occ[cards[i]].push_back(i);
        }
        printf("%d\n", helper(0, n-1));
    }
    return 0;
}