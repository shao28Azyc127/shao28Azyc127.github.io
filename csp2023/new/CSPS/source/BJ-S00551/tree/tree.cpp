#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

//~ bool cst;

const int N = 1e5 + 5;

struct node
{
	LL a,b,c,tim,dt;
}v[N];

struct edge
{
	int v,next;
}e[N*2];

int cnt;
int head[N];

inline void adde(int u,int v)
{
	++cnt;
	e[cnt].v = v;
	e[cnt].next = head[u];
	head[u] = cnt;
}

int n;
int deg[N];

inline void gettim(int idx)
{
	LL l = 0ll,r = 2e18;
	if(v[idx].c > 0)
	{
		while(l < r)
		{
			LL mid = (l + r) >> 1;
			if(v[idx].b + v[idx].c * mid >= 1ll)
				r = mid;
			else
				l = mid + 1ll;
		}
	}
	else if(v[idx].c < 0)
	{
		while(l < r)
		{
			LL mid = ((l + r) >> 1) + 1;
			if(v[idx].b + v[idx].c * mid >= 1ll)
				l = mid;
			else
				r = mid - 1;
		}
	}
	v[idx].tim = l;
}

inline LL getheight(int idx,int tm)
{
	if(tm <= 0)//?
		return 0;
	if(v[idx].c > 0)
	{
		if(v[idx].tim == 0)
		{
			return v[idx].b * tm + v[idx].c * (tm+1ll)*tm/2ll;
		}
		else
		{
			if(tm >= v[idx].tim)
			{
				return v[idx].tim-1ll + (tm-v[idx].tim+1ll) * (v[idx].b + v[idx].c*v[idx].tim + v[idx].b + v[idx].c*tm) /2ll;
			}
			else
			{
				return tm;
			}
		}
	}
	else if(v[idx].c == 0)
	{
		return max(v[idx].b,1ll) * tm;
	}
	else
	{
		if(v[idx].tim == 0)
		{
			return tm;
		}
		else if(tm >= v[idx].tim)
		{
			return (v[idx].b + v[idx].c*1ll + v[idx].b + v[idx].c*v[idx].tim)*(v[idx].tim)/2ll + (tm - v[idx].tim);
		}
		else
		{
			return (v[idx].b + v[idx].c*1ll + v[idx].b + v[idx].c*tm)*(tm)/2ll;
		}
	}
	return 0;
}

LL getday(int idx,int stt,int edt)
{
	return getheight(idx,edt) - getheight(idx,stt - 1);
}

vector<int> adj[(1<<20) + 5];
int tdt[(1<<20) + 5][22];
int sdt[(1<<20) + 5][22];
LL dp[(1<<20)+5];


inline bool ok(LL tm,int S = -1)
{
	if(S == -1)
	{
		for(int i = 1;i <= n;i++)
		{
			if(getday(i,v[i].dt,tm) < v[i].a)
				return false;
		}
		return true;
	}
	else
	{
		for(int i = 1;i <= n;i++)
		{
			if((S&(1<<(i-1))) == 0)
				continue;
			if(getday(i,tdt[S][i],tm) < v[i].a)
				return false;
		}
		return true;
	}
	return true;
}

inline LL check(int S = -1)
{
	LL l = 1,r = 2e9;
	while(l < r)
	{
		LL mid = (l + r) >> 1;
		LL res = ok(mid,S);
		if(res)
			r = mid;
		else
			l = mid+1;
	}
	return l;
}

void efs(int u,int fa,int tm,int cnt)
{
	if(cnt > n)
	{
		return;
	}
	v[u].dt = tm;
	for(int i = head[u];i != 0;i = e[i].next)
	{
		int v = e[i].v;
		if(v != fa)
		{
			efs(v,u,tm+1,cnt+1);
		}
	}
}

struct qn
{
	int s,tot;
};
queue<qn> q;

//~ bool ced;

string tostr(int S)
{
	string res = "";
	for(int i = 1;i <= n;i++)
		res += (char)((bool)(S&(1<<(i-1))) + '0');
	return res;
}

