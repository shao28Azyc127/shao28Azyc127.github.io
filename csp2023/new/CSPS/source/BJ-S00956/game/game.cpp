#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e6+100;
int n,r[maxn],f[maxn][30];
string s;
ll dp[maxn],ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>s;
    s=" "+s;
    r[n]=n+1;
    for(int i=1;i<=26;i++) f[n][i]=f[n+1][i]=f[n+2][i]=n+1;
    f[n][s[n]-'a'+1]=n;
    for(int i=n-1;i>=1;i--)
    {
        r[i]=f[i+1][s[i]-'a'+1];
        if(r[i]>n)
        {
            for(int j=1;j<=26;j++) f[i][j]=n+1;
        }
        else
        {
            for(int j=1;j<=26;j++) f[i][j]=f[r[i]+1][j];
        }
        f[i][s[i]-'a'+1]=i;
        //cout<<i<<":";
        //for(int j=1;j<=26;j++) cout<<f[i][j]<<' ';
        //cout<<'\n';
    }
    for(int i=n;i>=1;i--)
    {
        if(r[i]<=n) dp[i]=dp[r[i]+1]+1;
        ans=ans+dp[i];
    }
    cout<<ans<<'\n';
    return 0;
}
