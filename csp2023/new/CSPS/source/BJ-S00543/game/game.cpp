#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;
typedef long long ll;
const ll N = 4e6 + 5;

int n, m;
string s, t;
ll rf[N], dp[N];

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d", &n);
    cin >> s;
    rf[n] = n;
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        ll j = i + 1;
        while (j < n && s[j] != s[i]) j = rf[j] + 1;
        rf[i] = j;
        if (j < n)
        {
            dp[i] = dp[j + 1] + 1;
        }
        ans += dp[i];
    }
    cout << ans << endl;
    return 0;
}
