#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=8005;
int dp[N][N];
char ch[N];
signed main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>ch[i];
        if(ch[i]==ch[i-1]) dp[i-1][i]=1;
    }
    for(int k=2;k<=n;k++)
        for(int i=1;i+k<=n;i++)
        {
            int j=i+k;
            if(ch[i]==ch[j]&&dp[i+1][j-1]) dp[i][j]=1;
            else
            {
                for(int tmp=i+1;tmp-1<j;tmp++)
                    if(dp[i][tmp]&&dp[tmp+1][j])
                    {
                        dp[i][j]=1;
                        break;
                    }
            }
        }
    int ans=0;
    for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                ans+=dp[i][j];
    cout<<ans;
    return 0;
}
