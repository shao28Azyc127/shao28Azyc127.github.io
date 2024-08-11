#include <bits/stdc++.h>
using namespace std;
long long n, d, v[1000005], a[1000005], ans = 0;
double now = 0;
int main(){
		freopen("road.in", "r", stdin);
		freopen("road.out", "w", stdout);
		scanf("%lld%lld", &n, &d);
		for (long long i = 1; i <= n - 1; i++){
				scanf("%lld", &v[i]);
		}
		for (long long i = 1; i <= n; i++){
				scanf("%lld", &a[i]);
		}
		for (long long i = 1; i <= n; i++){
				long long j = i + 1;
				double dist = v[i] * 1.0 / d;
				while (j <= n && a[i] < a[j]){
					    if (j <= n - 1){
							dist += v[j] * 1.0 / d;
						}
						j++;
				}
				long long nd = ceil(dist);
				if (dist >= now){
						long long s = ceil(dist - now);
						double q = dist - s;
						if (ceil(dist - now) < nd){
							nd = ceil(dist - now);
							now -= q;
						}
				}else{
						now -= dist;
						nd = 0;
				}
				ans += nd * a[i];
				if (nd > dist){
					now += nd - dist;
				}
				i = j - 1;
		}
		printf("%lld\n", ans);
		return 0;
}
