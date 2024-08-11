#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, ans = -1, day, tmp;

signed main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    while(n > 0)
    {
        day++;
        tmp = ceil(1.0 * n / 3);
        if(n % 3 == 1 && ans == -1) ans = day;
        n -= tmp;
    }
    cout << day << " " << ans << endl;
    return 0;
}
