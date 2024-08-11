#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    long long int n, m, x, p = 0;
    long long int ans2 = -1;
    int a[1000005];
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a[i] = 1;
    }
    m = n;
    while (m != 0)
    {
        x = 1;
        p++;
        for(int i = 1; i <= n; i++)
        {
            if(a[i] == 1)
            {
                x = i;
                break;
            }
        }
        int y = 0;
        a[x] = 0;
        m--;
        if(x == n)
        {
            ans2 = p;
        }
        y = 0;
        for (int i = x + 1; i <= n; i++)
        {
            if(a[i] == 1)
            {
                y++;
            }
            if(y == 3)
            {
                a[i] = 0;
                m--;
                y = 0;
            }
            if(i == n && a[i] == 0 && ans2 == -1)
            {
                ans2 = p;
            }
        }

    }
    cout << p << " " << ans2;
    return 0;
}
