#include <iostream>
#include <cstdio>

using namespace std;

#define MAXN 100005

/*
WISH
*/

int t[MAXN], tenn[MAXN], t1[MAXN];

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);

    int n;
    cin >> n;

    int mul = 1;
    for(int i = 1; i <= 5; i ++)
    {
        tenn[i] = mul;
        mul *= 10;
    }

    for(int i = 1; i <= n; i ++)
    {
        int a[6], num = 0;

        for(int j = 1; j <= 5; j ++)
        {
            cin >> a[j];
            num += a[j] * tenn[j];
        }
        t1[num] ++;

        for(int j = 1; j <= 5; j ++)
        {
            int nm = num - a[j] * tenn[j];

            for(int k = 0; k <= 9; k ++)
            {
                t[nm + k * tenn[j]] ++;

                if(j <= 4)
                {
                    int tm = nm - a[j + 1] * tenn[j + 1];
                    int s = a[j + 1] - a[j] + k;

                    if(s >= 10)  s -= 10;
                    if(s < 0)  s += 10;

                    t[tm + k * tenn[j] + s * tenn[j + 1]] ++;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= 99999; i ++)
        if(t[i] == n && !t1[i])
            ans ++;

    cout << ans << endl;
    return 0;
}
