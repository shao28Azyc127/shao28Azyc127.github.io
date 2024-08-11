#include <iostream>
#include <stack>
using namespace std;
#define int long long
const int N=2e6+5;
int n;
int dp[N][30];
int f[N];
char x[N];
int ans;
signed main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int i,j;
    scanf("%lld",&n);
    scanf("%s",x+1);
    dp[1][x[1]-'a']=1;
    f[1]=0;
    for(i=2; i<=n; i++)
    {
        if(dp[i-1][x[i]-'a']!=0)
        {
            for(j=0; j<26; j++)
                dp[i][j]=dp[dp[i-1][x[i]-'a']-1][j];
            f[i]=f[dp[i-1][x[i]-'a']-1]+1;
            ans+=f[i];
        }
        dp[i][x[i]-'a']=i;
    }
    printf("%lld",ans);
    return 0;
}
