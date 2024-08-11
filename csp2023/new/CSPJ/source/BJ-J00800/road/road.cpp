#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl '\n'
mt19937 rnd((unsigned long long)new char);
void file(){freopen("road.in", "r", stdin); freopen("road.out", "w", stdout);}
void INIT(){ios::sync_with_stdio(false);}
const bool File = 1;
int n, d;
int a[100005], v[100005];
ll ans, now, hv;
int main(){ File ? file() : void(); INIT();
	cin >> n >> d;
	for(int i = 1; i < n; i++) cin >> v[i];
	for(int i = 1; i <= n; i++) cin >> a[i];
	now = a[1];
	for(int i = 2; i <= n; i++){
		int nd = ceil((v[i - 1] - hv) * 1.0 / d);
		//cout << nd << " " << hv << " ";
		ans += nd * now;
		now = min(now, 1ll * a[i]);
		//cout << now << " ";
		hv = hv + nd * d - v[i - 1];
		//cout << ans << " " << hv << endl;
	}
	cout << ans << endl;
	return 0;
}