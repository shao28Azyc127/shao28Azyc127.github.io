#include <cstring>
#include <cstdio>
#include <queue>
#define PROBLEMNAME "bus"
#define FILEIN PROBLEMNAME ".in"
#define FILEOUT PROBLEMNAME ".out"
using namespace std;
template<typename T> inline T ReadInt(){
	char ch = getchar();
	bool sgn = false;
	while((ch < '0' || ch > '9') && ch != '-')
		ch = getchar();
	if(ch == '-') sgn = true,ch = getchar();
	T ans = 0;
	while('0' <= ch && ch <= '9'){
		ans = (ans << 3) + (ans << 1) + (ch ^ 48);
		ch = getchar();
	}
	return ans * (sgn?-1:1);
}
template<typename T> inline void WriteInt(T x){
	if(x < 0) putchar('-'),x *= -1;
	if(x >= 10) WriteInt(x / 10);
	putchar('0' + x % 10);
}
struct Edge{
	int u,v,w,nxt;
} E[20010];
int head[10010],ecnt;
inline void AddEdge(int u,int v,int w){
	E[++ ecnt].u = u,E[ecnt].v = v,E[ecnt].w = w;
	E[ecnt].nxt = head[u],head[u] = ecnt;
}
namespace Solver1{
	int _head[1000010],_ecnt;
	int dis[2000010];
	Edge _E[2000010];
	inline void _AddEdge(int u,int v){
		_E[++ _ecnt].u = u,_E[_ecnt].v = v;
		_E[_ecnt].nxt = _head[u],_head[u] = _ecnt;
	}
	inline int Run(int n,int m,int k){
		memset(dis,-1,sizeof(dis));
		for(int i = 1;i <= n;i ++)
			for(int j = head[i];j;j = E[j].nxt)
				for(int r = 0;r < k;r ++)
					_AddEdge(i + r * n,E[j].v + (r + 1) % k * n);
		queue<int> q;
		q.push(1),dis[1] = 0;
		while(q.size()){
			int u = q.front();q.pop();
			for(int i = _head[u];i;i = _E[i].nxt){
				if(dis[_E[i].v] == -1){
					dis[_E[i].v] = dis[u] + 1;
					q.push(_E[i].v);
				}
			}
		}
		return dis[n];
	}
}
namespace Solver2{
	bool nvis[10010];
	bool vis[10010];
	inline int Run(int n,int m,int k,int mw){
		int mxtm = mw + n * k * 2;
		for(int i = 0;i <= mxtm;i ++){
			if(i % k == 0) vis[1] = true;
			memset(nvis,0,sizeof(nvis));
			for(int j = 1;j <= n;j ++){
				if(!vis[j]) continue;
				for(int k = head[j];k;k = E[k].nxt)
					if(E[k].w <= i) nvis[E[k].v] = true;
			}
			if(i % k == 0 && vis[n])
				return i;
			memcpy(vis,nvis,sizeof(nvis));
		}
		return -1;
	}
}
int main(){
	freopen(FILEIN,"r",stdin);
	freopen(FILEOUT,"w",stdout);
	int n,m,k,u,v,w,mw = 0;
	n = ReadInt<int>();
	m = ReadInt<int>();
	k = ReadInt<int>();
	for(int i = 1;i <= m;i ++){
		u = ReadInt<int>();
		v = ReadInt<int>();
		w = ReadInt<int>();
		mw = max(mw,w);
		AddEdge(u,v,w);
	}
	if(mw == 0)
		WriteInt(Solver1::Run(n,m,k));
	else WriteInt(Solver2::Run(n,m,k,mw));
	return 0;
}