#include<bits/stdc++.h>
#define N 100010
using namespace std;

int n, m, T, c;
int a[N];

void solve1()
{
    //clear
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) a[i] = 1;
    char v[5]; int x; 
    for(int i = 1; i <= m; ++i)
    {
        scanf("%s%d", v, &x);
        if(v[0] == 'T') a[x] = 1;
        else if(v[0] == 'F') a[x] = -1;
        else if(v[0] == 'U') a[x] = 0;
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i)
        if(a[i] == 0) ans ++;
    printf("%d\n", ans);
}

int pre[N], aft[N];

bool check()
{
    for(int i = 1; i <= n; ++i)
        if(pre[i] != 2) return 1;
    return 0;
}

void change()
{
    pre[1]++;
    for(int i = 1; i <= n; ++i)
        if(pre[i] == 3) pre[i] = 0, pre[i + 1]++;
}

int opt[N];

char s[N][3]; int ox[N], oy[N];

bool judge()
{
    for(int i = 1; i <= n; ++i)
        if(pre[i] != aft[i]) return 0;
    return 1;
}

int sa[N];

void save()
{
    for(int i = 1; i <= n; ++i) sa[i] = pre[i];
}

void solve2()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) ox[i] = oy[i] = s[i][0] = 0;
    for(int i = 1; i <= m; ++i)
    {
        scanf("%s", s[i]);
        if(s[i][0] == '+' || s[i][0] == '-') scanf("%d%d", &ox[i], &oy[i]);
        else scanf("%d", &ox[i]);
    }
    for(int i = 1; i <= n; ++i) pre[i] = 0;
    int ans = n, tmp = 0;
    while(1)
    {
        tmp = 0;
        for(int i = 1; i <= n; ++i)
            if(pre[i] == 2) tmp++;
        for(int i = 1; i <= n; ++i) aft[i] = pre[i];
        for(int i = 1; i <= m; ++i)
        {
            if(s[i][0] == 'T') aft[ox[i]] = 1;
            else if(s[i][0] == 'F') aft[ox[i]] = 0;
            else if(s[i][0] == 'U') aft[ox[i]] = 2;
            else if(s[i][0] == '+') aft[ox[i]] = aft[oy[i]];
            else if(s[i][0] == '-') 
            {
                if(aft[oy[i]] == 1) aft[ox[i]] = 0;
                else if(aft[oy[i]] == 0) aft[ox[i]] = 1;
                else if(aft[oy[i]] == 2) aft[ox[i]] = 2;
            }
        }
        if(judge()) 
        {
            if(ans > tmp) save();
            ans = min(ans, tmp);
        }
        if(!check()) break;
        change();
    }
    printf("%d\n", ans);
}

int val[N];

void solve3()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) val[i] = 0;
    for(int i = 1; i <= n; ++i) ox[i] = oy[i] = s[i][0] = 0;
    for(int i = 1; i <= m; ++i)
    {
        scanf("%s", s[i]);
        if(s[i][0] == 'U')
        {
            scanf("%d", &ox[i]);
            val[ox[i]] = 1;
        }
        else
        {
            scanf("%d%d", &ox[i], &oy[i]);
            val[ox[i]] = val[oy[i]];
        }
    }
    int t = 400;
    while(t--)
    {
        for(int i = 1; i <= m; ++i)
        {
            if(s[i][0] == 'U')
            {
                val[ox[i]] = 1;
            }
            else
            {
                val[ox[i]] = val[oy[i]];
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i)
        if(val[i] == 1) ans++;
    printf("%d\n", ans);
}

int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    scanf("%d%d", &c, &T);
    while(T--)
    {
        if(c == 3 || c == 4) solve1();
        else if(c == 1 || c == 2) solve2();
        else if(c == 5 || c == 6) solve3();
    }
    return 0;
}