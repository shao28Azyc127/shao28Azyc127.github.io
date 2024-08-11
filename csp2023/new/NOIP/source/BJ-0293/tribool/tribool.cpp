#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=100010;
int Tid,T,n,m;
struct COMMMAND{char op;int x,y;}op[N];
bitset<(N<<1)> isu,vis;
int t,f,u;
struct DS{
	int fa[N<<1][2],sz[N<<1];
	inline void init(int mxn){
		for(int i=1;i<=mxn;i++){
			if(i<=n||i>=t)	fa[i][0]=i;
			else	fa[i][0]=i-n;
			fa[i][1]=0,sz[i]=1;
		}
		isu[u]=1;
	}
	inline void add(int x,int y,int val){
		int fx=fa[y][0];val^=fa[y][1];
		fa[x][0]=fx,fa[x][1]=val;
	}
	PII find(int x){
		if(fa[x][0]==x)	return {x,0};
		else{
			PII res=find(fa[x][0]);
			fa[x][0]=res.first,fa[x][1]^=res.second;
			return {fa[x][0],fa[x][1]};
		}
	}
	inline void merge(int x,int y,int val){
		PII resx=find(x),resy=find(y);
		int fx=resx.first,fy=resy.first;
		val^=resx.second^resy.second;
		if(fx!=fy){
			if(sz[fx]>sz[fy])	sz[fx]+=sz[fy],fa[fy][0]=fx,fa[fy][1]=val,isu[fx]=(isu[fy]?1:isu[fx]);
			else	sz[fy]+=sz[fx],fa[fx][0]=fy,fa[fx][1]=val,isu[fy]=(isu[fx]?1:isu[fy]);
		}else if(val)	isu[fx]=1;
	}
	int solve(){
		vis.reset();
		int ans=0;
		for(int i=n+1;i<=(n<<1);i++)	merge(i-n,fa[i][0],fa[i][1]);
		for(int i=1;i<=n;i++){
			int fx=find(i).first;
			if(!vis[fx]&&isu[fx])	ans+=sz[fx],vis[fx]=1;
		}
		int fx=find(u).first;
		if(!vis[fx]&&isu[fx])	ans+=sz[fx];
		return ans-1;
	}
}ds;
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>Tid>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=m;i++){
			cin>>op[i].op>>op[i].x;
			if(op[i].op=='+'||op[i].op=='-')	cin>>op[i].y;
		}
		t=n<<1|1,f=t+1,u=f+1;
		isu.reset(),ds.init(u);
		for(int i=1;i<=m;i++){
			if(op[i].op=='+')	ds.add(n+op[i].x,n+op[i].y,0);
			else if(op[i].op=='-')	ds.add(n+op[i].x,n+op[i].y,1);
			else{
				if(op[i].op=='T')	ds.add(n+op[i].x,t,0);
				else if(op[i].op=='F')	ds.add(n+op[i].x,f,0);
				else	ds.add(n+op[i].x,u,0);
			}
		}
		cout<<ds.solve()<<'\n';
	}
	return 0;
}
