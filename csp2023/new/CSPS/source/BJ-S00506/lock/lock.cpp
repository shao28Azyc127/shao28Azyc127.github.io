#include <iostream>
#include <cstdio>
#include <cstring>
#include <bitset>
using namespace std;

int n, a[5], x, y;
bitset <100005> f, now;

inline int id()
{
    return a[0]*10000 + a[1]*1000 + a[2]*100 + a[3]*10 + a[4];
}

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);

    for(int i = 1; i <= 100000; i++)  f[i] = true;

    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        now = 0;

        for(int j = 0; j < 5; j++)  scanf("%d", &a[j]);
        for(int j = 0; j < 5; j++)
        {
            for(int k = 1; k <= 9; k++)
            {
                a[j] = (a[j] + 1) % 10;
                now[id()] = true;
            }
            a[j] = (a[j] + 1) % 10;

            if(j > 0)
            {
                for(int k = 1; k <= 9; k++)
                {
                    a[j] = (a[j] + 1) % 10;
                    a[j + 1] = (a[j + 1] + 1) % 10;
                    now[id()] = true;
                }
                a[j] = (a[j] + 1) % 10;
                a[j + 1] = (a[j + 1] + 1) % 10;
            }
            if(j < 4)
            {
                for(int k = 1; k <= 9; k++)
                {
                    a[j] = (a[j] + 1) % 10;
                    a[j - 1] = (a[j - 1] + 1) % 10;
                    now[id()] = true;
                }
                a[j] = (a[j] + 1) % 10;
                a[j - 1] = (a[j - 1] + 1) % 10;
            }
        }
        f = f & now;
    }
    printf("%d\n", int(f.count()));
    return 0;
}
