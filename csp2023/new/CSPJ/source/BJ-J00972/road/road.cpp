#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;
const int INF = 1e9 + 7;

int n, d, v[N], a[N];
ll tmp, dis, minn, ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> d;
	for(int i = 1; i < n; i++) cin >> v[i];
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	minn = a[1];
	for(int i = 1; i < n; i++)
	{
		dis += v[i], tmp = dis / d;
		if(dis % d != 0) tmp++;
		if(a[i + 1] < minn || i == n - 1)
			ans += minn * tmp, dis -= tmp * d, minn = a[i + 1];
	}
	cout << ans;
	
	return 0;
}