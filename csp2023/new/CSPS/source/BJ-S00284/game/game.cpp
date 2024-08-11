#include<bits/stdc++.h>
using namespace std;
bool dp[10010][10010]={0};
char a[200010];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    long long ans=0;
    cin>>n>>a;
    if((n%2)==1)
    {
        cout<<0;
        return 0;
    }
    for(int len=1;len<n;len+=2)
    {
        for(int i=0;(i+len)<n;i++)
        {
            int j=i+len;
            if(a[i]==a[j])
            {
                if((i+1)==j)
                    dp[i][j]=1;
                else
                    dp[i][j]=dp[i+1][j-1];
            }
            else
            {
                for(int t=i+1;t<j;t+=2)
                {
                    if(dp[i][t]==1&&dp[t+1][j]==1)
                    {
                        dp[i][j]=1;
                        break;
                    }
                }
            }
            ans+=dp[i][j];
        }
    }
    cout<<ans;
    return 0;
}