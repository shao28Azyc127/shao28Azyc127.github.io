#include<bits/stdc++.h>//40-50
using namespace std;
bool dp[8010][8010];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    long long n,ans=0;
    cin>>n;
    string s;
    cin>>s;
    s=' '+s;
    for(int j=1;j<=n;j++)//n3
    {
        for(int i=j-1;i>0;i--)
        {
            if((j-i+1)%2==1) continue;
            if(j==i+1)
            {
                if(s[i]==s[j]) dp[i][j]=1;
                if(dp[i][j]) ans++;
                continue;
            }
            if(dp[i][j-2]&&s[j-1]==s[j]) dp[i][j]=1;
            if(dp[i+2][j]&&s[i]==s[i+1]) dp[i][j]=1;
            if(dp[i+1][j-1]&&s[i]==s[j]) dp[i][j]=1;
            if(dp[i][j]) 
            {
                ans++;
                continue;
            }
            for(int k=i+1;k<=n;k+=2) 
            {
                if(dp[i][k]&&dp[k+1][j]) 
                {
                    dp[i][j]=1;
                    break;
                }
            }
            if(dp[i][j]) ans++;
        }
    }
    cout<<ans;
    return 0;
}