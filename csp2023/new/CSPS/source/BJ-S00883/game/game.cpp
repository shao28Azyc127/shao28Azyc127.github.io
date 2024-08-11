#include<bits/stdc++.h>
using namespace std;
char a[100100];
int b[100100];
bool dp[100100][20];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;cin>>n;int ans=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) dp[i][0]=a[i]-'0';
    for(int i=1;i<=__lg(n);i++)
    {
        if(i==1)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=bool(dp[i][j-1] == dp[i+(1<<(j-1))][j-1]);
            }
            continue;
        }
        for(int j=1;i+(1<<j)-1<=n;j++)
        {
            dp[i][j]=bool(dp[i][j-1] && dp[i+(1<<(j-1))][j-1]);
        }
    }
    for(int i=1;i<=__lg(n);i++)
    {
        for(int j=1;i+(1<<j)-1<=n;j++)
        {
            if(dp[i][j])
                ans++;
        }
    }
    cout<<ans<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}