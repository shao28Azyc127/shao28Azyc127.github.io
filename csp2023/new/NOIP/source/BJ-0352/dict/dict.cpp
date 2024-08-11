#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,mn[3005],mx[3005];
bool c[3005][3005];
char s[3005];
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n;i++)
    {
        scanf("%s",s + 1);
        mn[i] = 27;
        mx[i] = 0;
        for (int j = 1;j <= m;j++)
        {
            int x = s[j] - 'a' + 1;
            mn[i] = min(mn[i],x);
            mx[i] = max(mx[i],x);
        }
    }
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            if (mn[i] < mx[j])
                c[i][j] = true;
    for (int i = 1;i <= n;i++)
    {
        bool flag = true;
        for (int j = 1;j <= n;j++)
            if (j != i && c[i][j] == false)
            {
                flag = false;
                break;
            }
        if (flag == true)
            printf("1");
        else
            printf("0");
    }
    return 0;
}