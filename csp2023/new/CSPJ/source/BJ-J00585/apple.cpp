#include <bits/stdc++.h>

using namespace std;
int n, ti, ans;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    cin >> n;
    ti = 0;
    ans = ti;
    while (n)
    {
        ti++;
        if (n % 3 == 1 && ans == 0)
        {
            ans = ti;
        }
        int nn = n - n / 3;
        if (n % 3 > 0)
        {
            nn--;
        }
        n = nn;
    }
    cout << ti << " " << ans;
    return 0;
}
