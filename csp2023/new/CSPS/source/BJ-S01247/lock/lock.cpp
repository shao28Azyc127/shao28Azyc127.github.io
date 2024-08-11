#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin >> n;
    int a[17][17];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 5; j++)
            cin >> a[i][j];
    if (n == 1)
        cout << 81;
    else
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int cnt = 0, k1, k2;
                for (int k = 1; k <= 5; k++)
                {
                    if (a[i][k] != a[j][k])
                    {
                        cnt++;
                        if (cnt == 0)
                            k1 = k;
                        else if (cnt == 1)
                            k2 = k;
                    }
                }
                if (cnt > 2)
                {
                    cout << 0;
                    return 0;
                }
                else if (cnt == 2 && abs(k2 - k1) != 1)
                {
                    cout << 0;
                    return 0;
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
