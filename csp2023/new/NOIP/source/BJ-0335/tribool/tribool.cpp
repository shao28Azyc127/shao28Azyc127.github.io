#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXN 10005
#define MAXM 10005

int c, tim, n, m;

int ans, ini[MAXN], t[MAXN];//T2 U1 F0
int dy[27];

struct caozuo
{
    char opt;
    int fo, la;
}memo[MAXM];

char read()
{
    char c = getchar();
    while ((c < 'A' || c > 'Z') && c != '+' && c != '-')
    {
        c = getchar();
    }
    return c;
}

void dfs()
{
    bool jw = ini[1] == 2;
    ini[1] += 1 - 3 * (ini[1] == 2);
    for (int i = 2; i <= n && jw; ++i)
    {
        jw = ini[i] == 2;
        ini[i] += 1 - 3 * (ini[i] == 2);
    }
    memset(t, -1, sizeof(t));
    for (int i = 1; i <= m; ++i)
    {
        if (memo[i].opt == '-') t[memo[i].fo] = 2 - max(t[memo[i].la], ini[memo[i].la]);
        else if (memo[i].opt == '+') t[memo[i].fo] = max(t[memo[i].la], ini[memo[i].la]);
        else t[memo[i].fo] = dy[memo[i].opt - 'A'];
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (t[i] != -1 && t[i] != ini[i])
        {
            cnt = 1e6;
            break;
        }
        cnt += t[i] == 1 || ini[i] == 1;
    }
    //if (cnt != 1e6) printf("dar%dren", cnt);//
    ans = min(ans, cnt);
}

int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    dy['T' - 'A'] = 2;
    dy['U' - 'A'] = 1;
    scanf("%d%d", &c, &tim);
    while (tim--)
    {
        //chu shi hua hai mei xie
        ans = 1e6;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; ++i)
        {
            memo[i].opt = read();
            scanf("%d", &memo[i].fo);
            if (memo[i].opt < 'A' || memo[i].opt > 'Z') scanf("%d", &memo[i].la);
        }
        memset(ini, 0, sizeof(ini));
        int cur = n;
        for (int i = 1; cur; ++i)
        {
            dfs();
            //if (ini[1] == 1 && ini[2] == 1 && ini[3] == 1) printf("darren");//
            cur -= (ini[cur] == 2);
        }
        printf("%d\n", ans);
    }
    return 0;
}