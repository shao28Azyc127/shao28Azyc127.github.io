#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX = 100005;
LL n, a[MX], b[MX], c[MX], bor[MX], u[MX], v[MX], day[MX], ans;
bool chk(int k)
{
    for (int i = 1; i <= n; i++)
    {
        LL sum;
        if (k >= bor[i]) sum = (2 * b[i] + (bor[i] + i - 1) * c[i]) * (bor[i] - i) / 2 + (k - bor[i] + 1);
        else sum = (2 * b[i] + (k + i) * c[i]) * (k - i + 1) / 2;
        if (sum < a[i]) return 0;
    }
    return 1;
}
int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        if (c[i] >= 0) bor[i] = n + 10;
        else bor[i] = max(int(ceil(1.0 * (b[i] - 1) / c[i])) - i, i);
    }
    for (int i = 1; i < n; i++) cin >> u[i] >> v[i];
    int l = n, r = 1e9 + 10, mid;
    while (l <= r)
    {
        mid = l + r >> 1;
        if (chk(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}
