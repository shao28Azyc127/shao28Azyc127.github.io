#include <bits/stdc++.h>
using namespace std;
int n;
int a[100][100];
bool vis[10][1000005];
int ans;
int v[5] = {1, 10, 100, 1000, 10000};
int res, tmp, tmp1, tmp2, cnt;
int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    memset(vis, false, sizeof(vis));
    for(int i = 1;i <= n;i ++)
    {
        for(int j = 1;j <= 5;j ++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 1;i <= n;i ++)
    {
        tmp = 0;
        for(int j = 1;j <= 5;j ++)
        {
            tmp += v[5 - j] * a[i][j];
        }
        for(int j = 1;j <= 5;j ++)
        {
            for(int h = 1;h <= 9;h ++)
            {
                tmp1 = a[i][j] + h;
                tmp1 %= 10;
                res = tmp - v[5 - j] * a[i][j] + v[5 - j] * tmp1;
                vis[i][res] = true;
                //cout << res << " ";
                cnt ++;
            }
            //cout << endl;
        }
        for(int j = 1;j <= 4;j ++)
        {
            for(int h = 1;h <= 9;h ++)
            {
               tmp -= v[5 - j] * a[i][j] + v[5 - j - 1] * a[i][j + 1];
               tmp1 = a[i][j] + h;
               tmp1 %= 10;
               tmp2 = a[i][j + 1] + h;
               tmp2 %= 10;
               res = tmp + v[5 - j] * tmp1 + v[5 - j - 1] * tmp2;
                   //cout << res << " ";
               vis[i][res] = true;
               tmp += v[5 - j] * a[i][j] + v[5 - j - 1] * a[i][j + 1];
               cnt ++;
            }
            //cout << endl;
        }
    }
    bool ok = true;
    for(int i = 0;i <= 100000;i ++)
    {
        ok = true;
        for(int j = 1;j <= n;j ++)
        {
            if(vis[j][i] == false)
            {
                ok = false;
            }
        }
        if(ok == true)
        {
            ans ++;
        }
    }
    printf("%d", ans);
    return 0;
}
