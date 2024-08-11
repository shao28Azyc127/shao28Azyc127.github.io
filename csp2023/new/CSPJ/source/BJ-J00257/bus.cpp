//lxy qwq
//Csp-s Rp++
#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define WA cerr<<"QWQ\n"
#define INF 0x3f3f3f3f
#define H cout<<"\n"
#define C continue
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define Rof(i,a,b) for(int i=(b);i>=(a);i--)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(b);i>(a);i--)
#define MAXN 200019
#define pb push_back
#define ull unsigned long long
int n,m,k;
vector<int> pq[MAXN];
int dis[MAXN];
struct lxy {
 int pos,val;
 bool operator <(const lxy &x) const &
 { return x.val<val; }  };
priority_queue<lxy> q;
bool vv[MAXN];
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,m) { int u,v,w; cin>>u>>v>>w; pq[u].pb(v); pq[v].pb(u); }
	memset(dis,INF,sizeof(dis));
	dis[1]=0;
	q.push(lxy{1,0});
	while(!q.empty())
	{
		int p=q.top().pos;
		q.pop();
		if(vv[p]) C;
		vv[p]=1;
		for(auto i:pq[p])
		{
			if(dis[p]+1<dis[i])
			{
				dis[i]=dis[p]+1;
				q.push(lxy{i,dis[i]});
			}
		}
	}
	cout<<dis[n];
	return 0;
}