#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int rows[100001];
double wine[401][100001];

int upperLimit(int row){
    return (row*(row+1))/2;
}

int lowerLimit(int row){
    return (row*(row-1))/2 + 1;
}

int findRow(int n){
    if(rows[n]!=-1) return rows[n];
    int low=1, high=400;
    while(low<=high){
        int mid = (low+high)/2;
        if(upperLimit(mid)<n) low=mid+1;
        else if(lowerLimit(mid)>n) high = mid-1;
        else return rows[n] = mid;
    }
    return rows[n] = low;
}

int main()
{
    int t; scanf("%d", &t);
    int cnt=1;
    memset(rows, -1, sizeof rows);
    while(t--){
        double b; int level, number; scanf("%lf%d%d", &b, &level, &number);
        printf("Case #%d: ", cnt++);
    
        wine[1][1] = 750.0*b;
        for(int l=2; l<=level; l++){
            for(int n=1; n<=(l*(l+1))/2; n++){
                int j = findRow(n);
                double extra;
                wine[l][n]=0;
                if(n<=((l-1)*(l))/2 && wine[l-1][n]>250){
                    extra = wine[l-1][n]-250;
                    wine[l][n] += extra/3.0;
                }
                int idx1 = n-(j-1);
                if(idx1>=lowerLimit(j-1) && idx1<=upperLimit(j-1) && wine[l-1][idx1]>250){
                    extra = wine[l-1][idx1]-250;
                    wine[l][n] += extra/3.0;
                }
                idx1 = n-1-(j-1);
                if(idx1>=lowerLimit(j-1) && idx1<=upperLimit(j-1) && wine[l-1][idx1]>250){
                    extra = wine[l-1][idx1]-250;
                    wine[l][n] += extra/3.0;
                }
                // if(cnt==8 && l==4) cout<<n<<" "<<n-(j-1)<<" "<<n-(j-1)-1<<endl;
            }
        }
        // for(int l=1; l<=level; l++){
        //     for(int n=1; n<=(l*(l+1))/2; n++){
        //         cout<<wine[l][n]<<endl;
        //     }cout<<endl;
        // }
        double ans = wine[level][number];
        if(ans>250) ans=250;
        printf("%0.7f\n", ans);
    }
    return 0;
}