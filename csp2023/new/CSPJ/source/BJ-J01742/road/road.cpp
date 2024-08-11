#include <bits/stdc++.h>
using namespace std;
int n, d, u[100005], a[100005], ans = 0, tmp = 0, minn;
int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for(int i=1;i<=n-1;i++)
        cin >> u[i];
    for(int i=1;i<=n;i++)
        cin >> a[i];
    minn = a[1];
    for(int i=1;i<=n-1;i++) {
		if(a[i]<minn) {
			minn = a[i];
		}
		if((u[i]-tmp)%d!=0) {
			ans += minn*((u[i]-tmp)/d+1);
			tmp += d*((u[i]-tmp)/d+1)-u[i];
		}
		else {
			ans += minn*((u[i]-tmp)/d);
			tmp = 0;
		}
	}
	cout << ans;
    return 0;
}
