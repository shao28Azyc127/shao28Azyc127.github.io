//v1 35pts

#include <bits/stdc++.h>
using namespace std;
string s,t;
map<string,bool> m;

bool check(string x){
	//O(n)
	stack<int> st;
	for(int i=0;i<x.size();i++){
		if(!st.empty()&&st.top()==int(x[i]-'a')) st.pop();
		else st.push(x[i]-'a');
	}
	return st.empty();
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);

	int n,ans=0;
	cin>>n>>s;

	for(int i=2;i<=n;i+=2){
		for(int j=0;j<=n-i;j++){
			t=s.substr(j,i);
			if(i==2){
				if(t[0]==t[1]) ans++,m[t]=1;
			}else{
				if(t[0]==t[t.size()-1]&&m[t.substr(1,t.size()-2)]) ans++,m[t]=1;
				else if(check(t)) ans++,m[t]=1;
			}
		}
	}

	printf("%d",ans);
	return 0;
}