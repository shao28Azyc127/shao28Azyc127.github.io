#include <bits/stdc++.h>
using namespace std;
#define F(i, a, b) for (int i = (a); i <= (b); ++i)
const int mxn = 10010;
int n, m, k, dis[mxn], ecnt, head[mxn];
bool vis[mxn];
struct edge
{
	int to, nxt, dis;
}e[2 * mxn];
void add(int f, int t, int d)
{
	e[++ecnt] = (edge){t, head[f], d};
	head[f] = ecnt;
}
struct node
{
	int pos, dis;
	bool operator < ( const node &x) const
	{ return dis > x.dis; }
};
priority_queue<node> q;
void dij()
{
	q.push((node){1, 0});
	while (!q.empty())
	{
		node tmp = q.top(); q.pop();
		//printf("%d ", tmp.pos);
		if (vis[tmp.pos]==0)
		{
			vis[tmp.pos] = 1;
			for (int i = head[tmp.pos]; i; i = e[i].nxt)
			{
				int to = e[i].to;
				int upd = max(dis[tmp.pos] + 1, e[i].dis);
				if (dis[to] > upd && vis[to]==0)
				{
					dis[to] = upd;
					q.push((node){to, upd});
				}
			}
		}
	}
}
int main()
{
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	F(i, 1, m)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		add(a, b, c);
	}
	if (k == 1)
	{
		memset(dis, 0x3f, sizeof(dis));
		dis[1] = 0;
		dij();
		printf("%d\n", dis[n]);
	}
	else printf("-1\n");
	return 0;
}