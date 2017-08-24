#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int arr[3001][3001];
int tree[4*3001][4*3001];
int N;
long long A[3001], B[3001];

void build_y(int nodex, int sx, int ex, int nodey, int sy, int ey){
	if(sy == ey){
		if(sx == ex) tree[nodex][nodey] = arr[sx][sy];
		else{
			tree[nodex][nodey] = max(tree[2*nodex][nodey], tree[2*nodex+1][nodey]);
		}
		return;
	}
	int my = (sy+ey)/2;
	build_y(nodex, sx, ex, 2*nodey, sy, my);
	build_y(nodex, sx, ex, 2*nodey+1, my+1, ey);
	tree[nodex][nodey] = max(tree[nodex][2*nodey], tree[nodex][2*nodey+1]);
}

void build_x(int nodex, int sx, int ex){
	if(sx == ex){
		build_y(nodex, sx, ex, 1, 0, N-1);
		return;
	}
	int mx = (sx+ex)/2;
	build_x(2*nodex, sx, mx);
	build_x(2*nodex+1, mx+1, ex);
	build_y(nodex, sx, ex, 1, 0, N-1);
}

int query_y(int nodex, int nodey, int sy, int ey, int ly, int ry){
	if(ey<ly || sy>ry) return INT_MIN;
	if(sy>=ly && ey<=ry) return tree[nodex][nodey];
	int my = (sy+ey)/2;
	int a1 = query_y(nodex, 2*nodey, sy, my, ly, ry);
	int a2 = query_y(nodex, 2*nodey+1, my+1, ey, ly, ry);
	return max(a1,a2);
}

int query_x(int nodex, int sx, int ex, int lx, int rx, int ly, int ry){
	if(ex<lx || sx>rx) return INT_MIN;
	if(sx>=lx && ex<=rx) return query_y(nodex, 1, 0, N-1, ly, ry);
	int mx = (sx+ex)/2;
	int a1 = query_x(2*nodex, sx, mx, lx, rx, ly, ry);
	int a2 = query_x(2*nodex+1, mx+1, ex, lx, rx, ly, ry);
	return max(a1,a2);
}

int main() {
	freopen("inputf.in", "r", stdin); // redirects standard input
	freopen("outputf.in", "w", stdout); // redirects standard output

	int t; scanf("%d", &t);
	int cnt=1;
	while(t--){

   		cerr << "testCase: " << t << "\n";
		printf("Case #%d: ", cnt++);

		int k, c, x;
		scanf("%d%d%d%d", &N, &k, &c, &x);

		for(int i=0; i<N; i++) scanf("%lld", &A[i]);
		for(int i=0; i<N; i++) scanf("%lld", &B[i]);
		memset(tree, -1, sizeof tree);

		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				long long num = A[i]*(i+1) + B[j]*(j+1) + c;
				num %= x;
				arr[i][j]= num;
			}
		}

		// for(int i=0; i<N; i++){
		// 	for(int j=0; j<N; j++){
		// 		cout<<arr[i][j]<<endl;
		// 	}
		// }

		long long ans = 0;
		build_x(1, 0, N-1);

		for(int a=0; a<=N-k; a++){
			for(int b=0; b<=N-k; b++){
				int cur= query_x(1, 0, N-1, a, a+k-1, b, b+k-1);
				ans += (long long)cur;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;	
}