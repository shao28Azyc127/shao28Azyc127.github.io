#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define ll long long
using namespace std;
inline int read(){int x=1,f=0;char ch=getchar();
    while(ch<'0' && ch>'9'){if(ch=='-')x=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){f=f*10+ch-'0';ch=getchar();}
    return x*f;
}
//通过路径时:时间要>=a[i],到达终点时:时间%k==0 可选择到达时间 
/*
5 5 3
1 2 0
2 5 0
1 3 0
3 4 0
4 5 0

5 5 3
1 2 0
2 5 1
1 3 0
3 4 3
4 5 1

out:6;
*/
const int N=2e4;
struct node{
	int to,w,nxt,t;
}edge[N];int head[N],CNT=0;
#define repg(i,x) for(int i=head[x];~i;i=edge[i].nxt)
#define INF INT_MAX
void init(){memset(head,-1,sizeof(head));CNT=0;}
void add_edge(int u,int v,int t){edge[++CNT].to=v;edge[CNT].nxt=head[u];edge[CNT].t=t;edge[CNT].w=1;head[u]=CNT;}
int n,m,K,ans=INF;bool vis[N];
void dfs(int time,int dot){
	if(dot==n && (time%K==0)){
		if(ans>time){ans=time;}
		return ;
	}
	repg(i,dot){
		int to=edge[i].to;
		if(!vis[to]){
			vis[to]=1;
			dfs(time+1,to);
			vis[to]=0;
		}
	}
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    init();
	n=read(),m=read(),K=read();
	rep(i,m){
		int u=read(),v=read(),t=read();
		add_edge(u,v,t);
	}
	vis[1]=1;
	dfs(K,1);
	if(ans!=INF){
		printf("%d\n",ans);
	}else printf("-1\n");
    return 0;
}
