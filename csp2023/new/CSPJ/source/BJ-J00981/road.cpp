#include <iostream>
using namespace std;
long long n, d, v[100005], a = 100005, x, lft, ans, tmp;
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for (int i = 1; i < n; i++)
        cin >> v[i];
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        a = min(a, x);
        tmp = (max(v[i] - lft, 0ll) + d - 1) / d;
        ans += tmp * a;
        lft += tmp * d;
        lft -= v[i];
    }
    cout << ans << endl;
    return 0;
}
