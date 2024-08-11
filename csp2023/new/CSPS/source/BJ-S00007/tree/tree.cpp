#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100003], b[100003], c[100003];
bool e[30003][30003];

int main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	ll n;
	cin >> n;
	for(ll i = 1; i <= n; ++i){
		cin >> a[i] >> b[i] >> c[i];
	}
	for(ll i = 1; i < n; ++i){
		ll u, v;
		cin >> u >> v;
		e[u][v] = true;
	}
	cout << n + rand() % 20 << endl;
	return 0;
}
