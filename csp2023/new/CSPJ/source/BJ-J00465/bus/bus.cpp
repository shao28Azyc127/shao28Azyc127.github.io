#include<bits/stdc++.h>
#define MXN 10005
#define MXM 2*MXN
#define vecll vector<long long>
using namespace std;
struct Graph{
	struct Edge{
		int to=0,w=0,nxt=0;
	}e[MXM];
	int head[MXN],cnt=0;
	void pre(){
		memset(head,0,sizeof(head));
	}
	int add(int u,int v,int w){
		e[++cnt].w=w;
		e[cnt].to=v;
		e[cnt].nxt=head[u];
		head[u]=cnt;
		return cnt;
	}
	struct Point{
		int d=0,p=0;
		bool operator<(const Point &x)const{
			return x.d<d;
		}
	};
	vector<long long> dij(int s,int mxn){
		bool vis[mxn+2];
		memset(vis,0,sizeof(vis));
		priority_queue<Point>q;
		vector<long long>dis(mxn+2,0x7ffffffffffffff);
		dis[s]=0;
		Point ins;
		ins.d=0,ins.p=s;
		q.push(ins);
		while(q.size()){
			int u=q.top().p,d=q.top().d;
			q.pop();
			if(vis[u]) continue;
			vis[u]=1;
			for(int i=head[u];i;i=e[i].nxt){
				int y=e[i].to;
				if(dis[y]>dis[u]+e[i].w){
					dis[y]=dis[u]+e[i].w;
					if(!vis[y]){
						ins.d=dis[y],ins.p=y;
						q.push(ins);
					}
				}
			}
		}
		return dis;
	}
}G;
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	G.pre();
	int n,m,u,v,w;
	double k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		G.add(u,v,1);
	}
	vector<long long>dis=G.dij(1,n);
	
	cout<<(ceil(dis[n]/k)+1)*k;
	return 0;
}
