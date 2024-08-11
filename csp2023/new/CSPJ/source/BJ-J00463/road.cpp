#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;
long long v[100005], a[100005], sa[100005];
int n, d;
long long m = 0, ans = 0;
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for(int i = 1;i < n;i++)
        cin >> v[i];
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    memset(sa, 0x3f, sizeof(sa));
    a[0] = 1e18;
    for(int i = 1;i <= n;i++)
        sa[i] = min(sa[i - 1], a[i - 1]);
    for(int i = 2;i <= n;i++)
    {
        v[i - 1] -= m;
        m = 0;
        if(v[i - 1] % d == 0)
        {
            ans += (v[i - 1] / d) * sa[i];
            m = 0;
        }
        else
        {
            ans += ((v[i - 1] / d) + 1) * sa[i];
            m = ((v[i - 1] / d) + 1) * d;
            m -= v[i - 1];
        }
    }
    cout << ans << endl;
    return 0;
}
