#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const long long MAXN = 1e5 + 10;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ll n, d;
	cin >> n >> d;
	ll v[MAXN], a[MAXN], sum = 0;
	for(ll i = 1; i < n; ++i) {
		cin >> v[i];
		sum += v[i];
	}
	for(ll i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	cout << a[1] * sum / d;
	return 0;
}
