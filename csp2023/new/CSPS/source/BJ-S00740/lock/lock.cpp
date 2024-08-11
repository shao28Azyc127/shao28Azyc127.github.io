#include<cstdio>
#include<iostream>
using namespace std;
struct lock{int x[6];}a[10];
int b[6],n,ans;
bool check()
{
    for (int i = 1;i <= n;i++)
    {
        int pos1 = 0,pos2 = 0;
        for (int j = 1;j <= 5;j++)
            if(a[i].x[j] != b[j])
            {
                if (pos2) return false;
                else if (pos1) pos2 = j;
                else pos1 = j;
            }
        if (!pos1 && !pos2) return false;
        if (pos1 && pos2 && pos1 != pos2 - 1) return false;
        if (pos1 && pos2
        && ((a[i].x[pos1] - b[pos1]) % 10 + 10) % 10 != ((a[i].x[pos2] - b[pos2]) % 10 + 10) % 10)
            return false;
    }
    return true;
}
void dfs(int step)
{
    if (step > 5)
    {
        if(check()) ans++;
        return;
    }
    for (int i = 0;i <= 9;i++)
    {
        b[step] = i;
        dfs(step + 1);
    }
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= 5;j++)
            scanf("%d",&a[i].x[j]);
    dfs(1);
    printf("%d\n",ans);
    return 0;
}
