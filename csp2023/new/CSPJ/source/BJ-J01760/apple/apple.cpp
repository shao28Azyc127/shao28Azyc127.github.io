#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, i, ans = 0;
    cin >> n;
    for (i = 1; 1; i++)
    {
        if ((n - 1) % 3 == 0 && ans == 0)
            ans = i;
        n = n - (n - 1) / 3 - 1;
        if (n == 0)
            break;
    }
    cout << i << " " << ans << endl;
    return 0;
}
