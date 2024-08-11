#include <bits/stdc++.h>
using namespace std;

bool f[1000010];

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    int j = 0, m = 0;
    for (int i = 1; i <= n; i++)
    {
        f[i] = true;
    }
    while (true)
    {
        j++;
        int x = 0;
        for (int i = 1; i <= n; i++)
        {
            x %= 3;
            if (x == 0 && f[i])
            {
                f[i] = false;
                x++;
                if (i == n)
                {
                    m = j;
                }
            }
            if (f[i])
            {
                x++;
            }
        }
        bool b = true;
        for (int i = 1; i <= n; i++)
        {
            if (f[i])
            {
                b = false;
                break;
            }
        }
        if (b)
        {
            break;
        }
    }
    cout << j << " " << m << endl;
    return 0;
}
