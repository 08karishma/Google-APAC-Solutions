//assuming max no of players will be seated if the arrangement is-
//PP_PP_PP_PP_PP_PP....
//_PP_PP_PP_PP_PP_P....
//P_PP_PP_PP_PP_PP_....

#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

int helper(int r, int c){
	int a1, a2, a3;

	if(c%3==0){
		a1 = 2*(c/3);
		a2 = a1; a3 = a1;
	}
	else if(c%3==1){
		a1 = 2*((c+2)/3)-1;
		a2 = 2*((c+2)/3)-2;
		a3 = 2*((c+2)/3)-1;
	}
	else{
		a1 = 2*((c+1)/3);
		a2 = 2*((c+1)/3)-1;
		a3 = 2*((c+1)/3)-1;
	}

	if(r==1 || r==2){
		return r*a1;
	}

	int ans = (r/3)*(a1+a2+a3);
	if(r%3==1) ans += a1;
	else if(r%3==2) ans += (a1+a2);
	return ans;
}

int main() {

	freopen("inputf.in", "r", stdin); // redirects standard input
	freopen("outputf.in", "w", stdout); // redirects standard output

	int t; scanf("%d", &t);	
	int cnt=1;
	while(t--){
		printf("Case #%d: ", cnt++);
		int r,c;
		scanf("%d%d", &r, &c);

		int ans = max(helper(r,c), helper(c,r));
		printf("%d\n", ans);
	}
	return 0;	
}