//https://www.quora.com/How-can-problem-D-Sums-of-sums-from-Round-E
//-of-the-Google-APAC-Test-2016-be-solved-for-the-large-dataset
#include <iostream>
#include <vector>
#include <cstring>
#include <math.h>
#include <map>
#include <algorithm>
#include <climits>
#define f first
#define s second
#define MAXN 200010
#define ll long long
#define INF -1e+16
#define MOD 1000000007
using namespace std;

ll N, Q;
ll arr[MAXN];
ll psum[MAXN], qsum[MAXN];

ll countSubArrays(ll sum){
    //returns number of subarrays with sum < sum
    ll ans = 0;
    ll p1=1, p2=1;
    while(p1<=N){
        p2 = max(p2, p1);
        if(p2>N || psum[p2]-psum[p1-1] >= sum) {
            //all subarrays from p1 to p2-1 has sum < this.sum
            if(p2-1 >= p1) ans += ((p2-1)-p1+1);
            p1++;
        }
        else if(psum[p2]-psum[p1-1] < sum) p2++;
    }
    return ans;
}

ll countSubArrays2(ll sum){
    //returns number of subarrays with sum = sum
    ll ans = 0;
    ll p1=1, p2=1;
    while(p1<=N){
        p2 = max(p2, p1);
        if(psum[p2]-psum[p1-1] == sum) ans += 1;
        if(p2>N || psum[p2]-psum[p1-1] >= sum) p1++;
        else if(psum[p2]-psum[p1-1] < sum) p2++;
    }
    return ans;
}

ll findSumSmallestK(ll K){
    //returns sum of K smallest subarray sums

    ll occOfS=0;
    //find Kth smallest subarray sum
    ll S=0;
    ll low=0, high=psum[N];
    while(low <= high){
        ll mid = (low+high)/2;
        ll x = countSubArrays(mid);
        // cout<<low<<" "<<mid<<" "<<high<<" "<<x<<endl;
        if(x < K) {
            ll cnt = countSubArrays2(mid);
            if(x+cnt >= K){
                occOfS = K-x;
                S=mid; break;
            }
            low = mid+1;
        }
        else if(x >= K) high = mid-1;
    }

    //S = Kth smallest subarray sum
    // we now need to find sums of all subarray sums which are <= S
    ll res = 0;
    // sums of subarray sums which are less than S
    ll p1=1, p2=1;
    while(p1<=N){
        p2 = max(p2, p1);
        if(p2>N || psum[p2]-psum[p1-1] >= S) {
            //all subarrays from p1 to p2-1 has sum < S
            if(p2-1 >= p1) {
                ll r=p2-1, l=p1;
                res += qsum[r] - qsum[l-1] - (N-r)*(psum[r] - psum[l-1]);
            }
            p1++;
        }
        else if(psum[p2]-psum[p1-1] < S) p2++;
    }
    res += occOfS*S;
    return res;
}

int main()
{

    freopen("inputf.in", "r", stdin); // redirects standard input
    freopen("outputf.in", "w", stdout); // redirects standard output
    std::ios::sync_with_stdio(false);
    int t; cin>>t;
    int cnt=1;
    while(t--){
        cerr<<"case "<<cnt<<endl;
        cout<<"Case #"<<cnt++<<":"<<endl;
        cin>>N>>Q;        
        memset(arr, 0, sizeof arr);
        memset(psum, 0, sizeof psum);
        memset(qsum, 0, sizeof qsum);
        for(ll i=1; i<=N; i++) cin>>arr[i];
        psum[0]=0; qsum[0]=0;
        for(ll i=1; i<=N; i++){
            psum[i] = psum[i-1] + arr[i];
            qsum[i] = qsum[i-1] + (N-i+1)*arr[i];
        }

        // cout<<findSumSmallestK(11)<<endl;
        while(Q--){
            ll L, R; cin>>L>>R; 
            cout<<findSumSmallestK(R) - findSumSmallestK(L-1) <<endl;
        }
        
    }
    return 0;
}
