#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 1e5 + 7;
ll n, m, k, d, ans;
ll dp[N];

struct Node{
	ll x, y, num;
	bool operator<(const Node & no)const{
		return x < no.x;
	}
}a[N];

int main(){
	ios::sync_with_stdio(false);
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	int C, T;
	cin >> C >> T;
	while(T--){
		cin >> n >> m >> k >> d;
		for(int i = 1; i <= m; ++i){
			cin >> a[i].x >> a[i].y >> a[i].num;
		}
		sort(a + 1, a + m + 1);
		memset(dp, 128, sizeof(dp));
		dp[0] = 0;
		int now = 1;
		for(int i = 1; i <= n; ++i){
			ll tmp = dp[0];
			for(int j = 0; j <= k; ++j){
				dp[0] = max(dp[0], dp[j]);
			}
			for(int j = k; j >= 2; --j){
				dp[j] = dp[j - 1] - d;
			}
			dp[1] = tmp - d;
			while(now <= m && a[now].x == i){
				for(int j = a[now].y; j <= k; ++j){
					dp[j] += a[now].num;
				}
				now++;
			}
		}
		ans = -1e18 - 7;
		for(int i = 0; i <= k; ++i){
			ans = max(ans, dp[i]);
		}
		cout << ans << endl;
	}
	return 0;
}	