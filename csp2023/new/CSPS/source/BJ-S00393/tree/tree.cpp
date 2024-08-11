#include <bits/stdc++.h>
using namespace std;
int n, ans;
int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{

		int a, b, c;
		cin >> a >> b >> c;
		ans = max(ans, (a / b) + (a % b == 0));
	}
	cout << ans + n << endl;

	return 0;
}