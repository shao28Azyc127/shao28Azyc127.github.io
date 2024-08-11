#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define REPG(i,h,x) for(int i=h[x];~i;i=edge[i].next)
#define CLR(a,x) memset(a,x,sizeof(a))
const int INF=0x3f3f3f3f;
const int G=3e5+5;
int head[G],gcnt=1;
struct Edge{int v,next,w;}edge[G];
inline void addedge(int u,int v,int w){edge[++gcnt]={v,head[u],w},head[u]=gcnt;}

const int N=3e5+5;
int T,n,m,sta[N],ans=0,in[N],ecnt,sccnt,bel[N];
bool vis[N];
pii b[N],a[N];
vector<int> scc[N];
struct ee{int u,v,w;}e[N];
inline int conv(int x,bool ed){
	if(ed) return x;
	else{
		if(x==-3) return -1;
		if(x==-1) return -3;
		if(x==-2) return -2;
	}
}
namespace Tarjan{
	int dfn[N],low[N],cnt,stk[N],top;
	bool vis[N];
	void dfs(int p){
		dfn[p]=++cnt,low[p]=dfn[p],stk[++top]=p,vis[p]=true;
		REPG(i,head,p){
			int to=edge[i].v;
			if(!dfn[to]) dfs(to),low[p]=min(low[p],low[to]);
			else if(vis[to]) low[p]=min(low[p],dfn[to]);
		}
		if(low[p]==dfn[p]){
			sccnt++;
			while(true){
				int cur=stk[top--];
				bel[cur]=sccnt,scc[sccnt].push_back(cur),vis[cur]=false;
				if(cur==p) break;
			}
		}
	}
}
inline void bfs(){
	CLR(sta,0);
	CLR(vis,false);
	queue<int> q;
	for(int i=1;i<=sccnt;i++) if(!in[i]){
		// printf("!!initial %d %d\n",i,b[i].first);
		q.push(i);
		if(b[i].first) sta[i]=b[i].first;
		else sta[i]=-3;
		// vis[i]=tre
	}
	bool flag=false;
	while(!q.empty()){
		int p=q.front();q.pop();
		REPG(i,head,p){
			int to=edge[i].v;
			if(!sta[to]) sta[to]=conv(sta[p],edge[i].w);
			else if(sta[to]!=conv(sta[p],edge[i].w)) sta[to]=-2;
			if(!--in[to]) q.push(to);
		}
	}
	for(int i=1;i<=n;i++){if(sta[i]==-2) ans+=scc[i].size();}
	// puts("");
}
vector<pii> Gr[N];
int viss[N];
bool flagg=false;
void dfs2(int p){
	vis[p]=true;
	for(auto i:Gr[p]){
		int to=i.first,w=i.second;
		if(vis[to]) continue;
		printf("!%d set U\n",to);
		dfs2(to),ans++;
	}
}
inline void bfs2(){
	queue<int> q;
	for(int i=1;i<=n;i++) if(a[i].first==-2) q.push(i);
	while(!q.empty()){
		int p=q.front();q.pop();
		for(auto i:Gr[p]){
			int to=i.first;
			if(vis[to]) continue;
			ans++,q.push(to),vis[to]=true;
		}
	}
}
set<pii> st;
inline int get(int x,int typ){
	return n*typ+x;
}
inline void solve(int id){
	CLR(head,-1),gcnt=1,CLR(edge,0),CLR(a,0),CLR(b,0),CLR(e,0),CLR(in,0);st.clear();
	CLR(sta,0),CLR(bel,0),ans=ecnt=sccnt=0;
	CLR(Tarjan::dfn,0),CLR(Tarjan::low,0),CLR(Tarjan::vis,0),CLR(Tarjan::stk,0),Tarjan::top=Tarjan::cnt=0;
	CLR(vis,0),CLR(viss,0),flagg=false;
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n*3;i++) Gr[i].clear(),scc[i].clear();
	for(int i=1;i<=m;i++){
		char op[2];int x,y;
		scanf("%s%d",op,&x);//y->x
		if(op[0]=='+') scanf("%d",&y),a[x]={y,1};
		if(op[0]=='-') scanf("%d",&y),a[x]={y,0};
		if(op[0]=='T') a[x]={-3,0};
		if(op[0]=='F') a[x]={-1,0};
		if(op[0]=='U') a[x]={-2,0};
	}
	// for(int i=1;i<=n;i++) printf(""
	// if(id!=3) return;
	for(int i=1;i<=n;i++){
		if(a[i].first>0){
			if(a[i].second==1){
				addedge(get(a[i].first,0),get(i,0),0);
				addedge(get(a[i].first,1),get(i,1),0);
				addedge(get(a[i].first,2),get(i,2),0);
			}
			if(a[i].second==0){
				addedge(get(a[i].first,0),get(i,1),0);
				addedge(get(a[i].first,1),get(i,0),0);
				addedge(get(a[i].first,2),get(i,2),0);
			}
			Gr[a[i].first].push_back({i,0});
			// if(a[i].first==i){
				// printf("self-loop %d\n",i);
				// if(a[i].second) a[i].first=-2;
				// continue;
			// }
			// addedge(a[i].first,i,a[i].second),e[++ecnt]={a[i].first,i,a[i].second};//printf("add %d %d %d\n",a[i].first,i,a[i].second);
		}else if(a[i].first==-2) ans++;
	}
	for(int i=1;i<=n*3;i++) if(!Tarjan::dfn[i]) Tarjan::dfs(i);
	for(int i=1;i<=n;i++){
		// printf("T %d F %d U %d\n",bel[get(i,0)],bel[get(i,1)],bel[get(i,2)]);
		if(bel[get(i,0)]==bel[get(i,1)]||bel[get(i,1)]==bel[get(i,2)]||bel[get(i,2)]==bel[get(i,0)]) vis[i]=true,a[i].first=-2,ans++;
	}
	// printf("%d\n",ans);
	bfs2();
	// for(int i=1;i<=n;i++) if(a[i].first==-2) dfs2(i);
	printf("%d\n",ans);
	// for(int i=1;i<=n;i++) if(!Tarjan::dfn[i]) Tarjan::dfs(i);
	// // for(int i=1;i<=n;i++) printf("%d ",bel[i]);
	// // puts("");
	// CLR(viss,-1);
	// for(int i=1;i<=sccnt;i++){
	// 	if(scc[i].size()==1){
	// 		if(a[scc[i][0]].first<0){b[i]=a[scc[i][0]];continue;}
	// 	}
	// 	for(int j=1;j<=n;j++) Gr[i].clear();
	// 	for(auto j:scc[i]) REPG(k,head,j){
	// 		int to=edge[k].v;
	// 		if(bel[to]==bel[j]) Gr[j].push_back({to,edge[k].w});
	// 	}
	// 	flagg=false;
	// 	dfs2(scc[i][0],true);
	// 	// printf("%d %d\n",scc[i].size(),flagg);
	// 	if(flagg){
	// 		// ans+=scc[i].size();
	// 		b[i].first=-2;
	// 	}
	// }
	// CLR(head,-1),gcnt=1;
	// for(int i=1;i<=m;i++){
	// 	int u=e[i].u,v=e[i].v,w=e[i].w;
	// 	if(bel[u]!=bel[v]){
	// 		// if(st.count({bel[u],bel[v]})) continue;
	// 		// st.insert({bel[u],bel[v]});
	// 		// printf("add %d %d\n",bel[u],bel[v]);
	// 		if(viss[u]==-2||viss[v]==-2||viss[u]==viss[v]) addedge(bel[u],bel[v],w),in[bel[v]]++;
	// 		else addedge(bel[u],bel[v],!w),in[bel[v]]++;
	// 	}
	// }
	// bfs();
	// printf("%d\n",ans);
	// for(int i=0;i<=sccnt;i++) scc[i].clear();
}
int main(){
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%*d%d",&T);
	for(int i=1;i<=T;i++) solve(i);
	return 0;
}