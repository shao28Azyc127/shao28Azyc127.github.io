#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int n,m,k;
bool r[10005][10005];
bool vis[10005][10005];
int a[10005];
bool flg = true;
struct node
{
	int now,t;
};
queue<node> q;

int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin >> n >> m >> k;
	for (int i=1;i<=m;i++) 
	{
		int u,v;
		cin >> u >> v >> a[i];
		r[u][v] = true;
		if (a[i] != 0) flg = false;
	}
	if (!flg) cout << -1;
	else
	{
		for (int i=0;i<k;i++)
		{
			node xyz;
			xyz.t = i;
			xyz.now = 1;
			q.push(xyz);
		}
		while (!q.empty())
		{
			node temp = q.front();
			if (temp.t%k==0 && temp.t!=0)
			{
				cout << temp.t << endl;
				return 0;
			}
			q.pop();
			int now = temp.now;
			int t = temp.t;
			for (int i=1;i<=n;i++)
			{
				if (!vis[now][i] && r[now][i])
				{
					vis[now][i] = true;
					node in;
					in.now = i;
					in.t = t+1;
					q.push(in);
				}
			}
		}
		cout << -1;
	}
	return 0;
}