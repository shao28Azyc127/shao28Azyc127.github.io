#include <bits/stdc++.h>

using namespace std;

int n;
int a[30][10], wr[30];//wr mean wrong
int tmp[100000];

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= 5; j++) scanf("%d", &a[i][j]);
    if (n == 1)
    {
        printf("81");
        return 0;
    }
    int wr_cnt = 0;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= n; j++)
            if (a[j][i] != a[1][i]) wr[i] = 1, wr_cnt++;
    }
    if (wr_cnt > 2)
    {
        printf("0");
        return 0;
    }
    for (int i = 2; i < n; i++)
        if (wr_cnt == 2 && wr[i] == 1 && wr[i] == 0 && wr[i + 1] == 0)
        {
            printf("0");
            return 0;
        }
    if (wr_cnt == 0)
    {
        printf("81");
    }
    else if (wr_cnt == 1)
    {
        int cnt = 0, ans = 0, wr_pos;
        for (int i = 1; i <= 5; i++)
            if (wr[i])
                for (int j = 1; j <= n; j++)
                    if (tmp[a[j][i]] == 0)
                    {
                        wr_pos = i;
                        cnt++;
                        tmp[a[j][i]] = 1;
                    }
        ans += (10 - cnt);
        if (cnt == 2)
        {
            if (wr_pos == 1 || wr_pos == 5) ans += 2;
            else wr_pos += 2;
        }
        printf("%d", ans);
    }
    else if (wr_cnt == 2)
    {
        int ans = 0, wr_pos1, wr_pos2;
        for (int i = 1; i <= 5; i++)
            if (wr[i]) wr_pos1 = i, wr_pos2 = i + 1;
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (tmp[a[i][wr_pos1] - a[i][wr_pos2] + 20] == 0)
            {
                cnt++;
                tmp[a[i][wr_pos1] - a[i][wr_pos2] + 20] = 1;
            }
        }
        if (cnt > 2) printf("0");
        else if (cnt == 1)
        {
            memset(tmp, 0, sizeof(tmp));
            int ans = 0;
            for (int i = 1; i <= n; i++)
                if (tmp[a[i][wr_pos1]] == 0)
                {
                    ans++;
                    tmp[a[i][wr_pos1]] = 1;
                }
            ans = 10 - ans;
            printf("%d", ans);
        }
        else if (cnt == 2)
        {
            int num = 0;
            for (int i = 1; i <= n; i++)
                if (tmp[a[i][1] * 10000 + a[i][2] * 1000 + a[i][3] * 100 + a[i][4] * 10 + a[i][5]] == 0)
                {
                    num++;
                    tmp[a[i][1] * 10000 + a[i][2] * 1000 + a[i][3] * 100 + a[i][4] * 10 + a[i][5]] = 1;
                }
            if (num == 2) printf("2");
            else printf("0");
        }
    }
    return 0;
}
