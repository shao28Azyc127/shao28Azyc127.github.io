#include <bits/stdc++.h>
using namespace std;
int n,ans,a[10][10],box[10];
void dfs(int cur)
{
    if (cur > 5)
    {
        for (int i = 1; i <= n; i++)
        {
            int cnt = 0,change[5] = {0,0,0,0,0},idx[5] = {0,0,0,0,0};
            for (int j = 1; j <= 5; j++)
            {
                if (box[j] != a[i][j])
                {
                    idx[cnt] = j;
                    change[cnt++] = box[j] - a[i][j];
                    if (cnt > 2) return;
                }
            }
            if (!cnt) return;
            if (cnt == 2 && change[0] != change[1] || idx[0] + 1 < idx[1]) return;
        }
        ans++;
        return;
    }
    for (int i = 0; i <= 9; i++)
    {
        box[cur] = i;
        dfs(cur + 1);
    }
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 5; j++) scanf("%d", &a[i][j]);
    if (n == 1)
    {
        printf("81");
        return 0;
    }
    dfs(1);
    printf("%d", ans);
    return 0;
}