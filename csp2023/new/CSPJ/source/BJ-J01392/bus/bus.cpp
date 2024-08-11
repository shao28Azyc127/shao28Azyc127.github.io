#include<bits/stdc++.h>
using namespace std;

const long long N=1e4;
const long long M=2e4;
const long long K=100;
const long long INF=1e9;

long long h[N+5],tot;
struct edge{
	long long v,t,next;
}e[M+5];
void addedge(long long u,long long v,long long t){
	e[++tot].v=v;e[tot].t=t;
	e[tot].next=h[u];h[u]=tot;
}

long long n,m,k;
long long f[N+5][K+5];
bool vis[N+5][K+5];
long long trf[N+5][K+5];
long long trp[N+5];

struct node{
	long long d,u,kt;
	node(long long x,long long y,long long z){
		d=x;u=y;kt=z;
	}
	bool operator < (const node &a) const
	{
		return d>a.d;
	}
};
priority_queue<node> q;

void dp()
{
	for(long long i=1;i<=n;i++){
		for(long long j=0;j<k;j++){
			f[i][j]=INF;
			trf[i][j]=INF;
		}
	}
	f[1][0]=0;
	trf[1][0]=0;
	q.push(node(0,1,0));
	while(!q.empty()){
		long long u=q.top().u,ci=q.top().kt;q.pop();
		if(vis[u][ci]==true) continue;
		vis[u][ci]=true;
		for(long long i=h[u];i!=0;i=e[i].next){
			long long v=e[i].v;
			for(long long j=0;j<k;j++){
				if(vis[v][j]==false && f[u][(j-1+k)%k]+1<f[v][j]){
					f[v][j]=f[u][(j-1+k)%k]+1;
					trf[v][j]=min(trf[v][j],trf[u][(j-1+k)%k]+1);
					trf[v][j]=max(trf[v][j],trp[v]);
					q.push(node(f[v][j],v,j));
				}
			}
		}
	}
}

int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin>>n>>m>>k;
	bool t0=true;
	for(long long i=1;i<=n;i++){
		trp[i]=INF;
	}
	for(long long i=1;i<=m;i++){
		long long u,v,t;
		scanf("%lld%lld%lld",&u,&v,&t);
		if(t!=0) t0=false;
		trp[v]=min(trp[v],t);
		addedge(u,v,t);
	}
	if(t0==true){
		dp();
		if(f[n][0]>=INF){
			cout<<"-1";
		}
		else{
			cout<<f[n][0];
		}
	}
	else{
		dp();
		if(f[n][0]>=INF){
			cout<<"-1";
		}
		else{
			cout<<(trf[n][0]+k-1)/k*k;
		}
	}
	return 0;
}
