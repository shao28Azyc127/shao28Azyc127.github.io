#include <cstdio>
using namespace std;
int ans[100010],a[10],cnt;

int calc()
{
    int now = 0;
    for (int i = 1;i<=5;i++)
        now = now*10+a[i];
    return now;
}

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    scanf("%d",&n);
    for (int i = 1;i<=n;i++)
    {
        for (int j = 1;j<=5;j++)
        {
            scanf("%d",&a[j]);
        }
        ans[calc()] = -1;
        for (int j = 1;j<=5;j++)
        {
            for (int k = 1;k<=9;k++)
            {
                a[j] = (a[j]+1)%10;
                ans[calc()]++;
            }
            a[j] = (a[j]+1)%10;
        }
        for (int j = 1;j<=4;j++)
        {
            for (int k = 1;k<=9;k++)
            {
                a[j] = (a[j]+1)%10;
                a[j+1] = (a[j+1]+1)%10;
                ans[calc()]++;
            }
            a[j] = (a[j]+1)%10;
            a[j+1] = (a[j+1]+1)%10;
        }
    }
    for (int i = 0;i<=99999;i++)
        if(ans[i] == n)
            cnt++;
    printf("%d\n",cnt);
    return 0;
}