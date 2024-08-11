#include <iostream>

using namespace std;

typedef long long ll;
const int N = 1e5 + 7;
ll n, d;
ll ans, now, last = 1e9 + 7;
ll v[N], a[N];

int main(){
	ios::sync_with_stdio(false);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> d;
	for(int i = 1; i < n; ++i){
		cin >> v[i];
	}
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	for(int i = 1; i < n; ++i){
		if(last > a[i]){
			if(now <= 0){
			}else if(now % d == 0){
				ans += (now / d) * last;
				now = 0;
			}else{
				ans += (now / d + 1) * last;
				now = (now % d) - d;
			}
			last = a[i];
		}
		now += v[i];
	}
	if(now > 0){
		if(now % d == 0){
			ans += (now / d) * last;
			now = 0;
		}else{
			ans += (now / d + 1) * last;
			now = now % d;
		}
	}
	cout << ans << endl;
	return 0;
}