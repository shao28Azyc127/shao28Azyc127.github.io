#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    int i, j;
    int c, T;
    cin >> c >> T;
    while(T--)
    {
        int n, m, k, d;
        cin >> n >> m >> k >> d;
        long long int ans = 0;
        int x, y, v;
        for(i=1; i<=m; i++)
        {
            cin >> x >> y >> v;
            if(y > k) continue;
            if(x - y + 1 < 1) continue;
            if(1ll * y * d < 1ll * v)
            {
                ans += 1ll * v - 1ll * y * d;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
