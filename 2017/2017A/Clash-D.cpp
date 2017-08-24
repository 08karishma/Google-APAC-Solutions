#include <bits/stdc++.h>
 
#define icin(x) scanf("%d",&x)
#define lcin(x) scanf("%lld",&x)
#define pb push_back
#define LL long long
#define F first
#define S second
#define eps ((double)1e-14)
#define maxn 109
#define maxm 100009
#define bc(x) __builtin_popcount(x);
 
using namespace std;
 
 
LL mus[15][15];
LL cost[15][15];
LL sum_cost[15][15];
int curl[15],maxl[15];
vector<int> idx1,idx2;
map<LL,LL> m1,m2;
LL m;
int n;
 
void f(int pos,LL cur_pow,LL cur_m,vector<int> &idx,map<LL,LL> &ma)
{
  if(cur_m>m)
    return;
  if(pos==4)
  {
    if(cur_m>m)
      return;
    if(ma.find(cur_m)==ma.end())
      ma[cur_m]=cur_pow;
    else if(cur_pow > ma[cur_m])
      ma[cur_m] = cur_pow;
    return;
  }
  int i = idx[pos];
  for(int j=curl[i];j<=maxl[i];j++)
  {
    LL mp = mus[i][j];
    LL mm = sum_cost[i][j] - sum_cost[i][curl[i]];
    f(pos+1,cur_pow+mp,cur_m+mm,idx,ma);
  }
}
 
LL meet_in_the_middle(map<LL,LL> m3, map<LL,LL> m4)
{
  LL ans = 0;
  map<LL,LL> m1,m2;
 
  LL init = (m3.begin())->F;
  LL thres = m3[init];
 
  m1[init] = thres;
 
  for(auto it:m3)
  {
    if(it.S>thres)
    {
      m1[it.F]=it.S;
      thres = it.S;
    }
  }
 
  init = (m4.begin())->F;
  thres = m4[init];
 
  m2[init] = thres;
 
  for(auto it:m4)
  {
    if(it.S>thres)
    {
      m2[it.F]=it.S;
      thres = it.S;
    }
  }
 
 
 
  for(auto it:m1)
  {
    LL cur_m = it.F,cur_pow=it.S;
    auto it2 = m2.upper_bound(m-cur_m);
 
    if(it2!=m2.begin())
    {
      it2--;
      cur_pow += it2->S;
      ans = max(ans,cur_pow);
    }
    else
      assert(0);
  }
 
  return ans;
}
 
int main()
{
  int t;
  icin(t);
  for(int tc=1;tc<=t;tc++)
  {
   
    lcin(m);
    icin(n);
 
    memset(sum_cost,0,sizeof(sum_cost));
   
    for(int i=1;i<=n;i++)
    {
      icin(maxl[i]);
      icin(curl[i]);
      for(int j=1;j<=maxl[i];j++)
        lcin(mus[i][j]);
      for(int j=2;j<=maxl[i];j++)
      {
        lcin(cost[i][j]);
        sum_cost[i][j] = sum_cost[i][j-1] + cost[i][j];
      }
    }
    LL ans = 0;
    for(int mask=1;mask<(1<<n);mask++)
    {
      int x = bc(mask);
      if( x !=8)
        continue;
 
      idx1.clear();
      idx2.clear();
      m1.clear();
      m2.clear();
     
      for(int i=0;i<n;i++)
      {
        if( (mask&(1<<i)) !=0)
        {
          if(idx1.size()<4)
            idx1.pb(i+1);
          else
            idx2.pb(i+1);
        }
      }
 
      f(0,0ll,0ll,idx1,m1);
      f(0,0ll,0ll,idx2,m2);
 
      ans = max(ans,meet_in_the_middle(m1,m2));
     
    }
    printf("Case #%d: %lld\n",tc,ans);
 
  }
}