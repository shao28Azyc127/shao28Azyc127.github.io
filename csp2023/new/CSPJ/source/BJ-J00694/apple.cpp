#include <iostream>
#include <algorithm>
using namespace std;

int n, cnt, ans;
bool f = false;

int main()
{
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	cin >> n;
	int i = n;
	for (; i >= 1;)
	{
		if (i % 3 == 1 && !f)
		{
			ans = cnt + 1;
			f = true;
		}
		cnt++;
		int x;
		if (i % 3 == 0) x = max(i / 3, 1);
		else x = max(i / 3 + 1, 1);
		i -= x;
	}
	if (ans == 0) ans = cnt;
	cout << cnt << " " << ans << endl;
	return 0;
}