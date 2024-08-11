#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int n, ans, cnt;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    while (n)
    {
        cnt++;
        if (n % 3 == 1 && !ans) ans = cnt;
        int x = n % 3, y = n / 3;
        if (x == 0) n -= y;
        else n -= (y + 1);
    }
    cout << cnt << " " << ans << '\n';
    return 0;
}
