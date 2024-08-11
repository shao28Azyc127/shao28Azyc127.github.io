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

//9:06 AC T1

signed main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    srand(time(0) + 2327);
    int n, d = 0, ans = 0;
    cin >> n;
    while(n >= 3)
    {
        d++;
        if(ans == 0 && n % 3 == 1)ans = d;
        n -= ((n - 1) / 3 + 1);
    }
    if(ans == 0)ans = d + n;
    cout << d + n << " " << ans;
    return 0;
}
