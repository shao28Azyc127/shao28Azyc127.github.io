#include<bits/stdc++.h>
using namespace std;
stack<char> q;
stack<char> c;
string s;
bool bu(int x,int y){
	while(!q.empty()){
		q.pop();
	}
	for(int i=x;i<=y;i++){
		if(s[i]==q.top())q.pop();
		else q.push(s[i]);
	}
	
	for(i=1;i<=y;i++){
		if(q.top()==c.top()){
			q.pop();
			c.pop();
		}else{
			c.push(q.top());
			q.pop();
		}
	}
	if(q.empty())return 1;
	else return 0;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,i,cnt=0,j;
	cin>>n;
	cin>>s;
	for(i=0;i<s.size();i++){
		for(j=i+1;j<s.size();j++){
			if(bu(i,j))cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
