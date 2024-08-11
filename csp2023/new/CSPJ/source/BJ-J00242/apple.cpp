# include <bits/stdc++.h>
using namespace std;

bool a[1000005];

int main()
{
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	int n;
	cin >> n;
	int cnt = 0, ans = 0, last;
	int i, tmp;
	while (cnt < n)
	{
		i = 1;
		tmp = 2;
		while (i <= n)
		{
			if (a[i])
			{
				i++;
				continue;
			}
			tmp++;
			if (tmp == 3)
			{
				tmp = 0;
				cnt++;
				a[i] = 1;
				if (i == n)
					last = ans + 1;
				if (i > n)
				{
					break;
				}
			}
			i++;
		}
		ans++;
	}
	cout << ans << ' ' << last << endl;
	return 0;
}
