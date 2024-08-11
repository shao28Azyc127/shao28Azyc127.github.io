#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


bool sf,f[1000005];

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, s = 1, ans1 = 0, ans2, cnt = 0, x;
    scanf("%d", &n);
    while (cnt != n)
    {
        x = 0;
        sf = false;
        for (int i = s; i <= n; i++)
        {
            if (!f[i])
            {
                x++;
                if (x == 3) x = 0;
                if (!sf && x != 0)
                {
                    sf = true;
                    s = i;
                }
                if (x == 0)
                {
                    f[i] = true;
                    cnt++;
                    if (i == n)
                        ans2 = i;
                }
            }
        }
        ans1++;
    }
    printf("%d\n%d\n", ans1, ans2);
    return 0;
}