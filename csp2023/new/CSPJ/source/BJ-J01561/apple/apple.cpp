#include <bits/stdc++.h>
using namespace std;
int n, cnt, ans;
void dfs(int x)
{
	if (!x) return;
	++cnt;
	if (x % 3 == 1 && !ans) ans = cnt;
	dfs(x - (1 + (x-1) / 3));
}
int main()
{
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	scanf("%d", &n);
	dfs(n);
	printf("%d %d\n", cnt, ans);
	return 0;
}