#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>v[200005],v2[200005];
//2n T 2n+1 F 2n+2 U
//2i a[i+1] 2i+1 !a[i+1]
short col[200005];
// 1:F 2:T
int val[100005];
int dfn[200005],low[200005],scc[200005],dcnt,scnt;
bool in[200005];
stack<int>s;
void dfs(int now){
	dfn[now]=low[now]=++dcnt;
	in[now]=1;
	s.push(now);
	for(auto i:v[now]){
		if(!dfn[i])dfs(i),low[now]=min(low[now],low[i]);
		else if(in[i])low[now]=min(low[now],dfn[i]);
	}
	if(low[now]==dfn[now]){
		++scnt;
		while(s.top()!=now){
			scc[s.top()]=scnt;
			in[s.top()]=0;
			s.pop();
		}
		scc[now]=scnt,in[now]=0,s.pop();
	}
}
bool dfs2(int now,int c){
	if(c==col[now])return 1;
	if(col[now])return 0;
	col[now]=c;
	bool ans=1;
	for(auto i:v2[now])ans&=dfs2(i,3-c);
	return ans;
}
int cnt=0;
void paint(int now){
	if(col[now]==3)return;
	col[now]=3;++cnt;
	for(auto i:v2[now])paint(i);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _,t;cin>>_>>t;while(t--){
		cin>>n>>m;
		dcnt=scnt=0;cnt=0;
		int mx=n+n+2;
		for(int i=0;i<=mx;i++)v[i].clear(),v2[i].clear(),col[i]=dfn[i]=low[i]=0;
		for(int i=1;i<=n;i++)val[i]=(i-1)<<1;
		while(m--){
			char c;int x,y;
			cin>>c;
			if(c=='T'){
				cin>>x;
				val[x]=n<<1;
			}
			if(c=='F'){
				cin>>x;
				val[x]=n<<1|1;
			}
			if(c=='U'){
				cin>>x;
				val[x]=mx;
			}
			if(c=='+'){
				cin>>x>>y;
				val[x]=val[y];
			}
			if(c=='-'){
				cin>>x>>y;
				if(val[y]==mx)val[x]=mx;
				else val[x]=val[y]^1;
			}
		}
		for(int i=1;i<=n;i++)v[val[i]].push_back((i-1)<<1),v[(i-1)<<1].push_back(val[i]);
		for(int i=0;i<=mx;i++)if(!dfn[i])dfs(i);
		for(int i=0;i<mx;i+=2)v2[scc[i]].push_back(scc[i^1]),v2[scc[i^1]].push_back(scc[i]);
		paint(scc[mx]);
		for(int i=1;i<=scnt;i++)if(!col[i]){
			if(!dfs2(i,1))paint(i);
		}
		cout<<cnt-1<<"\n";
	}
	return 0;
}