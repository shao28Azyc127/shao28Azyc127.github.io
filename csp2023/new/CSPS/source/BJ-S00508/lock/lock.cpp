#include <cstdio>
using namespace std;

int n;
int x[10][10];

bool chk(int a, int b, int c, int d, int e, int i)
{
    int d1 = (a - x[i][1] + 10) % 10;
    int d2 = (b - x[i][2] + 10) % 10;
    int d3 = (c - x[i][3] + 10) % 10;
    int d4 = (d - x[i][4] + 10) % 10;
    int d5 = (e - x[i][5] + 10) % 10;
    int cnt = bool(d1) + bool(d2) + bool(d3) + bool(d4) + bool(d5);
    if (cnt == 1) return true;
    if (cnt == 2)
        if ((d1 && d2 && d1 == d2) || (d2 && d3 && d2 == d3) || (d3 && d4 && d3 == d4) || (d4 && d5 && d4 == d5)) return true;
    return false;
}

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 5; j++)
            scanf("%d", &x[i][j]);
    int ans = 0;
    for (int a = 0; a <= 9; a++)
        for (int b = 0; b <= 9; b++)
            for (int c = 0; c <= 9; c++)
                for (int d = 0; d <= 9; d++)
                    for (int e = 0; e <= 9; e++)
                    {
                        bool flag = true;
                        for (int i = 1; i <= n; i++)
                            if (!chk(a, b, c, d, e, i))
                            {
                                flag = false;
                                break;
                            }
                        if (flag) ans++;
                    }
    printf("%d", ans);
    return 0;
}