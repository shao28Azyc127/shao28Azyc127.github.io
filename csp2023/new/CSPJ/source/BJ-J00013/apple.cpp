#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a, k, t;
signed main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    a = n;
    while (a)
    {
        t++;
        if (a % 3 == 1 && k == 0)
        {
            k = t;
        }
        a = (a * 2) / 3;
    }
    cout << t << " " << k;
    return 0;
}