#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
int n, d, ans, cnt;
int v[N], p[N], sum[N];
vector <int> f[N];
double num = 0.0;

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
	scanf("%d%d", &n, &d);
	for (int i = 2; i <= n; i++) scanf("%d", &v[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	f[1].push_back(p[1]);
    for (int i = 2; i <= n; i++) {
        double tmp = (v[i] * 1.0) / (d * 1.0);
        int k = ceil(tmp - num);
        num += k;
        num -= tmp;
        f[i].push_back(min(f[i - 1][0], p[i - 1]));
        f[i].push_back(f[i - 1][1] + k * f[i][0]);
    }
	printf("%d", f[n][1]);
	return 0;
}
