#include<bits/stdc++.h>
using namespace std;

const long long N=1e5;
const long long M=1e5;

long long h[N+5],tot;
struct edge{
	long long v,next;
}e[2*N+5];
void addedge(long long u,long long v){
	e[++tot].v=v;e[tot].next=h[u];h[u]=tot;
}

long long n;
long long a[N+5],b[N+5],c[N+5];
struct node{
	long long id,t;
}p[N+5];
long long d[N+5],growt[N+5];
long long fa[N+5],vis[N+5],maxt=0,ans=0;

void build(long long x,long long fa)
{
	d[x]=d[fa]+1;
	p[x].t=d[x]+growt[x]-1;p[x].id=x;
	for(long long i=h[x];i!=0;i=e[i].next){
		long long v=e[i].v;
		if(v!=fa){
			build(v,x);
		}
	}
}

bool cmp(node x,node y){
	return x.t>y.t;
}

void rt(long long x,long long plant)
{
	if(vis[x]==true){
		maxt=max(maxt,growt[plant]-1);
		return;
	}
	ans++;
	maxt--;
	vis[x]=true;
	rt(fa[x],plant);
}

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	bool fpartA=true;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		if(c[i]!=0) fpartA=false;
		growt[i]=(a[i]+b[i]-1)/b[i];
	}
	for(long long i=1;i<=n-1;i++){
		long long u,v;
		cin>>u>>v;
		addedge(u,v);
		addedge(v,u);
	}
	if(fpartA==true){
		build(1,0);
		for(long long u=2;u<=n;u++){
			for(long long i=h[u];i!=0;i=e[i].next){
				if(d[e[i].v]<d[u]){
					fa[u]=e[i].v; break;
				}
			}
		}
		sort(p+2,p+n+1,cmp);
		vis[1]=true;
		maxt=growt[1]-1;
		ans++;
		for(long long i=2;i<=n;i++){
			rt(p[i].id,p[i].id);
		}
		cout<<ans+maxt;
	}
	return 0;
}
