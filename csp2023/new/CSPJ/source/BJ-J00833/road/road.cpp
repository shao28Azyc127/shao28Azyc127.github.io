#include <bits/stdc++.h>
using namespace std;

int n, d;
long long v1[100005];
int a[100005];
int way[100005];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d  %d\n", &n, &d);
	int k = n;
	for (int i = 2; i < n + 1; i++) {
		int temp;
		scanf("%d", &temp);
		v1[i] = v1[i - 1] + temp;
	}
	scanf("\n");
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	way[0] = 1;
	while (n > 1) {
		int ans = 1;
		int ans_va = a[1];
		for (int i = 2; i <= n; i++) {
			if (ans_va > a[i]) {
				ans = i;
				ans_va = a[i];
			}
		}
		way[way[0]] = ans;
		way[0]++;
		n = ans - 1;
	}
	int temp = way[0];
	way[temp] = 1;
	way[0] = k;
	long long ans = 0;
	int now = 0;
	for (int i = 0; i < temp; i++) {
		int to1 = way[temp - i - 1];
		int from1 = way[temp - i];
		long long si = v1[to1] - v1[from1];
		si -= now;
		if (si % d == 0) {
			ans += si/d * a[from1];
			now = 0;
		} else {
			ans += (si/d + 1) * a[from1];
			now = (si/d + 1) * d - si;
		}
	}
	printf("%lld", ans);
	return 0;
}