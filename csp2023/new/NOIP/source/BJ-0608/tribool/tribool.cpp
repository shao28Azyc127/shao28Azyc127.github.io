#include <bits/stdc++.h>
using namespace std;

typedef long long Long;
const Long LIM = 100100;

bool known[LIM] = { };
int nval = 0;

char v;
Long argn;
int vis[LIM];

inline Long read()
{
	bool pos = true;
	char c = getchar();
	Long res = 0;
	while (!isdigit(c))
	{
		if (c == '-')
		{
			pos = false;
		}
		c = getchar();
	}
	while (isdigit(c))
	{
		res = res * 10 + c - 48;
		c = getchar();
	}
	return pos? res : -res;
}

int main()
{
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	Long PCnt = read(), t = read(), n, m, cnt = 0;
	if (PCnt == 3 || PCnt == 5)
	{
		while (t)
		{
			t--;
			memset(vis, -1, sizeof(vis));
			n = read();
			m = read();
			for (int i = 0; i < m; i++)
			{
				cin >> v >> argn;
				if (v == 'T')
				{
					vis[argn] = 1;
				}
				if (v == 'U')
				{
					vis[argn] = 2;
				}
				if (v == 'F')
				{
					vis[argn] = 0;
				}
			}
			for (int i = 1; i <= n; i++)
			{
				if (vis[i] == 2)
					cnt++;
			}
			cout << cnt << endl;
		}
		return 0;
	}
	while (t)
	{
		t--;
		memset(vis, -1, sizeof(vis));
			n = read();
			m = read();
			for (int i = 0; i < m; i++)
			{
				cin >> v >> argn;
				if (v == 'T')
				{
					vis[argn] = 1;
				}
				else if (v == 'U')
				{
					vis[argn] = 2;
				}
				else if (v == 'F')
				{
					vis[argn] = 0;
				}
				else
				{
					cin >> argn;
				}
			}
			for (int i = 1; i <= n; i++)
			{
				if (vis[i] == 2)
					cnt++;
			}
			cout << cnt << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
