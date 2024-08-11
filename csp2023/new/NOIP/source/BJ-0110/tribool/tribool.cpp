#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int n,m,res,idx,cnt;
int fa[N],h[N],ne[2*N],e[2*N],x[N],y[N],ind[N],w[2*N],sz[N];
int dep[N];
char ans[N],now[N],opt[N],ss[N];
bool tag[N],vis[N];
void add(int a,int b)
{
	e[idx] = b,ne[idx] = h[a],h[a] = idx ++;
}
void cadd(int a,int b,int s)
{
	e[idx] = b,ne[idx] = h[a],w[idx] = s,h[a] = idx ++;
}
void dfs1(int x,int root)
{
	for(int i = h[x];i != -1;i = ne[i])
	{
		int y = e[i];
		ans[y] = 'U';
		tag[y] = true;
		dfs1(y,root);
	}
}
void dfs(int f)
{
	if(f == n+1)
	{
		for(int i = 1;i <= n;++i) ss[i] = now[i];
		for(int i = 1;i <= m;++i)
		{
			if(opt[i] == 'T' || opt[i] == 'F' || opt[i] == 'U') ss[x[i]] = opt[i];
			else if(opt[i] == '+') ss[x[i]] = ss[y[i]];
			else
			{
				if(ss[y[i]] == 'T') ss[x[i]] = 'F';
				else if(ss[y[i]] == 'F') ss[x[i]] = 'T';
				else ss[x[i]] = 'U';
			}
		}
		int dd = 0;
		for(int i = 1;i <= n;++i) 
		{
			if(now[i] != ss[i]) return ;
			if(ss[i] == 'U') ++dd;
		}
		cnt = min(dd,cnt);
		return ;
	}
	now[f] = 'T';
	dfs(f+1);
	now[f] = 'F';
	dfs(f+1);
	now[f] = 'U';
	dfs(f+1);
}
void solve1()
{
	cnt = 1000000;
	cin >> n >> m;
	for(int i = 1;i <= m;++i)
	{
		cin >> opt[i];
		if(opt[i] == 'T' || opt[i] == 'F' || opt[i] == 'U') 
			cin >> x[i];
		else if(opt[i] == '+' || opt[i] == '-')
			cin >> x[i] >> y[i];
	}
	dfs(1);
	cout << cnt << '\n';
}
void solve2()
{
	idx = res = 0;
	cin >> n >> m;
	for(int i = 1;i <= n;++i) tag[i] = false,fa[i] = i,ind[i] = 0;
	memset(h,-1,sizeof(h));
	for(int i = 1;i <= m;++i)
	{
		cin >> opt[i];
		if(opt[i] == 'T' || opt[i] == 'F' || opt[i] == 'U')
		{
			cin >> x[i];
			fa[x[i]] = x[i];
			tag[x[i]] = true;
			ans[x[i]] = opt[i];
		}
		else if(opt[i] == '+')
		{
			cin >> x[i] >> y[i];
			fa[x[i]] = fa[y[i]];
			tag[x[i]] = tag[y[i]];
			if(tag[x[i]]) ans[x[i]] = ans[y[i]];
		}
	}
	for(int i = 1;i <= n;++i)
	{
		if(tag[i]) continue ;
		else if(fa[i] == i) continue ;
		add(fa[i],i);
		++ind[i];
	}
	for(int i = 1;i <= n;++i) 
		if(tag[i] && ans[i] == 'U') dfs1(i,0);
	for(int i = 1;i <= n;++i)
		if(ans[i] == 'U' && tag[i]) ++res;
	cout << res << '\n';
}
bool fid;
void dfs2(int u,int father)
{
	sz[u] = 1;
	vis[u] = true;
	for(int i = h[u];i != -1;i = ne[i])
	{
		int y = e[i];
		if(y == father) continue ;
		dfs2(y,u);
		sz[u] += sz[y];
	}
}
void dfs3(int u,int edge,int depth)
{
	sz[u] = 1;
	vis[u] = true;
	dep[u] = depth;
	for(int i = h[u];i != -1;i = ne[i])
	{
		int y = e[i];
		if((i^1) == edge) continue ;
		else if(vis[y])
		{
			if((dep[u] - dep[y] + w[i]) % 2 == 1) fid = true;
			else fid = false;
			continue ;
		}
		dfs3(y,i,dep[u] + w[i]);
		sz[u] += sz[y];
	}
}

void solve3()
{
	cin >> n >> m;
	res = idx = 0;
	//cout << "ok" << endl;
	for(int i = 1;i <= n;++i) tag[i] = vis[i] = false,fa[i] = i,ind[i] = sz[i] = 0;
	memset(h,-1,sizeof(h));
	for(int i = 1;i <= m;++i)
	{
		cin >> opt[i];
		if(opt[i] == 'T' || opt[i] == 'F' || opt[i] == 'U') 
		{
			cin >> x[i];
			fa[x[i]] = x[i];
			tag[x[i]] = true;
			ans[x[i]] = opt[i];
		}
		else if(opt[i] == '+')
		{
			cin >> x[i] >> y[i];
			fa[x[i]] = fa[y[i]];
			if(tag[x[i]]) ans[x[i]] = ans[y[i]];
		}
		else
		{
			cin >> x[i] >> y[i];
			fa[x[i]] = -fa[y[i]];
			if(tag[x[i]]) ans[x[i]] = ans[y[i]];	
		}
	}
	//cout << "ok" << endl;
	for(int i = 1;i <= n;++i)
	{
		if(fa[i] == i) continue ;
		if(fa[i] < 0) cadd(-fa[i],i,1),cadd(i,-fa[i],1);
		else cadd(fa[i],i,0),cadd(i,fa[i],0);
		++ind[i];
	}
	//cout << "NO" << endl;
	for(int i = 1;i <= n;++i) 
		if(fa[i] == i) 
		{
			dfs2(i,0);
			if(ans[i] == 'U') res += sz[i];
		}
	//cout << "YES" << endl;
	for(int i = 1;i <= n;++i)
		if(!vis[i]) 
		{
			fid = false;
			dfs3(i,-1,1);
			if(fid) res += sz[i];
		}
	//cout << "YES" << endl;
	cout << res << endl;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--) 
	{
		if(c == 1 || c == 2) solve1();
		else if(c >= 3 && c <= 6) solve2();
		else solve3();
	}
	return 0;
}
