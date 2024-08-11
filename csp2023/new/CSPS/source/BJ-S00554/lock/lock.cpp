#include <cstdio>
using namespace std;
int n,a[13][10],b[10],ans = 0;
inline void dfs(int x)
{
    if (x <= 5)
    {
        for (int i = 0;i <= 9;i++)
        {
            b[x] = i;
            dfs(x + 1);
        }
    }
    else
    {
        for (int i = 1;i <= n;i++)
        {
            int pos = 0,d = 0;
            bool flag = false;
            for (int j = 1;j <= 5;j++)
                if (b[j] != a[i][j])
                {
                    if (pos)
                    {
                        if (pos != j - 1)
                            return;
                        if (d != (b[j] - a[i][j] + 10) % 10)
                            return;
                    }
                    else
                    {
                        pos = j;
                        d = (b[j] - a[i][j] + 10) % 10;
                    }
                    flag = true;
                }
            if (!flag)
                return;
        }
        ans++;
    }
    return;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= 5;j++)
            scanf("%d",&a[i][j]);
    dfs(1);
    printf("%d\n",ans);
    return 0;
}