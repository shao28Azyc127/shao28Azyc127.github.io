#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 3005;
const int MAXM = 3005;

int n, m;
char a1[MAXN][MAXM], a2[MAXN][MAXM];

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> a1[i];

        for (int j = 0; j < m; j++)
        {
            a2[i][j] = a1[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        sort(a1[i], a1[i]+m);
        sort(a2[i], a2[i]+m, greater<char>());
    }

    for (int i = 1; i <= n; i++)
    {
        bool flag = true;
        for (int j = 1; j <= n && (flag == true); j++)
        {
            if (i == j)
            {
                continue;
            }

            int k = 0;
            for (k = 0; k < m; k++)
            {
                if (a1[i][k] > a2[j][k])
                {
                    flag = false;
                    break;
                }
                if (a1[i][k] < a2[j][k])
                {
                    break;
                }
            }

            if (k == m)
            {
                flag = false;
            }
        }

        if (flag)
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
    }
    cout << "\n";

    return 0;
}