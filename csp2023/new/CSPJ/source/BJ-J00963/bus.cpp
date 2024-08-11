#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    int n, m, k, ans = 0, now_place = 0;
    cin >> n >> m >> k;
    ans = k;
    now_place = 1;
    for (int i = 0; i <= m; i++)
    {
        int ui, ni, ai;
        cin >> ui >> ni >> ai;
        for (int j = now_place; j <= n; j++)
        {
            if (ui == now_place && ai <= ans)
            {
                ans += 1;
                now_place = ni;
            }
            else
            {
                continue;
            }
        }
        if (now_place == n && n % k == 0)
        {
            cout << ans;
        }
        else
        {
            ans += 3 - n % 2;
            cout << ans;
        }

    }
    return 0;
}
