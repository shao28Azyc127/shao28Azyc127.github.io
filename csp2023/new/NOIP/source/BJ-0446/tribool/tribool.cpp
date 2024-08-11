#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int c,t,n,m,ans = 0;
struct Que{char v;int x,y;}q[100010];
char a[100010],b[100010];
char opp(char c)
{
    if (c == 'T') return 'F';
    if (c == 'F') return 'T';
    if (c == 'U') return 'U';
}
void dfs(int step)
{
    if (step > n)
    {
        int cnt = 0;
        for (int i = 1;i <= n;i++)
            if (a[i] == 'U')
                cnt++;
        for (int i = 1;i <= n;i++)
            b[i] = a[i];
        for (int i = 1;i <= m;i++)
        {
            if (q[i].v == 'T' || q[i].v == 'F' || q[i].v == 'U')
                b[q[i].x] = q[i].v;
            if (q[i].v == '+')
                b[q[i].x] = b[q[i].y];
            if (q[i].v == '-')
                b[q[i].x] = opp(b[q[i].y]);
        }
        for (int i = 1;i <= n;i++)
            if (a[i] != b[i])
                return;
        ans = min(ans,cnt);
        return;
    }
    a[step] = 'T';
    dfs(step + 1);
    a[step] = 'F';
    dfs(step + 1);
    a[step] = 'U';
    dfs(step + 1);
}
void solve1()
{
    while(t--)
    {
        scanf("%d%d",&n,&m);
        ans = 1e9;
        for (int i = 1;i <= m;i++)
        {
            cin >> q[i].v;
            if (q[i].v == '+' || q[i].v == '-')
                cin >> q[i].x >> q[i].y;
            else cin >> q[i].x;
        }
        dfs(1);
        printf("%d\n",ans);
    }
}
void solve2()
{
    while(t--)
    {
        scanf("%d%d",&n,&m);
        ans = 0;
        for (int i = 1;i <= n;i++)
            a[i] = 'X';
        for (int i = 1;i <= m;i++)
            cin >> q[i].v >> q[i].x;
        for (int i = 1;i <= m;i++)
            if (q[i].v == 'T' || q[i].v == 'F' || q[i].v == 'U')
                a[q[i].x] = q[i].v;
        for (int i = 1;i <= n;i++)
            if (a[i] == 'U')
                ans++;
        printf("%d\n",ans);
    }
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&c,&t);
    if (c == 1 || c == 2)
        solve1();
    if (c == 3 || c == 4)
        solve2();
    return 0;
}
