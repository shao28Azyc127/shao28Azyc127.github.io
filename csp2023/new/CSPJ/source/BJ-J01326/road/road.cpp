#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

long long n, d;
long long a[100005], v[100005], s[100005];
long long dp[100005];

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    memset(dp, 0x3f, sizeof(dp));
    dp[1] = dp[0] = 0;
    cin >> n >> d;
    for (int i = 1; i <= n-1; i++)
        scanf("%d", &v[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 2; i <= n; i++)
    {
        s[i] = s[i-1] + v[i-1];
    }

    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
        {
            long long x = ceil(1.0*(s[i] - s[j]) / d);
            dp[i] = min (dp[i], dp[j] + x * a[j]);
        }

    cout << dp[n] << endl;
}
