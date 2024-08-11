#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N = 1e5 + 5;
int dis[N], v[N], s[N];
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);

    int n, d; cin >> n >> d;
    for (int i = 1; i < n; i ++)
        cin >> dis[i], s[i + 1] = s[i] + dis[i];
    for (int i = 1; i < n; i ++)
        cin >> v[i]; v[0] = 1e9 + 7;
    int last = 0, ans = 0, dist = 0;
    for (int i = 1; i <= n; i ++)
        if (v[i] < v[last])
        {
            int tmp = s[i] - s[last];
            int cnt = (tmp - dist + d - 1) / d;
            ans += cnt * v[last]; last = i;
            dist = cnt * d + dist - tmp;
        }
    cout << ans;

    return 0;
}
