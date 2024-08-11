#include <bits/stdc++.h>
using namespace std;
long long n, m, k, hea[1000005], tot = 0, to = 0;
bool flg = false, qwq = false;
struct Edge{
	long long next, to, opn;
} edge[1000005];
void add(long long a, long long b, long long c){
	edge[++tot] = Edge{hea[a], b, c};
	hea[a] = tot;
	return ;
}
void dfs(long long chushi, long long u, long long tim, long long overwei){\
	to++;
	if (to > 100000000){
		return ;
	}
	if (tim > overwei){
		return ;
	}
	if (tim == overwei){
		qwq = true;
	}
	if (flg){
		return ;
	}
	if (tim % k == 0 && tim != chushi && u == n){
		flg = true;
		return ;
	}
	for (long long i = hea[u]; i; i = edge[i].next){
		if (to > 100000000){
			return ;
		}
		if (flg){
			return ;
		}
		long long v = edge[i].to;
		if (tim >= edge[i].opn){
			dfs(chushi, v, tim + 1, overwei);
		}
	}
	return ;
}
int main(){
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	scanf("%lld %lld %lld", &n, &m, &k);
	for (long long i = 1; i <= m; i++){
		long long u, v, a;
		scanf("%lld %lld %lld", &u, &v, &a);
		add(u, v, a);
		add(v, u, a);
	}
	long long ans = 1e18;
	for (long long st = 0; st <= 1000000; st += k){
		for (long long ov = st; ov; ov += k){
			qwq = false;
			if (to > 100000000){
				printf("%lld\n", ans);
				return 0;
			}
			dfs(st, 1, st, ov);
			if (flg){
				ans = min(ans, ov);
				break;
			}
			if (!qwq){
				break;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
