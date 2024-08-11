#include <iostream>
using namespace std;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, cnt = 0, ans = 2e9;
    cin >> n;
    while (n != 0)
    {
        cnt++;
        if (n % 3 == 1)
        {
            ans = min(ans, cnt);
        }
        n -= (n + 2) / 3;
    }
    cout << cnt << ' ' << ans << endl;
    return 0;
}
