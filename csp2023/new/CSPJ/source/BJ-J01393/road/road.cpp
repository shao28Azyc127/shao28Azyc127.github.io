#include <iostream>

#define reg register
#define rep(i, a, b) for (int i = a; i <= b; i = -~i)

using namespace std;

const int maxn = 1e6 + 10;

#define int long long

int n, d;
int a[maxn], v[maxn], s[maxn], p[maxn];

signed main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
    freopen("road.in" ,"r", stdin);
    freopen("road.out", "w", stdout);
    
    cin >> n >> d;
    rep(i, 1, n - 1) cin >> v[i], s[i + 1] = s[i] + v[i], p[i] = s[i] % d == 0 ? s[i] / d - 1 : s[i] / d;
    p[n] = s[n] % d == 0 ? s[n] / d - 1 : s[n] / d, p[1] = -1;
    // rep (i, 1, n) cout << p[i] << " "; cout << "\n";
    rep(i, 1, n) cin >> a[i]; 
    int ans = 0ll;
    for (int i = 1; i <= n; )
    {
        int j = i;
        while (j + 1 <= n && a[i] <= a[j]) j++;
        // cout << i << " " << j << " " << (p[j] - p[i]) * a[i] << "\n";
        ans += (p[j] - p[i]) * a[i];
        if (j == n) break;
        i = j;
    }
    cout << ans << "\n";
    return 0;
}