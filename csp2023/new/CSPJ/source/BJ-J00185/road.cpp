#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;

int n, d;
int v[MAXN] = {};
int p[MAXN] = {};
long long ans = 0;
int min_p = 10000000;

int main (){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%d %d", &n, &d);
	for (int i = 2; i <= n; i++) scanf("%d", &v[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	
	min_p = p[1];
	int vv = 0;
	for (int i = 2; i <= n; i++){
		vv += v[i];
		if (vv > 0){
			ans += (long long)vv/d * (long long)min_p;
			if (vv % d != 0){
				ans += (long long)min_p;
				vv -= d;
			}
			vv -= v[i] / d * d;
		}
		
		min_p = min(min_p, p[i]);
	}
	printf("%lld", ans);
	
	return 0;
}