#include <bits/stdc++.h>
using namespace std;

int c, t;

namespace S20
{
	int tp(char c)
	{
		if (c == 'T' || c == 'F' || c == 'U') return 1;
		if (c == '+') return 2;
		if (c == '-') return 3;
		return 0;
	}
	
	const int MR = 15;
	int n, m;
	char op[MR];
	int a[MR], b[MR];
	int v1[MR], v2[MR];	
	int ans;
	
	void dfs(int p, int cnt)
	{
		if (cnt >= ans) return;
		if (p > n)
		{
			for (int i = 1; i <= n; i++)
				v2[i] = v1[i];
			for (int i = 1; i <= m; i++)
				if (tp(op[i]) == 1) v2[a[i]] = (op[i] == 'T') - (op[i] == 'F');
				else if (tp(op[i]) == 2) v2[a[i]] = v2[b[i]];
				else if (tp(op[i]) == 3) v2[a[i]] = -v2[b[i]];
			for (int i = 1; i <= n; i++)
				if (v1[i] != v2[i]) return;
			ans = cnt;
			return;
		}	
		for (int i = -1; i <= 1; i++)
			v1[p] = i, dfs(p + 1, cnt + (i == 0));
	}
	
	void solve()
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++)
		{
			for (op[i] = ' '; !tp(op[i]); op[i] = getchar());
			if (tp(op[i]) == 1) scanf("%d", a + i);
			else scanf("%d%d", a + i, b + i);
		}
		ans = 10;
		dfs(1, 0);
		printf("%d\n", ans);
	}
}

namespace S40
{
	int tp(char c)
	{
		if (c == 'T' || c == 'F' || c == 'U') return 1;
		if (c == '+') return 2;
		if (c == '-') return 3;
		return 0;
	}
	
	const int NR = 1e5+10;
	int a[NR], fa[NR];
	
	int find(int x)
	{
		if (x == fa[x]) return x;
		return fa[x] = find(fa[x]);
	}
	
	void solve()
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n + 3; i++)
			a[i] = i;
		while (m--)
		{
			char op = ' ';
			while (!tp(op)) op = getchar();
			if (tp(op) == 1) 
			{
				int i;
				scanf("%d", &i);
				a[i] = (op == 'T') - (op == 'F') + n + 2;
			}
			else
			{
				int i, j;
				scanf("%d%d", &i, &j);
				a[i] = a[j];
			}
		}
		for (int i = 1; i <= n + 3; i++)
			fa[i] = i;
		for (int i = 1; i <= n; i++)
			fa[find(i)] = find(a[i]);
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (find(i) == find(n + 2)) cnt++;
		printf("%d\n", cnt);
	}
}

namespace AC
{
	int tp(char c)
	{
		if (c == 'T' || c == 'F' || c == 'U') return 1;
		if (c == '+') return 2;
		if (c == '-') return 3;
		return 0;
	}

	const int NR = 1e5+10;
	int n, m;
	int a[NR << 1], fa[NR << 1], Fa[NR << 1];
	vector<int> g[NR << 1];
	int c[NR << 1];
	bool mark[NR << 1];

	int rev(int x)
	{
		if (x <= n) return x + n;
		if (x <= (n << 1)) return x - n;
		return (n << 2) + 4 - x;
	}

	int find(int x)
	{
		if (x == fa[x]) return x;
		return fa[x] = find(fa[x]);
	}

	int Find(int x)
	{
		if (x == Fa[x]) return x;
		return Fa[x] = Find(Fa[x]);
	}

	bool dfs(int x, int fa)
	{
		if (x == find((n << 1) + 2)) return 0;
		c[x] = (fa ? -c[fa] : 1);
		bool flag = true;
		for (int i = 0; i < g[x].size(); i++)
		{
			int y = g[x][i];
			if (c[y] == c[x]) flag = false;
			if (!c[y] && !dfs(y, x)) flag = false;
		}
		return flag;
	}

	void solve()
	{
		memset(a, 0, sizeof(a));
		memset(fa, 0, sizeof(fa));
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= (n << 1) + 3; i++)
			a[i] = i;
		while (m--)
		{
			char op = ' ';
			while (!tp(op)) op = getchar();
			if (tp(op) == 1) 
			{
				int i;
				scanf("%d", &i);
				a[i] = (op == 'T') - (op == 'F') + (n << 1) + 2;
			}
			if (tp(op) == 2)
			{
				int i, j;
				scanf("%d%d", &i, &j);
				a[i] = a[j];
			}
			if (tp(op) == 3)
			{
				int i, j;
				scanf("%d%d", &i, &j);
				a[i] = rev(a[j]); 
			}
		}
		for (int i = 1; i <= (n << 1) + 3; i++)
			Fa[i] = fa[i] = i;
		for (int i = 1; i <= n; i++)
			fa[find(i)] = find(a[i]);
		for (int i = 1; i <= (n << 1) + 3; i++)
			g[i].clear();
		for (int i = 1; i <= n; i++)
		{
			g[find(i)].push_back(find(rev(i)));
			g[find(rev(i))].push_back(find(i));
			Fa[Find(find(i))] = Find(find(rev(i)));
		}	
		memset(c, 0, sizeof(c));
		memset(mark, 0, sizeof(mark));
		for (int i = 1; i <= n; i++)
			if (!c[Find(find(i))]) mark[Find(find(i))] = !dfs(Find(find(i)), 0);
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			cnt += mark[Find(find(i))];
		printf("%d\n", cnt);
		for (int i = 1; i <= (n << 1) + 3; i++)
			g[i].clear();
	}
}

int main()
{
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	scanf("%d%d", &c, &t);
	if (c <= 2) {while (t--) S20::solve(); return 0;}
	else if (c <= 6) {while (t--) S40::solve(); return 0;}
	else {while (t--) AC::solve(); return 0;}
	return 0;
}