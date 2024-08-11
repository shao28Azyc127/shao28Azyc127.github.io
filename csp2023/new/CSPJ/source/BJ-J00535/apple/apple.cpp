#include <bits/stdc++.h>
using namespace std;

int n, ans, i;
bool flag = 1;

int main ()
{
    freopen ("apple.in", "r", stdin);
    freopen ("apple.out", "w", stdout);
    cin >> n;
    while (n != 0)
    {
        i ++;
        if (n % 3 == 1 && flag)
        {
            ans = i;
            flag = 0;
        }
        n -= (n + 2) / 3;
    }
    cout << i << " " << ans;
    return 0;
}
