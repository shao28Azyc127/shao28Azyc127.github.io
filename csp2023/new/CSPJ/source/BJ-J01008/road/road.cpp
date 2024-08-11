#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int NR = 1e5+4;
long long dp[NR]; //
int n, d;
int v[NR];
int a[NR];
long long s[NR];
int main()
{
    //freopen("road1.in", "r", stdin);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    bool A = true, B = true;
    for(int i = 1; i < n; i++) scanf("%d", &v[i]), s[i+1] = s[i] + v[i], B &= (v[i] % d == 0);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]), A &= (a[1] <= a[i]);
    if(A)
    {
        cout << ceil(1.0 * s[n] / d) * a[1] << endl;
        return 0;
    }
    dp[1] = 0;
    for(int i = 2; i <= n; i++)
    {
        dp[i] = 1e18;
        for(int j = 1; j < i; j++)
            dp[i] = min(dp[i],(long long)(dp[j] + ceil(1.0 * (s[i] - s[j]) / d) * a[j]));
        //cout << i << ' ' << dp[i] << endl;
    }
    cout << dp[n] << endl;
    return 0;
}
