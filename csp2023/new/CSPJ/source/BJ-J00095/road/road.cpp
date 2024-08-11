#include <bits/stdc++.h>
using namespace std;
int dp[100007][100007],v[100008],a[100008];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,i,j;
    cin>>n>>d;

    for (i=1;i<=n-1;i++)
    {
        cin>>v[i];
    }
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    
    for (i=0;i<=n;i++)
    {
        for (j=0;j<=n;j++)
        {
            dp[i][j]=1e9;
            if (i==j)
            {
                dp[i][j]==0;
            }
        }
    }
    dp[1][0]=0;
    for (i=1;i<=n;i++)
    {
        for (j=i+1;j<=n;j++)
        {
            dp[i][j]=min(dp[i][j],int(dp[i][j-1]+ceil(d*1.0/v[j-1])*a[j-1]));
        }
    }
    cout<<dp[1][n];
    return 0;
}
