#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXM 100005
int n, m, k, d;
struct node{
	int x, y;
	long long v;
	friend bool operator < (node a, node b){
		if(a.x != b.x)
			return a.x < b.x;
		return a.y < b.y;
	}
}cha[MAXM];
int c, t;
namespace Solve1{
	long long dfs(int u, int r, long long v, int c){
		if(u == n){
			return v;
		}
		if(c == m + 1){
			return v;
		}
		while(cha[c].x < u) c++;
		while(cha[c].x == u){
			if(cha[c].y <= r) v += cha[c].v;
			c++;
		}
		long long ans = dfs(u + 1, 0, v, c);
		if(r + 1 <= k)
			ans = max(ans, dfs(u + 1, r + 1, v - d, c));
		return ans;
	}
	void work(){
		while(t--){
			scanf("%d%d%d%d", &n, &m, &k, &d);
			for(int i = 1; i <= m; i++){
				scanf("%d%d%lld", &cha[i].x, &cha[i].y, &cha[i].v);
			}
			sort(cha + 1, cha + m + 1);
			printf("%lld\n", dfs(0, 0, 0, 1));
		}
	}
}
namespace Solve2{
	long long dp[1005][1005];
	long long mxdp[1005];
	void init(){
		for(int i = 1; i <= n; i++)
			for(int j = 0; j <= k; j++)
				dp[i][j] = 0 - j * d;
	}
	void work(){
		while(t--){
			scanf("%d%d%d%d", &n, &m, &k, &d);
			init();
			for(int i = 1; i <= m; i++){
				scanf("%d%d%lld", &cha[i].x, &cha[i].y, &cha[i].v);
			}
			sort(cha + 1, cha + m + 1);
			int c = 1;
			mxdp[0] = 0;
			for(int i = 1; i <= n; i++){
				mxdp[i] = 0;
				dp[i][0] = mxdp[i - 1];
				mxdp[i] = max(mxdp[i], dp[i][0]);
				while(cha[c].x < i && c <= m) c++;
				long long sumc = 0;
				for(int j = 1; j <= min(i, k); j++){
					dp[i][j] = dp[i - 1][j - 1] - d;
					while(cha[c].x == i && cha[c].y <= j && c <= m){
						sumc += cha[c].v;
						c++;
					}
					dp[i][j] += sumc;
					mxdp[i] = max(mxdp[i], dp[i][j]);
				}
			}
			printf("%lld\n", mxdp[n]);
		}
		return;
	}
}
namespace Solve3{
	long long dp[2][100005];
	long long mxdp[2];
	void init(){
		for(int i = 0; i <= 1; i++)
			for(int j = 0; j <= k; j++)
				dp[i][j] = 0;
	}
	void work(){
		while(t--){
			scanf("%d%d%d%d", &n, &m, &k, &d);
			init();
			for(int i = 1; i <= m; i++){
				scanf("%d%d%lld", &cha[i].x, &cha[i].y, &cha[i].v);
			}
			sort(cha + 1, cha + m + 1);
			int c = 1;
			mxdp[0] = 0;
			for(int i = 1; i <= n; i++){
				mxdp[i % 2] = 0;
				dp[i % 2][0] = mxdp[(i - 1) % 2];
				mxdp[i % 2] = max(mxdp[i % 2], dp[i % 2][0]);
				while(cha[c].x < i && c <= m) c++;
				long long sumc = 0;
				for(int j = 1; j <= min(i, k); j++){
					dp[i % 2][j] = dp[(i - 1) % 2][j - 1] - d;
					while(cha[c].x == i && cha[c].y <= j && c <= m){
						sumc += cha[c].v;
						c++;
					}
					dp[i % 2][j] += sumc;
					mxdp[i % 2] = max(mxdp[i % 2], dp[i % 2][j]);
				}
			}
			printf("%lld\n", mxdp[n % 2]);
		}
		return;
	}
}
int main () {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	scanf("%d%d", &c, &t);
	if(c <= 2){
		Solve1::work();
		return 0;
	}
	if(c <= 9){
		Solve2::work();
		return 0;
	}
	if(c <= 14){
		Solve3::work();
		return 0;
	}
	return 0;
}