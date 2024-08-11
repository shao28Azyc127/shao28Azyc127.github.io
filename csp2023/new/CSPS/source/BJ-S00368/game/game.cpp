#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
using namespace std;
const int MAXN = 8005;
int n, ans, f[MAXN][MAXN];
char c[MAXN];
int read()
{
    int x = 0, flag = 1;
    char c = getchar();
    while(c < '0' || c > '9')
    {
        if(c == '-') flag = 0;
        c = getchar();
    }
    while(c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return flag ? x : -x;
}
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    n = read();
    for(int i = 1; i <= n; ++i)
    {
        scanf(" %c", &c[i]);
        if(c[i] == c[i - 1]) f[i - 1][i] = 1, ++ans;
    }
    for(int len = 4; len <= n; len += 2)
    {
        for(int l = 1; l + len - 1 <= n; ++l)
        {
            int r = l + len - 1;
            if(f[l + 1][r - 1] && c[r] == c[l])
            {
                f[l][r] = 1;
                ++ans;
            }
            else
            {
                for(int k = l + 1; k <= r - 2; k += 2)
                {
                    if(f[l][k] && f[k + 1][r])
                    {
                        f[l][r] = 1;
                        ++ans;
                        break;
                    }
                }
            }
        }
    }
    /*printf("%d\n", ans);
    for(int len = 4; len <= n; len += 2)
    {
        for(int l = 1; l + len - 1 <= n; ++l)
        {
            int r = l + len - 1;
            if(f[l][r]) continue;
            for(int k = l + 1; k <= r - 2; k += 2)
            {
                if(f[l][k] && f[k + 1][r])
                {
                    f[l][r] = 1;
                    ++ans;
                    break;
                }
            }
        }
    }*/
    printf("%d\n", ans);
    return 0;
}
