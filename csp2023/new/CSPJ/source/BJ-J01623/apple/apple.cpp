#include <iostream>
using namespace std;

int n, ans1, ans2;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    while (n > 0)
    {
        ans1++;
        if (ans2 == 0 && n % 3 == 1)
        {
            ans2 = ans1;
        }
        n -= (n + 2) / 3;
    }
    cout << ans1 << " " << ans2;
    return 0;
}
