#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read()
{
    register int x = 0, f = 1;
    register char c = getchar();
    while(c < '0' || c > '9')
    {
        if(c == '-')f = -1;
        c = getchar();
    }
    while(c <= '9' && c >= '0')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

//9:17 AC T2

int n, d, v[100010], a[100010];

signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    srand(time(0) + 2327);
    n = read(), d = read();
    for(int i = 2;i <= n;i++)
    {
        v[i] = read();
    }
    for(int i = 1;i <= n;i++)
    {
        a[i] = read();
    }
    int l = 0, w = a[1], ans = 0;
    for(int i = 2;i <= n;i++)
    {
        if(l >= v[i])
        {
            l -= v[i];
            w = min(w, a[i]);
            continue;
        }
        if((v[i] - l) % d == 0)
        {
            ans += (v[i] - l) / d * w;
            l = 0;
        }
        else
        {
            int steps = ((v[i] - l) / d + 1);
            ans += steps * w;
            l = steps * d - (v[i] - l);
        }
        w = min(w, a[i]);
    }
    cout << ans;
    return 0;
}