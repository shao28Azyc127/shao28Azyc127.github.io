/*
思路：从当前站点向后查找，哪个站点的油比当前站点便宜就开到哪个站点
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 1e5 + 5;

int n, d;
int v[MAXN], a[MAXN];
int cur = 1, ans = 0;
double oil = 0;

#undef int
int main(int argc, char const *argv[])
#define int long long
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> d;
	for (int i = 1; i < n; i++)
		cin >> v[i];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	while (cur != n) {
		int distance = 0;
		int to = 0;
		for (int j = cur + 1; j <= n; j++) {
			distance += v[j - 1];
			if (a[j]< a[cur]) {
				to = j;
				break;
			}
		}
		if (!to)
			to = n;
		int need = ceil((double)distance / (double)d - oil);
		ans += need * a[cur];
		oil += need;
		oil -= (double)distance / (double)d;
		cur = to;
		// cout << to << " " << need << endl;
	}
	cout << ans << endl;
	return 0;
}
