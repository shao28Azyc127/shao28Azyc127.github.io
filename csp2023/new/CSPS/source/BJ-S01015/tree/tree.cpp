#include <bits/stdc++.h>
using namespace std;
long long n, a[1000005], b[1000005], c[1000005], tot = 0, hea[1000005], mn = 1e18;
struct Edge{
	long long next, to;
} edge[1000005];
vector<long long> vc, height, dy, bk;
void add(long long a, long long b){
	edge[++tot].next = hea[a];
	edge[tot].to = b;
	hea[a] = tot;
	return ;
}
bool flg = false;
void dfs(long long u, vector<long long> v, vector<long long> hi, vector<long long> dayt, vector<long long> book, long long le, long long ove){
	if ((long long)(v.size()) == n){
		while (true){
			for (long long i = 1; i <= n; i++){
				dayt[i]++;
			}
			if (dayt[1] > ove){
				flg = true;
				return ;
			}
			if (dayt[1] == ove){
				flg = true;
			}
			for (long long i = 1; i <= n; i++){
				hi[i] += max(1ll, b[i] + dayt[i] * c[i]);
			}
			bool flg1 = true;
			for (long long i = 1; i <= n; i++){
				if (hi[i] < a[i]){
					flg1 = false;
					break;
				}
			}
			if (flg1){
				break;
			}
		}
		mn = min(mn, dayt[1]);
		return ;
	}
	if (dayt[1] > ove){
		flg = true;
		return ;
	}
	if (dayt[1] == ove){
		flg = true;
		return ;
	}
	for (long long q = 0; q < (long long)(v.size()); q++){
		long long u1 = v[q];
		for (long long i = hea[u1]; i; i = edge[i].next){
			long long v1 = edge[i].to;
			if (hi[v1] != 0){
				continue;
			}
			v.push_back(v1);
			for (long long j = 0; j < (long long)(v.size()); j++){
				dayt[v[j]]++;
			}
			for (long long j = 0; j < (long long)(v.size()); j++){
				hi[v[j]] += max(1ll, b[i] + dayt[v[j]] * c[i]);
			}
			dfs(v1, v, hi, dayt, book, le + 1, ove);
		}
	}
	return ;
}
int main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	scanf("%lld", &n);
	height.push_back(0ll);
	dy.push_back(0ll);
	bk.push_back(0ll);
	for (long long i = 1; i <= n; i++){
		height.push_back(0ll);
		dy.push_back(0ll);
		bk.push_back(0ll);
		scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
	}
	//bool flgq = true;
	for (long long i = 1; i <= n - 1; i++){
		long long u, v;
		scanf("%lld%lld", &u, &v);
		add(u, v);
		add(v, u);
		/*if (u != i || v != i + 1){
			flgq = false;
		}*/
	}
	dy[1] = 1;
	vc.push_back(1ll);
	height[1] = max(b[1] + c[1], 1ll);
	for (long long ov = 1; ov; ov++){
		flg = false;
		dfs(1, vc, height, dy, bk, 1, ov);
		if (mn != (long long)(1e18)){
			printf("%lld\n", mn);
			break;
		}
		if (!flg){
			break;
		}
	}
	return 0;
}
