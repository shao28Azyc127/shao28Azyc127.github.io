#include <iostream>
#include <cstdio>
using namespace std;

long long n, d, v[100005], a[100005], ans, ns;

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for (int i = 1; i < n; ++i) cin >> v[i];
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i)
    {
        long long sum = 0;
        bool f = false;
        for (int j = i; j < n; ++j)
        {
            if (a[j] < a[i])
            {
                long long x = (sum - ns + d - 1) / d;
                ans += x * a[i];
                ns += x * d - sum;
                i = j - 1;
                f = true;
                break;
            }
            sum += v[j];
        }
        if (!f)
        {
            long long x = (sum - ns + d - 1) / d;
            ans += x * a[i];
            break;
        }
    }
    cout << ans << endl;
    return 0;
}