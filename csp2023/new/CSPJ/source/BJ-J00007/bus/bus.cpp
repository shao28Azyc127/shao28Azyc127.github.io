#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
typedef long long ll;
using namespace std;
ll n, m, k;
ll e[10003][10003];
ll ans = 1e9;

void dfs(ll step, ll t){
	if(step == n){
		if(t % k == 0){
			ans = min(ans, t);
		}
		return ;
	}
	for(ll i = 1; i <= n; ++i){
		if(e[step][i] != -2 && e[step][i] != -1 && t >= e[step][i]){
			dfs(i, t + 1);
		}
	}
	return ;
}

int main(){
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	cin >> n >> m >> k;
	for(ll i = 1; i <= n; ++i){
		for(ll j = 1; j <= n; ++j){
			if(i == j){
				e[i][j] = -2;
			}else{
				e[i][j] = -1;
			}
		}
	}
	for(ll i = 1; i <= m; ++i){
		ll u, v, w;
		cin >> u >> v >> w;
		e[u][v] = w;
	}
	for(ll i = k; ; ++i){
		dfs(1, i);
		if(ans != 1e9){
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
