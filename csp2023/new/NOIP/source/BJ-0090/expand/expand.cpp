#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int c,n,m,q;
int x[N],y[N];
int a[N],b[N];
bool dp[2005][2005];
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>y[i];
    }
    for(int i=1;i<=n;i++)
    {
        a[i]=x[i];
    }
    for(int i=1;i<=m;i++)
    {
        b[i]=y[i];
    }
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]>b[j])
            {
                dp[i][j]|=dp[i][j-1];
                dp[i][j]|=dp[i-1][j];
                dp[i][j]|=dp[i-1][j-1];
            }
            //cout<<dp[i][j]<<' ';
        }
       // cout<<'\n';
    }
    if(dp[n][m])
    {
        cout<<1;

    }
    else
    {
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i]<b[j])
				{
					dp[i][j]|=dp[i][j-1];
					dp[i][j]|=dp[i-1][j];
					dp[i][j]|=dp[i-1][j-1];
				}
			}
		}
		if(dp[n][m])
		{
			cout<<1;
		}
		else cout<<0;
	}
    while(q--)
    {
        int kx,ky;
        cin>>kx>>ky;
        for(int i=1;i<=n;i++)
        {
            a[i]=x[i];
        }
        for(int i=1;i<=m;i++)
        {
            b[i]=y[i];
        }
        for(int i=1;i<=kx;i++)
        {
            int ii,jj;
            cin>>ii>>jj;
            a[ii]=jj;
        }
        for(int i=1;i<=ky;i++)
        {
            int ii,jj;
            cin>>ii>>jj;
            b[ii]=jj;
        }
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i]>b[j])
                {
                    dp[i][j]|=dp[i][j-1];
                    dp[i][j]|=dp[i-1][j];
                    dp[i][j]|=dp[i-1][j-1];
                }
            }
        }
        if(dp[n][m])
        {
            cout<<1;
            continue;
        }
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i]<b[j])
                {
                    dp[i][j]|=dp[i][j-1];
                    dp[i][j]|=dp[i-1][j];
                    dp[i][j]|=dp[i-1][j-1];
                }
            }
        }
        if(dp[n][m])
        {
            cout<<1;
            continue;
        }
        cout<<0;
    }
}
