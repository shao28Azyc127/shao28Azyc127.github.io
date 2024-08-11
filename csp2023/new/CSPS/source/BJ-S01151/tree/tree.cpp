#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int N = 1e5 + 10;

int n, ans;
int a[N], b[N], c[N];

signed main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        double aa = c[i] / 2.0, bb = c[i] / 2.0 + b[i], cc = (-i * i + i) / 2.0 * c[i] + (1.0 - i) * b[i] - a[i];
        ans = max(ans, cc != 0 ? (int)ceil((-bb + sqrt(bb * bb - 4 * aa * cc) / (2 * aa))) : (int)ceil(1.0 * a[i] / b[i]));
    }
    cout << ans << endl;
    return 0;
}

