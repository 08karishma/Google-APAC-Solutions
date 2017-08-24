#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>
#include <cstring>
#define MAX 101
using namespace std;

vector<string> validStates;
string states[MAX];
int n;
unordered_map<int,int> results;
int isFine;
int ambg;

void findAllValidStates(){
    validStates.push_back("1111110");
    validStates.push_back("0110000");
    validStates.push_back("1101101");
    validStates.push_back("1111001");
    validStates.push_back("0110011");
    validStates.push_back("1011011");
    validStates.push_back("1011111");
    validStates.push_back("1110000");
    validStates.push_back("1111111");
    validStates.push_back("1111011");
}

string dec2bin(int num){
    string res="";
    for(int i=6; i>=0; i--){
        if(num>>i & 1) res.push_back('1');
        else res.push_back('0');
    }
    return res;
}

int bin2dec(string s){
    int ans=0;
    for(int i=0; i<7; i++){
        if(s[i]=='1') ans += pow(2, 6-i);
    }
    return ans;
}

void helper(int cur, int num, int isFaulty){
    if(cur==n){
        string res = validStates[num];
        for(int i=0; i<7; i++){
            if(res[i]=='1'){
                if(((isFine>>i) & 1)!=0) continue;
                else if (((isFaulty>>i) & 1)!=0) res[i]='0';
                else {
                    ambg=1;
                    return;
                }
            }
        }
        results[bin2dec(res)]=1;
        return;
    }
    int flag=1;
    for(int i=0; i<7 && flag; i++){
        if(states[cur][i] == validStates[num][i]) continue;
        else{
            if(states[cur][i]=='1') flag=0;
            else{
                if(((isFine>>i) & 1)==1) flag=0;
                else{
                    if(((isFaulty>>i) & 1) == 0)  isFaulty+= pow(2,i);
                }
            }
        }
    }
    int next_num = (num==0) ? 9:num-1;
    if(flag) helper(cur+1, next_num, isFaulty);
}

int main()
{
    std::ios::sync_with_stdio(false);
    int t; cin>>t;
    int cnt=1;
    findAllValidStates();
    while(t--){
        cin>>n;
        results.clear();
        isFine=0;
        ambg=0;
        for(int i=0; i<n; i++){
            cin>>states[i];
            for(int j=0; j<7; j++){
                if(states[i][j]=='1') {
                    if(((isFine>>j) & 1 )== 0) isFine+=pow(2,j);
                }
            }
        }  
        for(int i=0; i<10 && (ambg==0); i++){
            helper(0, i, 0);
        } 
        cout<<"Case #"<<cnt++<<": ";
        if(results.size()!=1 || ambg==1) cout<<"ERROR!"<<endl;
        else cout<<dec2bin(results.begin()->first)<<endl;
    }
    return 0;
}