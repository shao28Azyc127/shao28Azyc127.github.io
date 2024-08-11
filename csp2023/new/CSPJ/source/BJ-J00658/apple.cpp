#include <bits/stdc++.h>
using namespace std;
int n, cnt, ans;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    while (n > 0)
    {
        cnt++;
        if (n % 3 == 1 && ans == 0)
        {
            ans = cnt;
        }
        n = n - (n+2) / 3;
    }
    cout << cnt << " " << ans;
    return 0;
}