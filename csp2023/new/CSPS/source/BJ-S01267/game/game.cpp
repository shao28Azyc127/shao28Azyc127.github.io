#include<bits/stdc++.h>
#define N 2000010
using namespace std;

int n;
char s[N];
bool g[8100][8100];
int f[N], last[N];

void solve1()
{
    long long ans = 0;
    for(int i = 1; i < n; ++i)
        if(s[i] == s[i + 1]) g[i][i + 1] = 1, ans++;
    for(int l = 4; l <= n; l += 2)
    {
        for(int i = 1; i + l - 1 <= n; ++i)
        {
            int j = i + l - 1;
            for(int k = 2; k <= l; ++k)
                if(g[i][i + k - 1] == 1 && g[i + k][j] == 1) g[i][j] = 1;
            if(g[i + 1][j - 1] == 1 && s[i] == s[j]) g[i][j] = 1;
            if(g[i][j] == 1) ans ++;
        }
    }
    printf("%lld", ans);
}

void solve2()
{
    long long ans = 0;
    for(int i = 1; i < n; ++i)
        if(s[i] == s[i + 1]) g[i][i + 1] = 1, ans++;
    for(int i = n; i >= 1; --i)
    {
        int k = 0;
        for(int l = 4; i + l - 1 <= n; l += 2)
        {
            int j = i + l - 1;
            if(s[i] == s[j] && g[i + 1][j - 1]) g[i][j] = 1;
            if(g[i][j] == 1 && k == 0) k = j;
            if(k != 0 && g[i][k] == 1 && g[k + 1][j] == 1) g[i][j] = 1;
            if(g[i][j] == 1) ans ++;
        }
    }
    printf("%lld", ans);
}

void solve3()
{
    long long ans = 0;
    for(int i = n - 1; i >= 1; --i)
    {
        if(s[i] == s[i + 1]) 
        {
            f[i] = f[i + 2] + 1;
            last[i] = i + 1;
        }
        else if(f[i + 1] != 0)
        {
            if(s[i] == s[last[i + 1] + 1])
            {
                f[i] = f[last[i + 1] + 2] + 1;
                last[i] = last[i + 1] + 1;
            }
            else f[i] = 0;
        }
    }
    for(int i = 1; i <= n; ++i)
        ans = ans + (long long)f[i];
    printf("\n%lld", ans);
}
int alp[30];
bool chk()
{
    int avg = n / 26;
    for(int i = 1; i <= n; ++i)
        alp[s[i] - 'a' + 1]++;
    for(int i = 1; i <= 26; ++i)
        if(alp[i] > 6 * avg) return 0;
    return 1; 
}

int v[11][N];
void solve4()
{
    long long ans = 0;
    for(int i = 1; i < n; ++i)
        if(s[i] == s[i + 1]) v[2][i] = 1, ans ++;
    for(int l = 4; l <= 10; l += 2)
    {
        for(int i = 1; i + l - 1 <= n; ++i)
        {
            int j = i + l - 1;
            if(s[i] == s[j] && v[l - 2][i + 1] == 1) v[l][i] = 1;
            for(int k = i + 1; k <= j; k += 2)
                if(v[k - i + 1][i] == 1 && v[j - k][k + 1] == 1) v[l][i] = 1;
            if(v[l][i] == 1) ans++;
        }
    }
    printf("%lld", ans);
}

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d", &n);
    scanf("%s", s + 1);
    if(n <= 800) solve1();
    else if(n <= 8000) solve2();
    else if(chk()) solve4();
    else solve3();
    return 0;
}