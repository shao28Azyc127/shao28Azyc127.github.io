#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m;
    cin >> t >> m;
    for (int i = 1; i <= t; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int trng = b * b - 4 * a * c;
        if (trng < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        else
        {
            int maxn = -1e9;
            for (int i = -m; i <= m; i++)
            {
                if (a * i * i + b * i + c == 0)
                {
                    if (maxn < i)
                    {
                        maxn = i;
                    }
                }
            }
            cout << maxn << endl;
            continue;
        }
    }
    return 0;
}
