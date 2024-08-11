#include <bits/stdc++.h>
#define int long long
#define MAXN 5010
#define INF 1000000000000000000
using namespace std;
int c,t,n,m,k,d,f[MAXN][MAXN],ans;
struct tiaozhan
{
    int x,y,w;
}a[MAXN];
int g[MAXN];
bool cmp(tiaozhan a,tiaozhan b)
{
    if(a.x!=b.x)
        return a.x<b.x;
    return a.y<b.y;
}
signed main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>c>>t;
    if(c<=2)
    {
        while(t--)
        {
            int ans=-INF;
            cin>>n>>m>>k>>d;
            for(int i=1;i<=m;i++)
                cin>>a[i].x>>a[i].y>>a[i].w;
            for(int S=0;S<(1<<n);S++)
            {
                int sum=0,flag=0;
                memset(g,0,sizeof(g));
                for(int i=1;i<=n;i++)
                    if(S&(1<<i-1))
                    {
                        g[i]=g[i-1]+1,sum-=d;
                        if(g[i]>k)
                        {
                            flag=1;
                            break;
                        }
                    }
                if(flag) continue;
                for(int i=1;i<=m;i++)
                    if(g[a[i].x]>=a[i].y)
                        sum+=a[i].w;
                //cout<<S<<" "<<sum<<endl;
                ans=max(ans,sum);
            }
            cout<<ans<<'\n';
        }
        return 0;
    }
    while(t--)
    {
        cin>>n>>m>>k>>d;
        for(int i=1;i<=m;i++)
            cin>>a[i].x>>a[i].y>>a[i].w;
        sort(a+1,a+1+m,cmp);
        for(int i=0;i<=n;i++)
            for(int j=0;j<=k;j++) f[i][j]=-INF;
        f[0][0]=0;
        int tot=1;int ans=-INF;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
                f[i][0]=max(f[i][0],f[i-1][j]);

            for(int j=1;j<=k;j++)
            {
                bool flag=0;
                f[i][j]=f[i-1][j-1]-d;
                if(tot<=m&&i==a[tot].x&&j>=a[tot].y)
                {
                    f[i][j]=max(f[i][j],f[i-1][j-1]-d+a[tot].w);
                    flag=1;
                }
                if(flag) ++tot;
            }
        }
        for(int i=0;i<=k;i++)
            ans=max(ans,f[n][i]);
        cout<<ans<<'\n';
    }
    return 0;
}
