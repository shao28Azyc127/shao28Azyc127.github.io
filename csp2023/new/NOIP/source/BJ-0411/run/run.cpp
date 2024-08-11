#include <iostream>
#include <cstring>
using namespace std;
#define int long long

int c,t,n,m,k,d,a[1005][1005],dp[1005][1005];

signed main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin >> c >> t;
    while(t--)
    {
        memset(a,-1,sizeof(a));
        memset(dp,0,sizeof(dp));
        cin >> n >> m >> k >> d;
        for(int i=1;i<=m;i++)
        {
            int x,y,v;
            cin >> x >> y >> v;
            a[x][y] = v;
        }

        dp[1][1] = -1;
        for(int i=1;i<=n;i++)
            for(int j=0;j<=min(i,k);j++)
            {
                if(a[i][j] != -1) dp[i][j] += a[i][j];
                if(i + 1 <= n)
                {
                    if(j < k) dp[i+1][j+1] = dp[i][j] - d;
                    dp[i+1][0] = max(dp[i][j],dp[i+1][0]);
                }
            }

        /*for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
                cout << dp[i][j] << " ";
            cout << endl;
        }*/

        int ans = 0;
        for(int i=0;i<k;i++)
            ans = max(ans,dp[n][i]);
        cout << ans << endl;
    }
    return 0;
}
