#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int nn = 1e5+5;
struct zd{
    long long id, nu;
}a[nn];
zd cur[nn];
int n, d, cnt ,v[nn], ma, x, dy;
long long sum, sv[nn];

bool cmp(zd a, zd b)
{
    if (a.nu != b.nu) return a.nu < b.nu;
    return a.id < b.id;
}

int main()
{
    freopen("rode.in", "r", stdin);
    freopen("rode.out", "w", stdout);
	cin >> n >> d;
    for (int i = 2; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) sv[i] = sv[i - 1] + v[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].nu;
		a[i].id = i;
    }
    ma = a[1].nu;
    sort(a + 1, a + n + 1, cmp);
    cur[++cnt].id = a[1].id;
    cur[cnt].nu = a[1].nu;
    for (int i = 2; a[i].nu <= ma; i++)
    {
        if (cur[cnt].id < a[i].id) continue;
        if (cur[cnt].nu >= a[i].nu) continue;
        cur[++cnt].id = a[i].id;
		cur[cnt].nu = a[i].nu;
    }
    for (int i = cnt - 1; i >= 1; i--)
    {
        long long dis = sv[cur[i].id] - sv[cur[i + 1].id];
        long long x = ceil(1.0 * (dis - dy) / d);
	    sum += cur[i + 1].nu * x;
        dy = x * d - dis + dy;
    }
    long long dis = sv[n] - sv[cur[1].id], x = ceil(1.0 * (dis - dy) / d);
    sum += cur[1].nu * x;
    cout << sum << endl;
    return 0;
}