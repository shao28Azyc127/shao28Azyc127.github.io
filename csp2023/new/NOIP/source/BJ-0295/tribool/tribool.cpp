#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5;

int c, t;
int cnt;
int ans;
vector<int> kin[maxn + 5];
vector<int> kout[maxn + 5];

int vis[maxn + 5];
struct edge
{
	int l, r;
	int value;
}es[maxn + 5];

int dfs(int k, int vl)
{
	int p = kout[k].size();
	if(p == 0)
	{
		return -1;
	}
	else if(vis[k] != -100)
	{
		if(vl != vis[k])
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		vis[k] = vl;
		for(int i = 0; i < p; i ++)
		{
			int lr = kout[k][i];
			int y;
			if(lr > 0)
			{
				y = dfs(lr, vl);
			}
			else if(vl == 2)
			{
				y = dfs(-lr, 1);
			}
			else
			{
				y = dfs(-lr, 2);
			}
			
			if(y != -1)
			{
				int t = y + 1;
				return t;
			}
		}
		return -1;
	}
}

int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin >> c >> t;
	if(c >= 7 && c <= 8)
	{
		while(t --)
		{
			int n, m;
			cin >> n >> m;
			cnt = 0;
			for(int i = 1; i <= m; i ++)
			{
				char opt;
				int a, b;
				cin >> opt >> a >> b;
				es[++ cnt].l = b;
				es[++ cnt].r = a;
				if(opt == '+')
				{
					es[++ cnt].value = 0;
					kout[a].push_back(b);
					kout[b].push_back(a);
				}
				if(opt == '-')
				{
					es[++ cnt].value = 1;
					kout[a].push_back(-b);
					kout[b].push_back(-a);
				}
			}
			for(int i = 1; i <= n; i ++)
			{
				vis[i] = -100;
			}
			ans = 0;
			for(int i = 1; i <= n; i ++)
			{
				if(vis[i] == -100)
				{
					int qwq = dfs(i, 2);
					if(qwq != -1)
					{
						ans += qwq;
					}
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}
