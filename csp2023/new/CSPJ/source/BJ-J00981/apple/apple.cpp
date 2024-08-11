#include <iostream>
using namespace std;
int n, t, cnt, ans;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    t = n;
    while (t)
    {
        if (t % 3 == 1 && !ans)
            ans = cnt + 1;
        t -= (t + 2) / 3;
        cnt++;
    }
    cout << cnt << " " << ans << endl;
    return 0;
}
