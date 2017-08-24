//SIMPLE BRUTE FORCE IMPLEMENTATION
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 101
#define W 101
using namespace std;


int tetris[N][W];
int filled[N];
int top_row[W];
int h, w;

int max3(int a, int b, int c){
    return max(a, max(b,c));
}

void _set(int row, int x){
    tetris[row][x]=1;
    filled[row]+=1;
    top_row[x]=row+1;
}

int fill(int type, int rotation, int x){
    int row;
    if(type==1){
        if(rotation==0 || rotation==2){
            row = max(top_row[x]-1, top_row[x+1]);
            if(row+2 >= h) return 0;
            _set(row, x+1);
            _set(row+1, x);
            _set(row+1, x+1);
            _set(row+2, x);
        }
        else{
            row = max3(top_row[x], top_row[x+1], top_row[x+2]-1);
            if(row+1 >= h) return 0;
            _set(row, x);
            _set(row, x+1);
            _set(row+1, x+1);
            _set(row+1, x+2);
        }
    }
    else if (type==2){
        if(rotation==0 || rotation==2){
            row = max(top_row[x], top_row[x+1]-1);
            if(row+2 >= h) return 0;
            _set(row, x);
            _set(row+1, x);
            _set(row+1,x+1);
            _set(row+2, x+1);
        }
        else{
            row = max3(top_row[x]-1, top_row[x+1], top_row[x+2]);
            if(row+1 >= h) return 0;
            _set(row, x+1);
            _set(row, x+2);
            _set(row+1, x);
            _set(row+1, x+1);
        }
    }
    else if(type==3){
        if(rotation==0){
            row = max(top_row[x], top_row[x+1]);
            if(row+2 >= h) return 0;
            _set(row, x);
            _set(row, x+1);
            _set(row+1, x);
            _set(row+2, x);
        }
        else if(rotation==1){
            row = max3(top_row[x], top_row[x+1], top_row[x+2]);
            if(row+1 >= h) return 0;
            _set(row, x);
            _set(row, x+1);
            _set(row, x+2);
            _set(row+1, x+2);
        }
        else if(rotation==2){
            row = max(top_row[x]-2, top_row[x+1]);
            if(row+2 >= h) return 0;
            _set(row, x+1);
            _set(row+1, x+1);
            _set(row+2, x);
            _set(row+2, x+1);
        }
        else{
            row = max3(top_row[x], top_row[x+1]-1, top_row[x+2]-1);
            if(row+1 >= h) return 0;
            _set(row, x);
            _set(row+1, x);
            _set(row+1, x+1);
            _set(row+1, x+2);
        }
    }
    else if(type==4){
        if(rotation==0){
            row = max(top_row[x], top_row[x+1]);
            if(row+2 >= h) return 0;
            _set(row, x);
            _set(row, x+1);
            _set(row+1, x+1);
            _set(row+2, x+1);
        }
        else if(rotation==1){
            row = max3(top_row[x]-1, top_row[x+1]-1, top_row[x+2]);
            if(row+1 >= h) return 0;
            _set(row, x+2);
            _set(row+1, x);
            _set(row+1, x+1);
            _set(row+1, x+2);
        }
        else if(rotation==2){
            row = max(top_row[x], top_row[x+1]-2);
            if(row+2 >= h) return 0;
            _set(row, x);
            _set(row+1, x);
            _set(row+2, x);
            _set(row+2, x+1);
        }
        else{
            row = max3(top_row[x], top_row[x+1], top_row[x+2]);
            if(row+1 >= h) return 0;
            _set(row, x);
            _set(row, x+1);
            _set(row, x+2);
            _set(row+1, x);
        }
    }
    else if(type==5){
        row = max(top_row[x], top_row[x+1]);
        if(row+1 >= h) return 0;
        _set(row, x);
        _set(row, x+1);
        _set(row+1, x);
        _set(row+1, x+1);
    }
    else if(type==6){
        if(rotation==0 || rotation==2){
            row = top_row[x];
            if(row+3 >= h) return 0;
            _set(row, x);
            _set(row+1, x);
            _set(row+2, x);
            _set(row+3, x);
        }
        else{
            row = max(top_row[x], max3(top_row[x+1], top_row[x+2], top_row[x+3]));
            if(row >= h) return 0;
            _set(row, x);
            _set(row, x+1);
            _set(row, x+2);
            _set(row, x+3);
        }
    }
    else{
        if(rotation==0){
            row = max3(top_row[x], top_row[x+1], top_row[x+2]);
            if(row+1 >= h) return 0;
            _set(row, x);
            _set(row, x+1);
            _set(row, x+2);
            _set(row+1, x+1);
        }
        else if (rotation==1){
            row = max(top_row[x]-1, top_row[x+1]);
            if(row+2 >= h) return 0;
            _set(row, x+1);
            _set(row+1, x);
            _set(row+1, x+1);
            _set(row+2, x+1);    
        }
        else if(rotation==2){
            row = max3(top_row[x]-1, top_row[x+1], top_row[x+2]-1);
            if(row+1 >= h) return 0;
            _set(row, x+1);
            _set(row+1, x);
            _set(row+1, x+1);
            _set(row+1, x+2);
        }
        else{
            row = max(top_row[x], top_row[x+1]-1);
            if(row+2 >= h) return 0;
            _set(row, x);
            _set(row+1, x);
            _set(row+1, x+1);
            _set(row+2, x);  
        }
    }
    return 1;
}

int main()
{
    int t; scanf("%d", &t);
    int cnt=1;
    while(t--){
        printf("Case #%d:\n", cnt++);
        int n; scanf("%d%d%d", &w, &h, &n);
        for(int i=0; i<h; i++){
            filled[i]=0;
            for(int j=0; j<w; j++){
                tetris[i][j]=0;
            }
        }
        for(int j=0; j<w; j++) top_row[j]=0;

        int q[n][3];
        for(int i=0; i<n; i++){
            int type, rotation, x; scanf("%d%d%d", &type, &rotation, &x);
            q[i][0]=type; q[i][1]=rotation; q[i][2]=x;
        }

        int flag=1;
        for(int i=0; i<n && flag; i++){
            flag= fill(q[i][0], q[i][1], q[i][2]);
            int j=0;
            while(j<h && flag){
                if(filled[j]==w){
                    int k=j+1;
                    int temp_j=j;
                    while(k<h && filled[k]!=0){
                        for(int j1=0; j1<w; j1++) tetris[temp_j][j1]=tetris[k][j1];
                        filled[temp_j]=filled[k];
                        temp_j++; k++;
                    }
                    for(int j1=0; j1<w; j1++) {
                        tetris[temp_j][j1]=0; filled[temp_j]=0;
                    }
                }
                else j++;
            }
            for(j=0; j<w && flag; j++){
                int j1=h-1;
                while(j1>=0 && tetris[j1][j]==0) j1--;
                j1++;
                top_row[j]=j1;
            }
        }

        if(flag==0){
            printf("Game Over!\n");
        }
        else{
            for(int i=h-1; i>=0; i--){
                if(filled[i]!=w){
                    for(int j=0; j<w; j++){
                        if(tetris[i][j]==0) printf(".");
                        else printf("x");
                    }
                    printf("\n");
                }
            }
        }
    }
    return 0;
}
