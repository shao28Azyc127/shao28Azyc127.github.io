#include <bits/stdc++.h>

using namespace std;

int n, m;
string s[3001];

int main()
{
	freopen("dict.in", "r", stdin);
        freopen("dict.out", "w", stdout);//double check
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	if (n == 1)
	{
		cout << 1 << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		sort(s[i].begin(), s[i].end());
	}
	for (int i = 1; i <= n; i++)
	{
		bool tflag = true;
		for (int j = 1; j <= n; j++)
		{
			if (j == i) continue;
			bool flag = false;
			for (int cj = m - 1, ci = 0; cj >= 0, ci < m; cj--, ci++)
			{
				if (s[j][cj] < s[i][ci]) break;
				else if (s[j][cj] > s[i][ci])
				{
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				tflag = false;
				break;
			}
		}
		cout << tflag;
	}
	cout << endl;
}