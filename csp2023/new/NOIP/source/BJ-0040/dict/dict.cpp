//8:56 T1over.
#include<bits/stdc++.h>
using namespace std;

const int N = 3005, M = 3005;
int n, m;
char a[N][M];
int cnt[N][26];

bool cmp(char a, char b)
{
    return a > b;
}

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf(" %c", &a[i][j]);
            cnt[i][a[i][j] - 'a']++;
        }
        sort(a[i] + 1, a[i] + 1 + m);
    }
    for (int i = 1; i <= n; i++)
    {
        bool ok = true;
        for (int j = 1; j <= n; j++)
        {
            if (j != i)
            {
                if (a[i][1] >= a[j][m])
                {
                    ok = false;
                }
            }
        }
        if (ok) printf("1");
        else printf("0");
    }
    printf("\n");
    return 0;
}
