#include <cstdio>
using namespace std;
const int NR = 1e6;
int n;
long long ans = 0;
bool dp[8005][8005];
char s[NR * 2 + 5];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    scanf("%s",s + 1);
    for (int i = 1;i <= n - 1;i++)
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = true;
            ans++;
        }
    for (int len = 4;len <= n;len += 2)
        for (int i = 1;i <= n - len + 1;i++)
        {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1])
                dp[i][j] = true;
            if (!dp[i][j])
                for (int k = i + 1;k <= j - 2;k += 2)
                    if (dp[i][k] && dp[k + 1][j])
                    {
                        dp[i][j] = true;
                        break;
                    }
            if (dp[i][j])
                ans++;
        }
    printf("%lld\n",ans);
    return 0;
}