#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
long long n,ans=0;
bool dp[10005][10005];
string a;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%lld",&n);
    cin>>a;
    a=" "+a;
    dp[0][0]=true;
    for(int i=1;i<n;++i)
        if(a[i]==a[i+1])
        {
            dp[i][i+1]=true;
            ++ans;
        }
    for(int l=3;l<=n;++l)
        for(int i=1;i+l-1<=n;++i)
        {
            int j=i+l-1;
            if(dp[i+1][j-1]==true && a[i]==a[j])
                dp[i][j]=true;
            else
            {
                for(int k=i;k<j;++k)
                    if(dp[i][k]==true && dp[k+1][j]==true)
                    {
                        dp[i][j]=true;
                        break;
                    }
            }
            if(dp[i][j]==true)
                ++ans;
        }
    printf("%lld\n",ans);
    return 0;
}
