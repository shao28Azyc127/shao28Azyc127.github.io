#include<bits/stdc++.h>
using namespace std;

const int N = 3005;
int n, m, f, s;
char w[N][N];

bool check(int x, int y)
{
    for (int i = m;i > 0;i--)
    {
        if (w[x][i] < w[y][i]) return 1;
        if (w[x][i] > w[y][i]) return 0;
    }
    return 0;
}

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    scanf("%d%d", &n, &m);
    w[0][m] = 'z'+1;
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= m;j++)
            while (w[i][j] < 'a' || w[i][j] > 'z') scanf("%c", &w[i][j]);
        if (n == 1)
        {
            puts("1");
            return 0;
        }
        sort(w[i]+1, w[i]+m+1);
        if (check(i, s))
        {
            s = i;
            if (check(s, f)) swap(s, f);
        }
    }
    for (int i = 1;i <= n;i++)
    {
        int p = f;
        if (p == i) p = s;
        bool flag = 1;
        for (int j = 1;j <= m;j++)
        {
            if (w[i][j] < w[p][m-j+1])
            {
                printf("1");
                flag = 0;
                break;
            }
            if (w[i][j] > w[p][m-j+1]) break;
        }
        if (flag) printf("0");
    }
    return 0;
}
