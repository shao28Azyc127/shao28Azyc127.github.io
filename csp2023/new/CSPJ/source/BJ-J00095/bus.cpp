#include <bits/stdc++.h>
using namespace std;
int g[10007][10007];
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k2;
    int i,j,k;

    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&k);

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            g[i][j]=1e9;
            if (g[i][j]%k2)
            {
                g[i][j]++;
            }
        }
    }
    g[0][1]=0-k;
    for (i=0;i<m;i++)
    {
        int a,b,w;
        scanf("%d",&a);
        scanf("%d",&b);
        scanf("%d",&w);
        g[a][b]=w;

    }
    while ((k2+(g[1][n]))%k2!=0)
    {
        g[0][1]+=k2;
        for (k=0;k<=n;k++)
        {
            for (i=1;i<=n;i++)
            {
                for (j=1;j<=n;j++)
                {
                    if (g[i][k]-g[k][j]>=-1)
                    {
                        g[i][j]=max(g[i][k],g[k][j]);
                    }
                }
            }
        }

    }
    printf("%d",k2+(g[1][n]));
    return 0;
}
