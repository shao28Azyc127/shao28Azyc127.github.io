#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
string s;
bool flag[810][810];
long long ans = 0,dp[810];
bool check(int i,int j)
{
    if((j-i+1) % 2 != 0) return false;
    if(flag[i][j]) return true;
    return false;
}

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    scanf("%d",&n);
    cin>>s;
    s = ' '+s;
    for (int i = 2;i<=n;i++)
        if(s[i] == s[i-1])
            flag[i-1][i] = true;
    for (int i = n;i>=1;i--)
        for (int j = i+1;j<=n;j++)
            if(s[i] == s[j] && (flag[i+1][j-1] || (flag[i+2][j-1] && s[i] == s[i+1] && 1) || (flag[i+1][j-2] && s[j] == s[j-1] && 1)))
            {
                flag[i][j] = true;
            }
    for (int i = n;i>=1;i--)
        for (int j = i+1;j<=n;j++)
            for (int k = j+1;k<=n;k++)
                if(flag[i][j] && flag[j+1][k])
                    flag[i][k] = true;
    for (int i = 1;i<=n;i++)
        for (int j = i+1;j<=n;j++)
            if(check(i,j))
                ans++;
    printf("%lld\n",ans);
    return 0;
}
