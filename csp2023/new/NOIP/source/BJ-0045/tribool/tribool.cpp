#include <bits/stdc++.h>
#define mp make_pair
#define fir first
#define sec second
using namespace std;
const int N=1e5+10;
int T,num,n,m,u,v,vis[N],sz[N],c[N],flag;
char op[2];
pair <int,int> f[N];
vector < pair<pair<int,int>,int> > edge[N];
void dfs(int u,int lst){
	vis[u]=1;if(u<=n)sz[u]=1;
	//cout<<u<<endl;
	for(auto to:edge[u]){
		if(to.sec==lst)continue;
		int v=to.fir.fir,w=to.fir.sec;
		if(vis[v]){
			if(c[v]!=(c[u]^w))flag=1;
		}else{
			c[v]=c[u]^w;
			dfs(v,to.sec);
			sz[u]+=sz[v];
		}
	}
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n+3;i++)
		f[i]=mp(i,0);
	while(m--){
		cin>>op;
		if(op[0]=='+'){
			cin>>u>>v;
			f[u]=f[v];
		}else if(op[0]=='-'){
			cin>>u>>v;
			f[u]=f[v];
			f[u].sec^=1;
		}else{
			cin>>u;
			if(op[0]=='T'){
				f[u]=mp(n+1,0);
			}else if(op[0]=='F'){
				f[u]=mp(n+2,0);
			}else{
				f[u]=mp(n+3,0);
			}
		}
	}
	for(int i=1;i<=n+3;i++)edge[i].clear();
	for(int i=1;i<=n+3;i++){
		edge[i].push_back(mp(mp(f[i].fir,f[i].sec),i));
		edge[f[i].fir].push_back(mp(mp(i,f[i].sec),i));
	}
	flag=0;
	fill(vis,vis+n+4,0);
	fill(c,c+n+4,-1);
	fill(sz,sz+n+4,0);
	dfs(n+3,0);
	int res=sz[n+3];
	for(int i=1;i<=n+2;i++){
		if(vis[i])continue;
		flag=0;
		dfs(i,0);
		if(flag)res+=sz[i];
	}
	cout<<res<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
	cin>>num>>T;
	while(T--)solve();
    return 0;
}
