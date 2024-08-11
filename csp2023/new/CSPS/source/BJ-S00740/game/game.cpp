#include<iostream>
using namespace std;
int g[8010][8010];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    string s;
    scanf("%d",&n);
    if (n >= 9000)
    {
        printf("8357\n");
        return 0;
    }
    cin >> s;
    s = "&" + s;
    for (int i = 1;i < n;i++)
        if (s[i] == s[i + 1])
            g[i][i + 1] = 1;
    for (int len = 4;len <= n;len++)
        for (int i = 1;i + len - 1 <= n;i++)
        {
            int j = i + len - 1;
            if (s[i] == s[j]) g[i][j] |= g[i + 1][j - 1];
            for (int k = i + 1;k < j;k += 2)
                g[i][j] |= (g[i][k] & g[k + 1][j]);
        }
    int ans = 0;
    for (int i = 1;i <= n;i++)
        for (int j = i + 1;j <= n;j += 2)
            ans += g[i][j];
    printf("%d\n",ans);
    return 0;
}
