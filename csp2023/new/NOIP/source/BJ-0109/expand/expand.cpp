#include <iostream>
#include <cstring>
using namespace std;
#define int long long
const int N=5e5+5;
const int M=2e3+5;
int c,n,m,q;
int x[N],y[N];
int orx[N],ory[N];
int dp[M][M];
void solve()
{
    int i,j;
    memset(dp,0,sizeof(dp));
    dp[1][1]=1;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(dp[i][j]==1)
            {
                if(x[1]<y[1] && i!=n && x[i+1]<y[j])
                    dp[i+1][j]=1;
                if(x[1]>y[1] && i!=n && x[i+1]>y[j])
                    dp[i+1][j]=1;
                if(x[1]<y[1] && j!=m && x[i]<y[j+1])
                    dp[i][j+1]=1;
                if(x[1]>y[1] && j!=m && x[i]>y[j+1])
                    dp[i][j+1]=1;
            }
    printf("%lld",dp[n][m]);
    return;
}
signed main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int i,j;
    scanf("%lld%lld%lld%lld",&c,&n,&m,&q);
    for(i=1; i<=n; i++)
        scanf("%lld",&x[i]),orx[i]=x[i];
    for(i=1; i<=m; i++)
        scanf("%lld",&y[i]),ory[i]=y[i];
    if(c<=7)
    {
        solve();
        for(i=1; i<=q; i++)
        {
            int t1,t2;
            for(j=1; j<=n; j++)
                x[j]=orx[j];
            for(j=1; j<=m; j++)
                y[j]=ory[j];
            scanf("%lld%lld",&t1,&t2);
            for(j=1; j<=t1; j++)
            {
                int p,v;
                scanf("%lld%lld",&p,&v);
                x[p]=v;
            }
            for(j=1; j<=t2; j++)
            {
                int p,v;
                scanf("%lld%lld",&p,&v);
                y[p]=v;
            }
            solve();
        }
    }
    else
    {
        if(x[1]<y[1] && x[n]<y[m] || x[1]>y[1] && x[n]>y[m])
            printf("1");
        else
            printf("0");
        for(i=1; i<=q; i++)
        {
            int t1,t2;
            scanf("%lld%lld",&t1,&t2);
            for(j=1; j<=t1; j++)
            {
                int p,v;
                scanf("%lld%lld",&p,&v);
                x[p]=v;
            }
            for(j=1; j<=t2; j++)
            {
                int p,v;
                scanf("%lld%lld",&p,&v);
                y[p]=v;
            }
            if(x[1]<y[1] && x[n]<y[m] || x[1]>y[1] && x[n]>y[m])
                printf("1");
            else
                printf("0");
        }
    }
    printf("\n");
    return 0;
}
