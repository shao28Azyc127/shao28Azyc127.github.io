#include <bits/stdc++.h>
using namespace std;

int t, m;

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> t >>m;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (b * b - 4 * a * c < 0)
        {
            cout << "NO" << endl;
            continue;
        }

    }
    return 0;
}
