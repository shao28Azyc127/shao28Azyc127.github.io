#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long dp[2010][2010];
char c[1000010];
signed main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(0);

    cin>>n;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n-1;i++)
    {
        if(c[i]==c[i+1]) dp[i][i+1]=1,ans++;
    }
    for(int l=3;l<=n;l+=2)
    {
        for(int i=1;i<=n;i++)
        {
            int j=i+l;
            if(j>n) break;
            if(c[i]==c[j])
            {
                dp[i][j]=dp[i+1][j-1];
                if(dp[i][j]==1) ans++;
                continue;
            }
            for(int k=i+1;k<=j-1;k+=2)
            {
                //cout<<i<<" "<<k<<" "<<j<<"\n";
                if(dp[i][k]==1&&dp[k+1][j]==1)
                {
                    ans++;
                    dp[i][j]=1;
                    break;
                }
            }
        }
    }
    cout<<ans;

    cout<<endl;
    return 0;
}
