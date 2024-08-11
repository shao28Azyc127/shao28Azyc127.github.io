#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

bool kxc (string s, int ks)
{
	if (ks == -1)
	{
		ks = 0;
	}
	if (s.size() == 0)
	{
		return true;
	}
	if (s.size() % 2 == 1)
	{
		return false;
	}
	int i;
	bool ans = false;
	for (i = ks; i < s.size() - 1; i++)
	{
		if (s[i] == s[i + 1])
		{
			ans = (ans || kxc(s.substr(0, i) + s.substr(i + 2), i - 1));
			break;
		}
	}
	return ans;
}

int main ()
{
	freopen ("game.in", "r", stdin);
	freopen ("game.out", "w", stdout);
	string a;
	int i, j, n, ans = 0;
	cin >> n >> a;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 2; j + i <= n; j += 2)
		{
			if (kxc(a.substr(i, j), 0))
			{
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}