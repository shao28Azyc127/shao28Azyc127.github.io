#include <bits/stdc++.h>
using namespace std;

bool f[10005][10005],f2[1000005][105];
int n,m,k,u[20005],v[20005],a[20005],p = 10000;

int main() {
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin >> n >> m >> k;
	if (n <= 100) {
		p = 0;
		for (int i = 1;i <= m;i++) {cin >> u[i] >> v[i] >> a[i];p = max(p,a[i]);}
		p += m;
		for (int i = 0;i * k <= p;i++) f2[i * k][1] = 1;
		for (int i = 1;i <= p;i++)
			for (int j = 1;j <= m;j++) f2[i][v[j]] |= (i >= a[j] && f2[i - 1][u[j]]);
		for (int i = 0;i * k <= p;i++)
			if (f2[i * k][n]) {cout << i * k << endl;return 0;}
		cout << -1 << endl;
		return 0;
	}
	for (int i = 1;i <= m;i++) cin >> u[i] >> v[i] >> a[i];
	for (int i = 0;i * k <= p;i++) f[i * k][1] = 1;
	for (int i = 1;i <= p;i++)
		for (int j = 1;j <= m;j++) f[i][v[j]] |= (i >= a[j] && f[i - 1][u[j]]);
	for (int i = 0;i * k <= p;i++)
		if (f[i * k][n]) {cout << i * k << endl;return 0;}
	cout << -1 << endl;
	return 0;
}