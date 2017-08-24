#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define f first
#define s second
using namespace std;
#define N 500001

struct mark{
  int val, type, ind;
};

long long x[N], y[N];
vector<mark> all;
int non_overlap[N];
unordered_map<int,int> mp;

bool comp(mark m1, mark m2){
	if(m1.val == m2.val && m1.type == m2.type) return m1.ind < m2.ind;
	if(m1.val == m2.val) return m1.type < m2.type;
	return m1.val < m2.val;
}

int main() {  
    int t; scanf("%d", &t);
    int cnt=1;
    while(t--){
        printf("Case #%d: ", cnt++);
        int n;
        long long L1, R1, A, B, C1, C2, M;
        scanf("%d%lld%lld%lld%lld%lld%lld%lld", &n, &L1, &R1, &A, &B, &C1, &C2, &M);
        x[0]=L1; y[0]=R1;
        for(int i=1; i<n; i++){
            x[i] = A*x[i-1]+B*y[i-1]+C1;
            x[i]%=M;
            y[i] = A*y[i-1]+B*x[i-1]+C2;
            y[i]%=M;
        }
        // cin>>n;
        all.clear();
        int total = 0;
      	mark m;	
        for(int i=0; i<n; i++){
			non_overlap[i]=0;
			//left
			m.val = min(x[i], y[i]);
			m.type = 1;
			m.ind = i;
			all.push_back(m);
			//right
			m.val = max(x[i], y[i])+1;
			m.type = 0;
			m.ind = i;
			all.push_back(m);
        }
        sort(all.begin(), all.end(), comp);

        mp.clear();
        int start_val=-1;
        for(int i=0; i<all.size(); i++){
        	if(mp.size()==0) start_val = all[i].val;
        	if(all[i].type == 0) mp.erase(all[i].ind);
        	else mp[all[i].ind]=1;
        	if(i!=all.size()-1 && all[i].type == all[i+1].type && all[i].val == all[i+1].val) 
        		continue;
        	if(mp.size()==1){
        		non_overlap[mp.begin()->first] += (all[i+1].val - all[i].val);
        	}
        	if(mp.size()==0) {
        		total += all[i].val-start_val;
        	}
        }

        int maxm=-1;
        for(int i=0; i<n; i++){
        	maxm = max(maxm, non_overlap[i]);
        }
        printf("%d\n", total-maxm);
    }
    return 0;
}