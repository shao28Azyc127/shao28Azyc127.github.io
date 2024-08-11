#include<bits/stdc++.h>
using namespace std;

const int N = 15005;
int n, o[N][27], ans;
char c[N];
bool b[N][N];

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d%s", &n, c);
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < 26;j++) o[i+1][j] = o[i][j];
        o[i+1][c[i] - 'a']++;
    }
    for (int i = 0;i+1 < n;i++) b[i+1][i] = 1;
    for (int l = 1;l <= n/2;l++)
    {
        for (int i = 0;i + l*2 - 1 < n;i++)
        {
            int j = i + l*2 - 1;
            if (c[i] == c[j] && b[i+1][j-1])
            {
                ans++;
                b[i][j] = 1;
                continue;
            }
            bool flag = 0;
            for (int k = 0;k < 26;k++)
            {
                if ((o[j+1][k] - o[i][k]) & 1)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag) continue;
            for (int k = i+1;k <= j-2;k += 2)
            {
                if (b[i][k] && b[k+1][j])
                {
                    ans++;
                    b[i][j] = 1;
                    break;
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}
