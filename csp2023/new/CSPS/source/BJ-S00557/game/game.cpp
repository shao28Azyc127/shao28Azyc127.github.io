#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+9;
int n, s[N], cnt;
stack<int> st;
int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin>>n;
	char c = getchar();
	while(c<'a' || c>'z') c = getchar();
	for(int i=1; i<=n; ++i){
		s[i] = c - 'a';
		c = getchar();
	}
	for(int i=1; i<=n; ++i){
		for(int j=i+1; j<=n; j+=2){
			if(st.empty()){
				if(s[j-1]==s[j]) ++cnt;
				else{
					st.push(s[j-1]);
					st.push(s[j]);
				}
			}else{
				if(st.top()==s[j-1]){
					st.pop();
				}else{
					st.push(s[j-1]);
				}
				if(st.top()==s[j]){
					st.pop();
				}else{
					st.push(s[j]);
				}
				if(st.empty()) ++cnt;
			}
		}
		while(!st.empty()) st.pop();
	}
	cout<<cnt;
	return 0;
}
