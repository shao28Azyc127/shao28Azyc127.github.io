#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    int ans = 0, cnt = 0;
    bool flag = true;
    while (n > 0)
    {
        cnt++;
        if (flag && n % 3 == 1)
        {
            ans = cnt;
            flag = false;
        }
        if (n % 3 == 1) n -= (n + 2) / 3;
        else if (n % 3 == 2) n -= (n + 1) / 3;
        else n -= n / 3;
    }
    cout << cnt << " " << ans << endl;
    return 0;
}
