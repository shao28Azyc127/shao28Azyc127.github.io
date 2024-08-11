#include <iostream>
#include <cstdio>
using namespace std;
// YES YE5
// NO N0
int n, m;
int a[100005];
int zhuanhuan(char ch)
{
    if(ch == 'T') return 1;
    if(ch == 'F') return 0;
    if(ch == 'U') return -1;
    return 1e9;
}
int nt(int x)
{
    if(x == -1) return -1;
    return !x;
}
void work1()    // 20pts
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) a[i] = 0;
    // F = 0, T = 1, U = -1;
    for(int i = 1; i <= m; i++)
    {
        char v; int x;
        cin >> v >> x;
        //cout << v << " " << x <<endl;
        a[x] = zhuanhuan(v);
    }
    int cntu = 0;
    for(int i = 1; i <= n; i++) cntu += a[i] == -1;
    cout << cntu << endl;
}
int ans;
struct node{char op; int x, y;}f[100005];
int b[100005];
bool check()
{
    for(int i = 1; i <= n; i++) b[i] = a[i];
    for(int i = 1; i <= m; i++)
    {
        if(f[i].op == '+') b[f[i].x] = b[f[i].y];
        else if(f[i].op == '-') b[f[i].x] = nt(b[f[i].y]);
        else b[f[i].x] = zhuanhuan(f[i].op);
    }
    for(int i = 1; i <= n; i++)
        if(a[i] != b[i]) return false;
    return true;
}
void dfs(int step, int cntu)
{
    if(cntu > ans) return ;
    if(step > n)
    {
        if(check())ans = min(ans, cntu);
        return ;
    }
    a[step] = 0;
    dfs(step + 1, cntu);
    a[step] = 1;
    dfs(step + 1, cntu);
    a[step] = -1;
    dfs(step + 1, cntu + 1);
}
void work2()    // 20pts    1 & 2   AC
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> f[i].op;
        if(f[i].op == '+' || f[i].op == '-') cin >> f[i].x >> f[i].y;
        else cin >> f[i].x;
    }
    ans = 1e9;
    dfs(1, 0);
    cout << ans << endl;
}
int main()
{
    // work1    -----   --  +20pts
    // work2    1 & 2   AC  +20pts
    //freopen("tribool2.in", "r", stdin);
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    ios::sync_with_stdio(false);
    int c, t;
    cin >> c >> t;
    while(t--)
    {
        if(c == 3 || c == 4) work1();
        else if(c == 1 || c == 2) work2();
    }
    return 0;
}

