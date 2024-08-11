#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[20005], u[20005], v[20005], l[20005], mi[10005][10005];

int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    int n, m, k;
    cin >> n;
    cin >> m;
    cin >> k;
    for (int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i] >> a[i];
        mi[u[i]][v[i]] = 1;
    }
    if (m <= 15)
    {
        int ans = 0;
        for (int i = 1; i <= m; i++)
        {
            l[i] = i;
        }
        do
        {
            bool flag = false;
            int cnt = 0;
            for (int i = 2; i <= m; i++)
            {
                cnt++;
                if (u[l[i]] != v[l[i - 1]])
                {
                    break;
                }
                if (v[l[i]] == n)
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                ans = max(ans, cnt);
            }
        }while(next_permutation(l + 1, l + 1 + m));
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}
