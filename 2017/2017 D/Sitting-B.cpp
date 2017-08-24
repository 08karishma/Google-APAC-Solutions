#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#define MAX 2001
using namespace std;

int r, c;

int helper(int i, int j, long long mask){
	if(i==r) return 0;
	int ans = (j==c-1) ? helper(i+1, 0, mask) : helper(i, j+1, mask);
	//check for (i-1, j) and (i-2, j)
	if(i>1){
		int n1 = (c*(i-1)) + j;
		int n2 = (c*(i-2)) + j;
		if((mask & (1LL<<n1)) && (mask & (1LL<<n2))) return ans;
	}
	//check for (i, j-1) and (i, j-2)
	if(j>1){
		int n1 = c*i + j-1;
		int n2 = c*i + j-2;
		if((mask & (1LL<<n1)) && (mask & (1LL<<n2))) return ans;
	}
	int n = c*i + j;
	mask |= (1LL<<n);
	int ans1 = (j==c-1) ? helper(i+1, 0, mask) : helper(i, j+1, mask);
	// cout<<i<<" "<<j<<" "<<max(ans, 1+ans1)<<endl;
	return max(ans, 1+ans1);
}

int main() {

	freopen("inputf.in", "r", stdin); // redirects standard input
	freopen("outputf.in", "w", stdout); // redirects standard output

	int t; scanf("%d", &t);	
	int cnt=1;
	while(t--){
		printf("Case #%d: ", cnt++);
		scanf("%d%d", &r, &c);

		printf("%d\n", helper(0, 0, 0));
	}
	return 0;	
}