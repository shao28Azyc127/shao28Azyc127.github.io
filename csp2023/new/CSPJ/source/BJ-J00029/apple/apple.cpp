#include <iostream>
#include <cmath>
using namespace std;

int my(int x, int y)
{
    if (x % y == 0) return x / y;
    return x / y + 1;
}

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    // cout << my(n, 3) << endl;
    int cnt = 0, ans = -1;
    while (n > 0)
    {
        cnt++;
        if (n % 3 == 1 && ans == -1) ans = cnt;
        n -= my(n, 3);
        // cout << ans <<" " << cnt << " " << n <<endl;
    }
    // cout << 1 << endl;
    cout << cnt << " " << ans << endl;
    return 0;
}
