#include <iostream>
#include <vector>
#include <cstring>
#include <math.h>
#include <unordered_map>
#include <algorithm>
#include <climits>
#define f first
#define s second
using namespace std;

struct node{
    node *left, *right; //left=>0
    int isLeaf;
    node () : isLeaf(0), left(NULL), right(NULL) {}
};

void insert_(string s, node* root){
    node *cur = root;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='0'){
            if(!cur->left) cur->left = new node();
            cur = cur->left;
        }
        else{
            if(!cur->right) cur->right = new node();
            cur = cur->right;
        }
    }
    cur->isLeaf = 1;
}

void dfs(node *cur){
    if(!cur) return;
    if(cur->isLeaf){
        cur->left = NULL;
        cur->right = NULL;
        return;
    }
    dfs(cur->left);
    dfs(cur->right);
    if(cur->left && cur->right && cur->left->isLeaf && cur->right->isLeaf){
        cur->isLeaf=1;
        cur->left = NULL;
        cur->right = NULL;
    }
}

void btrack(node *cur, int val, string &temp, vector<string> &ans){
    if(!cur) return;
    if(val!=-1) temp.push_back(val + '0');
    if(cur->isLeaf) ans.push_back(temp);
    btrack(cur->left, 0, temp, ans);
    btrack(cur->right, 1, temp, ans);
    temp.pop_back();
}

string dec2bin(int n){
    string s="";
    for(int i=7; i>=0; i--){
        if( n & (1<<i) ) s.push_back('1');
        else s.push_back('0');
    }
    return s;
}

int bin2dec(string s){
    int n = s.length();
    int ans = 0;
    for(int i=0; i<n; i++){
        if(s[n-1-i]=='1') ans += (1<<i);
    }
    return ans;
}

string convert_and_truncate(int n1, int n2, int n3, int n4, int p){
    string s = "";
    if(p==0) return s;
    s += dec2bin(n1);   
    if(p<=8) return s.substr(0, p);
    s += dec2bin(n2);
    if(p<=16) return s.substr(0, p);
    s += dec2bin(n3);
    if(p<=24) return s.substr(0, p);
    s += dec2bin(n4);
    return s.substr(0, p);
}

bool comp(string s1, string s2){
    int j=0, i=0;
    while(s1[i]!='.') i++;
    int n11 = stoi(s1.substr(j, i-j));
    j=i+1; i++;
    while(s1[i]!='.') i++;
    int n12 = stoi(s1.substr(j, i-j));
    j=i+1; i++;
    while(s1[i]!='.') i++;
    int n13 = stoi(s1.substr(j, i-j));
    j=i+1; i++;
    while(s1[i]!='/') i++;
    int n14 = stoi(s1.substr(j, i-j));

    j=0, i=0;
    while(s2[i]!='.') i++;
    int n21 = stoi(s2.substr(j, i-j));
    j=i+1; i++;
    while(s2[i]!='.') i++;
    int n22 = stoi(s2.substr(j, i-j));
    j=i+1; i++;
    while(s2[i]!='.') i++;
    int n23 = stoi(s2.substr(j, i-j));
    j=i+1; i++;
    while(s2[i]!='/') i++;
    int n24 = stoi(s2.substr(j, i-j));

    if(n11 != n21) return n11<n21;
    if(n12 != n22) return n12<n22;
    if(n13 != n23) return n13<n23;
    if(n14 != n24) return n14<n24;
    return false;
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
        cout<<"Case #"<<cnt++<<": "<<endl;

        node *root = new node();
        int n; cin>>n;  
        for(int x=0; x<n; x++){

            string s; cin>>s;
            int j=0, i=0;
            while(s[i]!='.') i++;
            int n1 = stoi(s.substr(j, i-j));
            j=i+1; i++;
            while(s[i]!='.') i++;
            int n2 = stoi(s.substr(j, i-j));
            j=i+1; i++;
            while(s[i]!='.') i++;
            int n3 = stoi(s.substr(j, i-j));
            j=i+1; i++;
            while(s[i]!='/') i++;
            int n4 = stoi(s.substr(j, i-j));
            int p = stoi(s.substr(i+1, s.length()-i-1));

            string trunc = convert_and_truncate(n1, n2, n3, n4, p);
            insert_(trunc, root);
        }

        // cout<<endl;
        dfs(root);

        vector<string> ans;
        string cur="";
        btrack(root, -1, cur, ans);

        // for(int i=0; i<ans.size(); i++){
        //     cout<<ans[i]<<" "<<endl;
        // }

        vector<string> res;
        for(int i=0; i<ans.size(); i++){

            int p = ans[i].length();
            if(p<32) ans[i].append(32-p, '0');

            string normal = "";
            for(int it=0; it<4; it++){
                int num = bin2dec(ans[i].substr(8*it, 8));
                normal += to_string(num);
                if(it<3) normal += ".";
            }
            normal += "/";
            normal += to_string(p);

            res.push_back(normal);
        }

        sort(res.begin(), res.end(), comp);
        for(int i=0; i<res.size(); i++){
            cout<<res[i]<<endl;
        }
    }

    return 0;
}
    