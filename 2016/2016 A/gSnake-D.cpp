#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
#define f first
#define s second
#define pii pair<int,int>
using namespace std;

struct node{
	int x, y;
	node *next;
	node(int a, int b) : x(a), y(b), next(NULL) {};
};

node *head, *tail;
map<pii, int> occupied;
long long length;
int R, C;
int changeDir[1000001];
map<pii, int> food;

int move(int newx, int newy){
	if(occupied.find({newx, newy})!=occupied.end()){
		if(tail->x != newx || tail->y != newy) return 0;
	}
	occupied[{newx, newy}]=1;
	head->next = new node(newx, newy);
	head = head->next;
	if((newx+newy)%2!=0 && food.find({newx, newy})==food.end()) {
		food[{newx, newy}]=1;
		length+=1LL;
	}
	else{
		occupied.erase({tail->x, tail->y});
		node *next_tail=tail->next;
		tail->next = NULL;
		tail=next_tail;
	}
	return 1;
}

int move_right(){//move right by one cell, return 0 if game ends
	int newx = head->x;
	int newy = head->y+1;
	if(newy > C) newy=1;
	return move(newx, newy);
}

int move_left(){//move left by one cell, return 0 if game ends
	int newx = head->x;
	int newy = head->y-1;
	if(newy < 1) newy=C;
	return move(newx, newy);
}

int move_up(){
	int newx = head->x-1;
	int newy = head->y;
	if(newx < 1) newx=R;
	return move(newx, newy);
}

int move_down(){
	int newx = head->x+1;
	int newy = head->y;
	if(newx > R) newx=1;
	return move(newx, newy);
}

int main() {
	freopen("inputf.in", "r", stdin); // redirects standard input
	freopen("outputf.in", "w", stdout); // redirects standard output

	int t; scanf("%d", &t);
	int cnt=1;
	while(t--){

		cerr<<t<<endl;
		printf("Case #%d: ", cnt++);
		occupied.clear();
		food.clear();
		head = new node(1, 1);
		tail = head;
		length = 1;
		occupied[{1,1}]=1;
		int dir=3; //0-top 1-left 2-down 3-right

		for(int time=1; time<1000001; time++){
			changeDir[time]=-1;
		}

		int S;
		scanf("%d%d%d", &S, &R, &C);
		while(S--){
			int x; scanf("%d", &x);
			char ch; scanf(" %c", &ch);
			if(ch=='L') changeDir[x]=0;
			else changeDir[x]=1;
		}

		int temp;

		int maxLim = 1000000+100000;
		for(int time=1; time<maxLim; time++){
			// cout<<time<<" "<<head->x<<" "<<head->y<<endl;
			// cout<<time<<" "<<tail->x<<" "<<tail->y<<endl;
			if(dir==0) temp = move_up();
			else if(dir==1) temp = move_left();
			else if(dir==2) temp = move_down();
			else temp = move_right();
			if(!temp) break;
			if(time<1000001 && changeDir[time]!=-1){
				if(changeDir[time]==0){ //anti clockwise 
					dir = (dir+1)%4;
				}
				else dir = (dir+3)%4;
			}
		}
		printf("%lld\n", length);
	}										
	return 0;	
}