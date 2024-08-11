#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, l, index = 1, first, d = 0;
    scanf("%d", &n);
    l = n;
    bool f[n + 5];
    for (int i = 1; i <= n; i++)
    {
        f[i] = true;
    }
    int i = 1;
    while (l >= 1)
    {
        d++;
        for (int i = index; i <= n; )
        {
            f[i] = false;
            l--;
            if (i == n)
            {
                first = d;
            }
            int cnt = 0;
            while (cnt < 3)
            {
                i++;
                cnt += f[i];
            }
        }
        do
        {
            index++;
        } while (!f[index]);
    }
    printf("%d %d", d, first);
    return 0;
}
