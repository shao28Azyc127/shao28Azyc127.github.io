#include<bits/stdc++.h>
using namespace std;
struct node{int l,r;};
bool operator<(node x,node y){return x.l!=y.l?x.l<y.l:x.r>y.r;}
vector<node> v,v2,v3;
queue<node>q;
int n,f[2000005];string s;
int cnt[26];
long long ans=0;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(0);cin>>n>>s;
	s=' '+s;
	if(n>=10000){
		for(int i=1,j=1;i<=n;++i){
			j=i;
			while(s[j]==s[i])++j;
			ans+=1ll*(j-i)*(j-i)/4;
			i=j-1;
		}
		cout<<ans<<'\n';
		return 0;
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;j+=2){
			stack<int> st;
			int flag=0;
			for(int k=i;k<=j;++k){
				if(st.empty()||(st.top()!=s[k]-'a'))st.push(s[k]-'a');
				else st.pop();
			}
			if(!st.size()){++ans;}
		}
	}
	cout<<ans<<'\n';
	return 0;
}