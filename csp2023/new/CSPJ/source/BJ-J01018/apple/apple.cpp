#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, x = 3, a = 0, b = 0;
    scanf("%lld", &n);
    bool ba = 1, bb = 1;
    while (n)
    {
        if (bb)
            b++;
        a++;
        if ((n - 1) % 3 == 0)
            bb = 0;
        n -= (int)ceil(n / 3.0);
    }
    printf("%lld %lld\n", a, b);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
