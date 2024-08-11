#include <cstdio>

#define N 10
#define M 100000 + 10

int n;
int a[N][5];
int vis[M];

inline void change1(int pos)
{
    for (int i = 0; i < 5; i++)
        for (int x = 0; x <= 9; x++)
            if (x != a[pos][i])
            {
                int t = 0;
                for (int j = 0; j < i; j++)
                    t = t * 10 + a[pos][j];
                t = t * 10 + x;
                for (int j = i + 1; j < 5; j++)
                    t = t * 10 + a[pos][j];
                vis[t]++;
            }
}

inline void change2(int pos)
{
    for (int i = 0; i < 4; i++)
        for (int x = 1; x <= 9; x++)
        {
            int t = 0;
            for (int j = 0; j < i; j++)
                t = t * 10 + a[pos][j];
            t = t * 10 + (a[pos][i] + x) % 10;
            t = t * 10 + (a[pos][i + 1] + x) % 10;
            for (int j = i + 2; j < 5; j++)
                t = t * 10 + a[pos][j];
            vis[t]++;
        }
}

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 5; j++)
            scanf("%d", &a[i][j]);

    for (int i = 0; i < n; i++)
    {
        change1(i);
        change2(i);
    }

    int ans = 0;
    for (int i = 0; i < M; i++)
        if (vis[i] == n)
            ans++;

    printf("%d\n", ans);

    fclose(stdin);
    fclose(stdout);

    return 0;
}