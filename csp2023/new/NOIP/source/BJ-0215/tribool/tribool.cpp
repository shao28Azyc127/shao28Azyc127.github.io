#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const int inf = 1e9;
int n, m;
namespace sub2
{
	int a[N];
	struct node { int t, x, y; }q[N]; //t -> x or x -> y
	bool book[N];
	void change();
}
namespace sub1
{
	int a[N], ans = 0, tmp[N];
	void dfs(int cur);
	int check();
	struct node { int t, x, y; }q[N]; //t -> x or x -> y
}

int main()
{
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	int C, T;
	cin >> C >> T;
	while (T--)
	{
		cin >> n >> m;
		if (C <= 2)
		{
			using namespace sub1;
			char ch;
			for (int i = 1;i <= m;i++)
			{
				cin >> ch;
				if (ch == 'T') q[i].t = 1, cin >> q[i].x;
				if (ch == 'F') q[i].t = 2, cin >> q[i].x;
				if (ch == 'U') q[i].t = 3, cin >> q[i].x;
				if (ch == '+') q[i].t = 4, cin >> q[i].y >> q[i].x;
				if (ch == '-') q[i].t = 5, cin >> q[i].y >> q[i].x;
			}
			ans = n;
			dfs(1);
			cout << ans << endl;
		}
		else if (C <= 4)
		{
			char ch;
			int x, sum = 0;
			for (int i = 1;i <= m;i++)
			{
				cin >> ch >> x;
				if (ch == 'U') sum++;
			}
			cout << sum << endl;
		}
		else if (C <= 6)
		{
			using namespace sub2;
			int sum = 0;
			for (int i = 1;i <= n;i++) a[i] = 1, book[i] = false;
			char ch;
			for (int i = 1;i <= m;i++)
			{
				cin >> ch >> q[i].x;
				if (ch == 'U') q[i].t = 3;
				else q[i].t = 4, cin >> q[i].y;
			}
			bool flag = true;
			while (flag)
			{
				change();
				flag = false;
				for (int i = 1;i <= n;i++)
					if (!book[i] && a[i] == 3) flag = true, book[i] = true;
			}
			for (int i = 1;i <= n;i++)
				if (a[i] == 3) sum++;
			cout << sum << endl;
		}
		else cout << "Good Luck!" << endl;
	}
	return 0;
}

void sub2::change()
{
	for (int i = 1;i <= m;i++)
	{
		if (q[i].t == 4) a[q[i].x] = a[q[i].y];
		if (q[i].t == 3) a[q[i].x] = 3;
	}
}

int sub1::check()
{
	for (int i = 1;i <= n;i++) tmp[i] = a[i];
	for (int i = 1;i <= m;i++)
	{
		if (q[i].t <= 3) tmp[q[i].x] = q[i].t;
		else if (q[i].t == 4) tmp[q[i].y] = tmp[q[i].x];
		else
		{
			if (tmp[q[i].x] == 1) tmp[q[i].y] = 2;
			else if (tmp[q[i].x] == 2) tmp[q[i].y] = 1;
			else tmp[q[i].y] = 3;
		}
	}
	int sum = 0;
	for (int i = 1;i <= n;i++)
	{
		if (tmp[i] != a[i]) return inf;
		if (tmp[i] == 3) sum++;
	}
	return sum;
}

void sub1::dfs(int cur)
{
	if (cur == n + 1)
	{
		ans = min(ans, check());
		return;
	}
	for (int i = 1;i <= 3;i++) a[cur] = i, sub1::dfs(cur + 1);
}
