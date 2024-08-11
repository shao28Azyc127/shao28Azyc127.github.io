#include <iostream>
#include <cstdio>
using namespace std;

int a[1000005];

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    int n, s, cnt = 0, x = 0, y;
    cin >> n;
    while (true)
    {
        s = -1;
        for (int i = 1; i <= n; i++)
        {
            if (!a[i])
            {
                s = i;
                break;
            }
        }
        if (s == -1)
        {
            cout << x << ' ' << y + 1;
            return 0;
        }
        cnt = 3;
        for (int i = s; i <= n; i++)
        {
            if (!a[i])
            {
                cnt++;
                if (cnt >= 3)
                {
                    cnt = 0;
                    a[i] = 1;
                    if (i == n)
                        y = x;
                }
            }
        }
        x++;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
