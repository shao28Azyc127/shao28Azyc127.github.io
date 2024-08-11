#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[500001],b[500001],aa[500001],bb[500001];
bool dp[2001][2001];
bool work()
{
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    int mx;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
        {
            mx = b[j];
            if(mx < a[i]) dp[i][j] |= dp[i-1][j];
            for(int k = j-1;k >= 0;k--)
            {
                if(mx >= a[i]) break;
                dp[i][j] |= dp[i-1][k];
                mx = max(mx,b[k]);
            }
        }
    if(dp[n][m]) return 1;
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    int mn;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
        {
            mn = b[j];
            if(mn > a[i]) dp[i][j] |= dp[i-1][j];
            for(int k = j-1;k >= 0;k--)
            {
                if(mn <= a[i]) break;
                dp[i][j] |= dp[i-1][k];
                mn = min(mn,b[k]);
            }
        }
    if(dp[n][m]) return 1;
    return 0;
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c,q,kx,ky,xxx,yyy;
    scanf("%d%d%d%d",&c,&n,&m,&q);
    for(int i = 1;i <= n;i++) {scanf("%d",&a[i]); aa[i] = a[i];}
    for(int i = 1;i <= m;i++) {scanf("%d",&b[i]); bb[i] = b[i];}
    printf("%d",work());
    for(int i = 1;i <= q;i++)
    {
        memcpy(a,aa,sizeof(a));
        memcpy(b,bb,sizeof(b));
        scanf("%d%d",&kx,&ky);
        for(int j = 1;j <= kx;j++)
        {
            scanf("%d%d",&xxx,&yyy);
            a[xxx] = yyy;
        }
        for(int j = 1;j <= ky;j++)
        {
            scanf("%d%d",&xxx,&yyy);
            b[xxx] = yyy;
        }
        //for(int j = 1;j <= n;j++) cout << a[j] << " ";
        //cout << endl;
        //for(int j = 1;j <= n;j++) cout << b[j] << " ";
        //cout << endl;
        printf("%d",work());
    }
    return 0;
}
