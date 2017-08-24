#include <iostream>
#include <cstring>
#include <math.h>
#include <climits>
using namespace std;

int compStr(string s1, string s2){
	//return 1 if s1 is lexicographically larger
	return s1>s2;
}

int main() {

	string temp;
	int t; getline(cin, temp);
	t=stoi(temp);

	int cnt=1;
	int alp[26];
	
	while(t--){
		cout<<"Case #"<<cnt++<<": ";
		int n; getline(cin, temp);
		n=stoi(temp);

		string str; 
		string ans; int _ans=0;
		for(int i=0; i<n; i++){
			getline(cin, str);

			for(int j=0; j<26; j++) alp[j]=0;
			for(int j=0; j<str.length(); j++){
				if(str[j]==' ') continue;
				alp[str[j]-'A']++;
			}

			int num=0;
			for(int j=0; j<26; j++){
				if(alp[j]!=0) num+=1;
			}
			if(_ans<num){
				ans=str;
				_ans = num;
			}
			else if(_ans==num){
				if(compStr(ans, str)==1){
					ans=str;
					_ans = num;
				}
			}

		}

		cout<<ans<<endl;
	}
	return 0;
}