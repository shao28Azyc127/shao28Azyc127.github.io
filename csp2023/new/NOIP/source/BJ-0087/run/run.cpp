#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
int n,m,k,cost;
int f[1005][1005];
int value[1005][1005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int op;
    cin>>op>>T;
    while(T--)
    {
        cin>>n>>m>>k>>cost;
        if(op<=9)
        {
            int x,y,val;
            memset(value,0,sizeof(value));
            for(int i=1;i<=m;i++)
            {
                cin>>x>>y>>val;
                value[x][y]+=val;
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=k;j++)
                {
                    value[i][j]+=value[i][j-1];
                }
            }
            memset(f,~0x3f,sizeof(f));
            f[0][0]=0;
            for(int i=1;i<=n;i++)
            {
                f[i][0]=f[i-1][0];
                for(int j=1;j<=k;j++)
                {
                    f[i][0]=max(f[i][0],f[i-1][j]);
                    f[i][j]=f[i-1][j-1]-cost+value[i][j];
                }
            }
            int ans=0;
            for(int i=0;i<=k;i++)
            {
                ans=max(ans,f[n][i]);
            }
            cout<<ans<<endl;
        }

    }
    return 0;
}
