#include <iostream>
#include <cstring>
#include <math.h>
#define MAX 21
using namespace std;

int vis[MAX][MAX];
char grid[MAX][MAX];
int R, C, Rs, Cs, S;
double P, Q;
int s;

double helper(int x, int y){
    if(s==S) return 0;
    vis[x][y]++;
    s++;
    double prob = (grid[x][y]=='.') ? Q : P;
    double ans = pow(1-prob, vis[x][y]-1)*prob;
    double temp=0;
    if(x+1<R) temp = helper(x+1, y);
    if(x-1>=0) temp = max(temp, helper(x-1, y));
    if(y+1<C) temp = max(temp, helper(x, y+1));
    if(y-1>=0) temp = max(temp, helper(x, y-1));
 
    vis[x][y]--;
    s--;
    return ans+temp;
}

int main() {    
    int t; scanf("%d", &t);
    int cnt=1;
    while(t--){
        printf("Case #%d: ", cnt++);
        scanf("%d%d%d%d%d", &R, &C, &Rs, &Cs, &S);
        scanf("%lf%lf", &P, &Q);
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                scanf(" %c", &grid[i][j]);
            }
        }

        memset(vis, 0, sizeof vis);
        s=0;
        double ans=0;
        if(Rs+1<R) ans = helper(Rs+1, Cs);
        if(Rs-1>=0) ans = max(ans, helper(Rs-1, Cs));
        if(Cs+1<C) ans = max(ans, helper(Rs, Cs+1));
        if(Cs-1>=0) ans = max(ans, helper(Rs, Cs-1));

        printf("%0.7f\n", ans);
    }
    return 0;
}