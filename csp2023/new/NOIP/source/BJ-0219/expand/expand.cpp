#include<bits/stdc++.h>
using namespace std;
int x[2005],y[2005];
int rex[2005],rey[2005];
int dp[2005];
int vis[2005];
int main()
{
    int c,n,m,q;
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++) cin>>x[i],rex[i]=x[i];
    for(int i=1;i<=m;i++) cin>>y[i],rey[i]=y[i];
    q+=2;
    while(q--)
    {
        if(x[1]>y[1])
        {
            int nowy=0;
            dp[0]=1;
           for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    if(x[i]<=y[j]&&nowy>=j)
                    {
                        dp[j]=0;
                    }
                    if(x[i]>y[j]&&nowy<j&&dp[j-1]==1)
                    {
                        nowy++;
                        dp[j]=1;
                    }
                }
                for(int j=m;j>=1;j--) if(dp[j]) {nowy=j;break;}
            }
            if(dp[m]==1) cout<<1;
            else cout<<0;
        }
        else if(x[1]<y[1])
        {
             int nowy=0;
            dp[0]=1;
           for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    if(x[i]>=y[j]&&nowy>=j)
                    {
                        dp[j]=0;
                    }
                    if(x[i]<y[j]&&nowy<j&&dp[j-1]==1)
                    {
                        nowy++;
                        dp[j]=1;
                    }
                }
                for(int j=m;j>=1;j--) if(dp[j]) {nowy=j;break;}
            }
            if(dp[m]==1) cout<<1;
            else cout<<0;
        }
        else cout<<0;
        if(q==1) break;
        int kx,ky;
        cin>>kx>>ky;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++) x[i]=rex[i];
        for(int j=1;j<=m;j++) y[j]=rey[j];
        for(int i=1;i<=kx;i++)
        {
            int p,v;
            cin>>p>>v;
            x[p]=v;
        }
        for(int j=1;j<=ky;j++)
        {
            int p,v;
            cin>>p>>v;
            y[p]=v;
        }
    }
    return 0;
}
