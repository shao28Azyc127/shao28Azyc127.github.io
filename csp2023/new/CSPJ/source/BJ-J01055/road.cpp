#include<bits/stdc++.h>
using namespace std;
long long n, d, cnt, m, mina = 1e5 + 10, v[100005], a[100005];
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%lld%lld", &n, &d);
    for (int i = 1; i <= n - 1; i++) scanf("%lld", &v[i]);
    for (int i = 1; i <= n - 1; i++) scanf("%lld", &a[i]);
    mina = a[1];
    for (int i = 1; i <= n - 1; i++) {
		if (a[i] < mina) {
			m += ceil(cnt * 1.0 / d) * mina;
			cnt -= ceil(cnt * 1.0 / d) * d;
			mina = a[i];
		}
		cnt += v[i];
	}
	m += ceil(cnt * 1.0 / d) * mina;
	printf("%lld", m);
    return 0;
}
