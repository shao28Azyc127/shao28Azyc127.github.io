#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m;
    cin >> t >> m;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        ll dirta = b * b - 4 * a * c;
        if (dirta < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        ll sq = sqrt(dirta);
        ll x = sq - b;
        x /= (2 * a);
        cout << x << endl;
    }
    return 0;
}
