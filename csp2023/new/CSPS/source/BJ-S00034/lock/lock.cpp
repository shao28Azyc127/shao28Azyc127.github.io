#include <iostream>
#include <cstdio>
using namespace std;

int n;
int r[10][6] = {};
int d[10][100][6] = {};

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            cin >> r[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int cnt = 1;
        for (int q = 1; q <= 81; q++)
        {
            for (int j = 1; j <= 5; j++)
            {
                d[i][cnt][j] = r[i][j];
            }
            cnt++;
        }

        cnt = 0;
        for (int x = 1; x <= 5; x++)
        {
            for (int y = 0; y <= 9; y++)
            {
                if (r[i][x] != y)
                {
                    d[i][++cnt][x] = y;
                }
            }
        }

        for (int x = 1; x <= 4; x++)
        {
            for (int y = 1; y <= 9; y++)
            {
                cnt++;
                d[i][cnt][x] = (r[i][x] + y) % 10;
                d[i][cnt][x+1] = (r[i][x+1] + y) % 10;
            }
        }
    }

    if (n == 1) cout << 81 << endl;
    else
    {
        int sum = 0;
        for (int j = 1; j <= 81; j++)
        {
            int flag = 0;
            for (int i = 2; i <= n; i++)
            {
                for (int k = 1; k <= 81; k++)
                {
                    if (d[1][j][1] == d[i][k][1] && d[1][j][2] == d[i][k][2] && d[1][j][3] == d[i][k][3] && d[1][j][4] == d[i][k][4] && d[1][j][5] == d[i][k][5])
                    {
                        flag++;
                        break;
                    }
                }
                if (flag != i - 1) break;
            }
            if (flag == n - 1) sum++;
        }
        cout << sum << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
