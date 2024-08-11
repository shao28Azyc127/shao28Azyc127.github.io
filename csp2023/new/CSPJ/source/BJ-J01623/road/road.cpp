#include <iostream>
#include <cmath>
using namespace std;

int n, d, ans;
double oil;
int v[100005], a[100005], minn[100005];

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    minn[0] = 2e9;
    for (int i = 1; i <= n; i++)
    {
        minn[i] = min(minn[i - 1], a[i]);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        ans += minn[i] * ceil(1.0 * v[i] / d - oil);
        oil += ceil(1.0 * v[i] / d - oil) - 1.0 * v[i] / d;
    }
    cout << ans;
    return 0;
}
