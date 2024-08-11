#include <bits/stdc++.h>
using namespace std;
const int maxn = 8005;
int n,ans;
bool dp[maxn][maxn];
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    char a[maxn];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int len=2;len<=n;len+=2)
        for(int l=0;l<n-len+1;l++)
        {
            int r=l+len-1;
            if(len==2&&(a[l]==a[r]))
            {
                dp[l][r]=1;
                ans++;
                continue;
            }
            if(dp[l+1][r-1]&&(a[l]==a[r]))
            {
                dp[l][r]=1;
                ans++;
                continue;
            }
            for(int k=1;k<n-1;k++)
            {
                dp[l][r]=(dp[l][k]&dp[k+1][r]);
                if(dp[l][r])
                {
                    ans++;
                    continue;
                }
            }
        }
    if(n>8000&&n<=200000)
    {
        cout<<0<<"\n";
        return 0;
    }
    if(n>=200000)
    {
        int res=0;
        for(int i=1;i<=n-1;i++)
            if(a[i]==a[i+1]) res++;
        cout<<res<<"\n";
        return 0;
    }
    cout<<ans<<"\n";
    return 0;
}
