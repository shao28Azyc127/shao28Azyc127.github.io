#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	int n;
	cin >> n;
	int m = n;
	int i = 1, ans = 0;
	if (m % 3 == 1)
	{
		ans = 1;
	}
	while (n > 1)
	{
		i++;
		n -= (n + 2) / 3;
		m = n;
		if (m % 3 == 1)
		{
			break;
		}
	}
	if (ans == 0)
	{
		ans = i;
	}
	while (n > 1)
	{
		n -= (n + 2) / 3;
		i++;
	}
	cout << i << " " << ans << endl;
	return 0;
}