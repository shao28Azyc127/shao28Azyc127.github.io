#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int a[15][15];
bool flag[15];
int cnt = 0;
bool two = 0;
int ans = 0;

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);

    cin >> n;
    for (int i = 1;i <= n;i ++)
        for (int j = 1;j <= 5;j ++)
            cin >> a[i][j];

    if (n == 1)
    {
        cout << 81;
    }
    else
    {
        for (int j = 1;j <= 5;j ++)
        {
            for (int i = 2;i <= n;i ++)
                if (a[i][j] != a[i - 1][j])
                {
                    flag[j] = 1;
                    cnt ++;
                    if (flag[j - 1])
                        two = 1;
                    break;
                }
        }

        if (cnt == 1)
            cout << 10;
        else if (cnt == 2 && two)
            cout << 10;
        else
            cout << 0;
    }
    return 0;
}