bool vis[N];

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	//~ cout << (&ced - &cst)/1024/1024 << "MB.\n";
	//~ bool ckA = true;
	//~ bool ckC = true;
	bool ckB = true;
	//int stv = 0;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> v[i].a >> v[i].b >> v[i].c;
		gettim(i);
		//~ if(v[i].c != 0)
		//~ {
			//~ ckA = false;
		//~ }
	}
	for(int i = 1;i <= n-1;i++)
	{
		int u,v;
		cin >> u >> v;
		if(v != u+1)
			ckB = false;
		adde(u,v);
		adde(v,u);
		deg[u]++;
		deg[v]++;
		//~ if(deg[u] > 2 || deg[v] > 2)
		//~ {
			//~ ckC = false;
		//~ }
	}
	//~ for(int i = 1;i <= n;i++)
		//~ if(deg[i] == 1)
		//~ {
			//~ stv = i;
			//~ break;
		//~ }
	LL ans = 0;
	//~ cout << "ckB:" << ckB << "\n";
	if(ckB)
	{
		efs(1,0,1,1);
		//~ cout << "stv:" << stv << "\n";
		//~ for(int i = 1;i <= n;i++)
			//~ cout << v[i].dt << " ";
		//~ cout << "\n";
		//~ for(int i = 1;i <= n;i++)
		//~ {
			//~ cout << i << "th:" << " ";
			//~ for(int j = 1;j <= 10;j++)
			//~ {
				//~ cout << getheight(i,j) << " ";
			//~ }
			//~ cout << "\n";
		//~ }
		//~ cout << "\n";
		//~ for(int i = 1;i <= n;i++)
		//~ {
			//~ cout << i << "th:" << " ";
			//~ for(int j = 1;j <= 10;j++)
			//~ {
				//~ cout 1<< getday(i,v[i].dt,j) << " ";
			//~ }
			//~ cout << "\n";
		//~ }
		//~ for(int i = 1;i <= 10;i++)
			//~ cout << ok(i) << " ";
		//~ cout << "\n";
		ans = check();
	}
	else if(n <= 20)
	{
		for(int i = 0;i < (1<<n);i++)
		{
			dp[i] = 2e18;
		}
		dp[0] = 0;
		adj[0].push_back(1);
		q.push({0,0});
		vis[0] = true;
		while(!q.empty())
		{
			qn top = q.front();
			int S = top.s;
			int tm = top.tot + 1;
			q.pop();
			vis[S] = false;
			if(S == ((1<<n)-1))
				continue;
			//~ cout << tostr(S) << "\n";
			for(int i = 0;i < (int)adj[S].size();i++)
			{
				int v = adj[S][i];
				int T = S|(1<<(v-1));
				for(int j = 1;j <= n;j++)
					tdt[T][j] = sdt[S][j];
				tdt[T][v] = tm;
				LL tres = check(T);
				//~ cout << "search:" << tostr(T) << " " << tres << " " << tm << "\n";
				if(dp[T] >= 2e18)
				{
					vector<int>().swap(adj[T]);
					for(int j = 0;j < (int)adj[S].size();j++)
						if(adj[S][j] != v)
							adj[T].push_back(adj[S][j]);
					for(int j = head[v];j != 0;j = e[j].next)
					{
						int tv = e[j].v;
						if(sdt[T][v] == 0 && tv != v)
						{
							adj[T].push_back(tv);
						}
					}
				}
				if(tres < dp[T])
				{
					dp[T] = tres;
					for(int j = 1;j <= n;j++)
						sdt[T][j] = tdt[T][j];
					if(!vis[T])
					{
						q.push({T,tm});
						vis[T] = true;
					}
					
				}
			}
			ans = dp[(1<<n)-1];
		}
	}
	else
	{
		//efs(1,0,1,1);
		//ans = check();
		ans = n;
	}
	cout << ans << "\n";
	return 0;
}
/*

*/
