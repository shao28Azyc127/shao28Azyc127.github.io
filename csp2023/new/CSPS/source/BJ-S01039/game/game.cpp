#include<bits/stdc++.h>
using namespace std;

const int nr = 2e6 + 10;
int n;
char c[nr], tc[nr];

bool check(int l, int r)
{
	if (l > r) return true;
	bool cansolve = false;
	for (int i = l; i < r; i++)
		if (c[i] == c[i + 1]) 
		{
			cansolve = true;
			for (int j = i; j <= r - 2; j++) c[j] = c[j + 2];
			r -= 2;
		}
	if (!cansolve) return false;
	return check(l, r);
}

void solve()
{
	for (int i = 1; i <= n; i++) tc[i] = c[i];
	int ans = 0;
	for (int l = 1; l < n; l++)
		for (int r = l + 1; r <= n; r++)
		{
			ans += (check(l, r));
			for (int i = 1; i <= n; i++) c[i] = tc[i];
		}
	cout << ans << endl;
}

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> c[i];
	solve();
	return 0;
}