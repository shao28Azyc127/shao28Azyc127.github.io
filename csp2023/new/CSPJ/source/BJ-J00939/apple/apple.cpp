#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    int cnt = 0, ans;
    bool flag = 1;
    while (n > 0)
    {
        cnt++;
        if (n % 3 == 1 && flag)
        {
            flag = 0;
            ans = cnt;
        }
        n -= (n - 1) / 3 + 1;
    }
    cout << cnt << " " << ans << endl;
    return 0;
}
