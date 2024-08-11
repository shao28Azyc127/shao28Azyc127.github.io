#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 2e5 + 10;
int n, d;
int a[N], b[N], stk[N], l[N], tt;
LL s[N];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d", &n, &d);
	for (int i = 1; i < n; i ++ ) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i ++ ) scanf("%d", &b[i]);
	for (int i = 2; i <= n; i ++ ) s[i] = s[i - 1] + a[i - 1];
	for (int i = n; i >= 1; i -- ) {
		while (tt && b[stk[tt]] >= b[i]) tt --;
		if (tt) l[i] = stk[tt];
		else l[i] = n;
		stk[ ++ tt] = i;
	}
	LL ans = 0;
	double now = 0;
	for (int i = 1; i <= n; i ++ ) {
		double go = now * d, x = s[l[i]] - s[i];
		if (x > go) {
			double t = (x - go) / d;	
			LL nn = t;
			if (nn != t) nn ++;
			ans += nn * b[i], now += nn;
		}
		now -= 1.0 * a[i] / d;
	}
	cout << ans << endl;
	return 0;
}

