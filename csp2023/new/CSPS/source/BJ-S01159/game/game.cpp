#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

char s[2000005];
bool dp[8010][8010];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    cin>>(s+1);
    for(int i=1;i<=n;i++)dp[i][i-1]=1;
    int ans=0;
    for(int len=2;len<=n;len+=2)
    {
        for(int l=1;l+len-1<=n;l++)
        {
            int r=l+len-1;
            if(s[l]==s[r])dp[l][r]|=dp[l+1][r-1];
            if(!dp[l][r])
            {
                for(int k=l+1;k<r;k+=2)
                {
                    dp[l][r]|=(dp[l][k]&dp[k+1][r]);
                    if(dp[l][r])break;
                }
            }
            ans+=dp[l][r];
        }
    }
    cout<<ans;
    return 0;
}