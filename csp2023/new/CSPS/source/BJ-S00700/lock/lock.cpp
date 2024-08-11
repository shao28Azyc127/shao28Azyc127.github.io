#include <iostream>
using namespace std;
int n, a[15][5], ans, l, t, tmp, cnt;
bool flag;
int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 5; j++)
            cin >> a[i][j];
    for (int i = 0; i < 100000; i++)
    {
        flag = true;
        for (int j = 1; j <= n; j++)
        {
            t = i;
            l = 0;
            for (int k = 4; k >= 0; k--)
            {
                tmp = (a[j][k] + 10 - t % 10) % 10;
                if (l && (tmp == l || !tmp))
                    l = 10;
                else if (l)
                    flag = false;
                else
                    l = tmp;
                t /= 10;
            }
            if (!l)
                flag = false;
        }
        if (flag)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}
