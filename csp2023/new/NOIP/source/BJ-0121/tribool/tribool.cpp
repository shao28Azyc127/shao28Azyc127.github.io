#include<bits/stdc++.h>

using namespace std;
const int N=1e5+5;
struct edge{int to,nxt,w;};
struct graph{
private: int cnt;
public:
	int head[N];
	edge e[2*N];
	void init(){memset(head,0,sizeof(head));cnt=0;}
	inline void add(int x,int y,int w){e[++cnt]={y,head[x],w};head[x]=cnt;}
}g;
int n,m,f[N],w[N],ans,c[N],stk[N],cnt;
bool vis[N];
bool dfs(int x,int fa,int col){
	if(vis[x]){
		if(c[x]!=col){
			c[x]=0;
			return 1;
		}
		return 0;
	}
	stk[++cnt]=x;
	c[x]=col;
	vis[x]=1;
	bool flag=0;
	for(int i=g.head[x];i;i=g.e[i].nxt){
		int y=g.e[i].to;
		if(y==fa) continue;
		flag|=dfs(y,x,col*g.e[i].w);
	}
	if(flag) c[x]=0;
	return flag;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int C,t;
	cin>>C>>t;
	while(t--){
		g.init();
		cin>>n>>m;
		for(int i=0;i<=n;i++){
			f[i]=i;
			w[i]=1;
		}
		for(int i=1;i<=m;i++){
			char c;cin>>c;
			if(c=='T'){
				int x;cin>>x;
				f[x]=0,w[x]=1;
			}else if(c=='F'){
				int x;cin>>x;
				f[x]=0,w[x]=-1;
			}else if(c=='U'){
				int x;cin>>x;
				f[x]=0,w[x]=0;
			}else if(c=='+'){
				int x,y;cin>>x>>y;
				f[x]=f[y],w[x]=w[y];
			}else if(c=='-'){
				int x,y;cin>>x>>y;
				f[x]=f[y],w[x]=-w[y];
			}
		}
		// for(int i=0;i<=n;i++) cout<<f[i]<<" "<<w[i]<<endl;
		for(int i=1;i<=n;i++){
			g.add(i,f[i],w[i]);g.add(f[i],i,w[i]);
		}
		memset(vis,0,sizeof(vis));
		for(int i=0;i<=n;i++){
			if(!vis[i]){
				cnt=0;
				if(dfs(i,0,1)){
					while(cnt){
						c[stk[cnt--]]=0;
					}
				}
			}
		}
		// for(int i=0;i<=n;i++){
		// 	cout<<c[i]<<" ";
		// }cout<<endl;
		ans=0;
		for(int i=1;i<=n;i++){
			ans+=(c[i]==0);
		}
		cout<<ans<<endl;
	}
	return 0;
}