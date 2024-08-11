#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    int r[n], o[n + 1];
    int ans = 0, ext = 0;
    for(int i = 1; i < n; i++) cin >> r[i];
    for(int i = 1; i <= n; i++) cin >> o[i];
    for(int i = 1; i < n; i++) {
        ans += ceil((r[i] / d - ext) * 1.0) * o[i];
        ext = ceil((r[i] / d - ext) * 1.0) - r[i];
    }
    cout << ans << endl;
    return 0;
}