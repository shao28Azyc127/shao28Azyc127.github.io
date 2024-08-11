#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
using namespace std;
const int MAXN = 10, MAXM = 10;
int n, a[MAXN][MAXM], ans, b[MAXM], c[MAXM];
int cnt1, cnt2;
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
bool check()
{
    for(int i = 1; i <= n; ++i)
    {
        int cnt = 0, first_num = 0;
        for(int j = 1; j <= 5; ++j)
        {
            c[j] = ((b[j] - a[i][j]) + 10) % 10;
            if(c[j] != 0)
            {
                if(!first_num) first_num = j;
                ++cnt;
            }
        }
        if(cnt > 2 || cnt == 0) return 0;
        bool flag = 0;
        if(cnt == 1) flag = 1, ++cnt1;
        else
        {
            if(c[first_num] == c[first_num + 1]) flag = 1, ++cnt2;
        }
        if(!flag) return 0;
    }
    //for(int j = 1; j <= 5; ++j) printf("%d ", b[j]);
    //puts("");
    return 1;
}
void dfs(int x)
{
    //printf("%d\n", x);
    if(x == 5)
    {
        if(check()) ++ans;
        return;
    }
    for(int i = 0; i <= 9; ++i)
    {
        b[x + 1] = i;
        dfs(x + 1);
    }
}
int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    n = read();
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= 5; ++j)
            a[i][j] = read();
    }
    //printf("1\n");
    dfs(0);
    printf("%d\n", ans);
    //printf("%d %d\n", cnt1, cnt2);
    return 0;
}
