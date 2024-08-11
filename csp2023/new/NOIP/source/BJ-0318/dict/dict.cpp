#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
using namespace std;
const int MAXN = 3005, MAXM = 3005;
int n, m, minpos[MAXM], tminpos, maxpos[MAXM], tmaxpos;
char s[MAXN][MAXM], mins[MAXN][MAXM], maxs[MAXN][MAXM], tmpmin, tmpmax;
void solve(int x)
{
    for(int i = 1; i <= m; ++i) mins[x][i] = maxs[x][i] = s[x][i];
    tmpmin = 'z' + 1, tminpos = m + 1;
    for(int i = m; i >= 1; --i)
    {
        minpos[i] = tminpos;
        if(s[x][i] < tmpmin)
        {
            tmpmin = s[x][i];
            tminpos = i;
        }
    }
    for(int i = 1; i < m; ++i)
    {
        if(mins[x][i] > mins[x][minpos[i]])
        {
            swap(mins[x][i], mins[x][minpos[i]]);
            break;
        }
    }
    tmpmax = 'a' - 1, tmaxpos = m + 1;
    for(int i = m; i >= 1; --i)
    {
        maxpos[i] = tmaxpos;
        if(s[x][i] > tmpmax)
        {
            tmpmax = s[x][i];
            tmaxpos = i;
        }
    }
    for(int i = 1; i < m; ++i)
    {
        if(maxs[x][i] < maxs[x][maxpos[i]])
        {
            swap(maxs[x][i], maxs[x][maxpos[i]]);
            break;
        }
    }
}
bool check(int x)
{
    for(int i = 1; i <= n; ++i)
    {
        if(i == x) continue;
        bool flag = 1;
        for(int j = 1; j <= m; ++j)
        {
            if(mins[x][j] < maxs[i][j]) break;
            if(mins[x][j] > maxs[i][j])
            {
                flag = 0;
                break;
            }
        }
        if(!flag) return 0;
    }
    return 1;
}
int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            scanf(" %c", &s[i][j]);
    for(int i = 1; i <= n; ++i)
        solve(i);
    for(int i = 1; i <= n; ++i)
    {
        bool flag = 1;
        if(check(i)) putchar('1');
        else putchar('0');
    }
    puts("");
    return 0;
}
