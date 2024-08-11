#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 10;
long long v[maxn],a[maxn];
long long cnt[maxn];
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	long long n,d;
	scanf("%lld%lld",&n,&d);
	
	for (int i = 2; i <= n; i++) {
		scanf("%lld",&v[i]);
	}
	for (int i = 1; i <= n; i++) {
		cnt[i] = cnt[i - 1] + v[i];
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld",&a[i]);
	}
	a[n] = -1;
	int i = 1,j = 2;
	long long ans = 0,num = 0;
	while (i < n) {
		while (j + 1 <= n && a[j] >= a[i]) j++;
		int dis = cnt[j] - cnt[i];
		ans += (( dis - num) / d + (( dis - num) % d != 0)) * a[i];
		num += (( dis - num) / d + (( dis - num) % d != 0)) * d - dis;
		i = j;
	}
	printf("%lld\n",ans);
	
	return 0;
}
