#include <iostream>
#include <math.h>
using namespace std;

long double c[101];
int m;

long double func(long double x){
	long double ans = (-1)*c[0]*pow(x, m);
	for(int i=1; i<=m; i++){
			ans += c[i]*pow(x, m-i);
	}
	return ans;
}

long double bSearch(){
	long double high=2, low=0;
	while((high-low)>1e-9){
		long double x = (high+low)/2;
		long double f = func(x);
		if(f > 0) low=x;
		else if(f < 0) high=x;
		else return x;
	}
	return high;
}

int main() {
	int t; scanf("%d", &t);
	int cnt=1;
	while(t--){
			printf("Case #%d: ", cnt++);
			scanf("%d", &m);
			for(int i=0; i<=m; i++) scanf("%Lf", &c[i]);
			long double ans= bSearch();
			printf("%.12Lf\n", ans-1);
	}
	return 0;
}