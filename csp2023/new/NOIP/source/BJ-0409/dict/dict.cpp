#include <cstdio>
#include <iostream>
using namespace std;

const int N = 3005, M = 30;

int n, m, cnt[N][M], sum[N][M], first[N];
char s[N];

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        cin >> s + 1;
        for (int j = 1; j <= m; j++) cnt[i][s[j] - 'a' + 1]++;
        for (int j = 1; j <= 26; j++)
        {
            sum[i][j] = sum[i][j - 1] + cnt[i][j];
            if (sum[i][j] && sum[i][j - 1] == 0) first[i] = j;
        }
    }
    if (m == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            int flag = 0;
            for (int j = 1; j <= n; j++)
            {
                if (j == i) continue;
                if (sum[j][first[i]] == m && cnt[j][first[i]] <= cnt[i][first[i]])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag) printf("0");
            else printf("1");
        }
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        int flag = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i == j) continue;
            if (sum[j][first[i]] < m) continue;
            if (cnt[j][first[i]] > cnt[i][first[i]]) continue;
            flag = 1;
            break;
        }
        if (flag) printf("0");
        else printf("1");
    }
    return 0;
}