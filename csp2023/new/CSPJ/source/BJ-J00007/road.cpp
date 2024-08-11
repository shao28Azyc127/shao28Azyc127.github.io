#include <iostream>
#include <cstdio>
#include <algorithm>
typedef long long ll;
using namespace std;
ll v[100003], a[100003];
ll ans = 1e9, Ans = 1e9;
ll n, d;
ll totv = 0;

inline ll min(ll a, ll b){
	return a < b ? a : b;
}

void dfs(ll step, ll cost, ll last){
	if(step == n - 1){
		ans = min(ans, cost);
		return ;
	}
	ll Last = last - v[step - 1] / d;
	if(Last <= v[step] / d){
		return ;
	}
	if(Last * d >= v[step]){ // no buy
		dfs(step + 1, cost, Last - v[step] / d);
	}
	for(ll i = v[step] / d; i <= totv / d + 1; ++i){ // buy
		dfs(step + 1, cost + a[step] * i, Last + i);
	}
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> d;
	for(ll i = 1; i < n; ++i){
		cin >> v[i]; // dist
		totv += v[i];
	}
	ll minn = 1e18;
	for(ll i = 1; i <= n; ++i){
		cin >> a[i];// price
		minn = min(a[i], minn);
	}
	if(minn == a[1]){
		cout << totv / d * a[1] << endl;
		exit(0);
	}
	for(ll i = v[1] / d; i <= totv / d; ++i){
		dfs(2, a[1] * i, i - v[1] / d);
	}
	cout << ans << endl;
	return 0;
}
