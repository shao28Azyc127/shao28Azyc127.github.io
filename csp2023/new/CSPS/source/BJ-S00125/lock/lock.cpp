#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 10, M = 5;
int n, a[N][M], b[M], res = 0;

bool good(int x, int y, int u, int v)
{
    return ((u + y - x - v) % 10 == 0);
}

int check()
{
    for (int i = 0; i < n; ++ i )
    {
        int t[5], c = 0;
        for (int j = 0; j < 5; ++ j )
            if (a[i][j] != b[j])
                t[j] = 1, ++ c;
            else
                t[j] = 0;
        if (c >= 3 || c == 0) return 0;
        if (c == 1) continue;

        int j = 0;
        while(t[j] == 0) ++ j;
        if (t[j + 1] == 0) return 0;
        if (!good(a[i][j], a[i][j + 1], b[j], b[j + 1]))
            return 0;
    }

    return 1;
}

void dfs(int k)
{
    if (k == 5)
    {
        if (check())
        {
            ++ res;
            /*for (int j = 0; j < 5; ++ j )
                printf("%d ", b[j]);
            puts("");*/
        }
        return;
    }
    for (int i = 0; i < 10; ++ i )
    {
        b[k] = i;
        dfs(k + 1);
    }
}

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++ i )
        for (int j = 0; j < M; ++ j )
            scanf("%d", &a[i][j]);

    dfs(0);
    printf("%d\n", res);

    fclose(stdin);
    fclose(stdout);

    return 0;
}
