#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int sizes[501];
int done[501];
int n;

void helper(int l, int w){
    int i=n-1;
    while(i>=0 && (done[i] || sizes[i]>l || sizes[i]>w)) i--;
    if(i<0) return;
    done[i]=1;
    helper(l-sizes[i], sizes[i]);
    helper(w-sizes[i], l);
}

int main()
{
    std::ios::sync_with_stdio(false);
    int t; cin>>t;
    int cnt=1;
    while(t--){
        int m; cin>>n>>m;
        cout<<"Case #"<<cnt++<<": ";
        for(int i=0; i<n; i++){
            int x; cin>>x;
            sizes[i]=pow(2,x);
        }
        sort(sizes, sizes+n);
        memset(done, 0, sizeof done);
        int ans=0;
        for(int i=n-1; i>=0; i--){
            if(!done[i]) {
                helper(m, m);
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}