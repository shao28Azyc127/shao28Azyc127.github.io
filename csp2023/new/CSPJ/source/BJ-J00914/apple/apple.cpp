#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	int n, cnt = 0;
	cin >> n;
	int k = n;
//	cout << n << " " << k << endl;
	while (k)
	{
		if (k % 3 == 0)
		{
			k -= k / 3;
		}
		else
		{
			k -= (k / 3 + 1);
		}
//		cout << k << endl;
		cnt++;
	}
	int l = n - 1, ans = 0;
	while (l % 3 != 0)
	{
		if (l % 3 == 0)
		{
			l -= (l / 3);
		}
		else
		{
			l -= (l / 3 + 1);
		}
		ans++;
	}
	cout << cnt << " " << ans + 1 << endl;
	return 0;
}
