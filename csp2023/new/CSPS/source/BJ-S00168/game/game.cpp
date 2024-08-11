# include <bits/stdc++.h>
using namespace std;

int n, cnt;
bool vis[2000005];
string s;

bool check(int l, int r)
{
	if ((r - l + 1) % 2 != 0) return 0;
	int cur = l, cnt1 = 0;
	for (int i = 1; i <= (r - l + 1) / 2; i++)
	{
		cur = l;
		while (cur <= r)
		{
			bool f = 0;
			if (cur != r && !vis[cur])
			{
				char t = s[cur];
				for (int j = cur + 1; j <= r; j++)
				{
					if (!vis[j] && s[j] != t) break;
					if (!vis[j] && s[j] == t)
					{
						//cout << cur << ' ' << j <<  ' ' << t << ' ' << cnt1 << endl;
						cnt1 += 2;
						vis[j] = vis[cur] = 1;
						cur = j + 1;
						f = 1;
						break;
					}
				}
			}
			if (f == 0) cur++;
		}
		if (cnt1 == r - l + 1) return 1;
	}
	return 0;
}

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			memset(vis, 0, sizeof(vis));
			if (check(i, j))
			{
				//cout << i << " " << j << endl;
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
