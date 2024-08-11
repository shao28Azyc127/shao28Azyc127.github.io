// 8pts
#include <iostream>
#include <cstdio>
using namespace std;
int n, m, k, d;
struct node{int x, y, v;} w[100005];
void work1()
{
    long long ret = 0;
    for(int i = 1; i <= m; i++)
        if(w[i].y <= k && w[i].y * d < w[i].v) ret += w[i].v - w[i].y * d;
    cout << ret << endl;
}


bool flag[25];
long long ans = 0;
long long get()
{
    long long ret = 0;
    for(int i = 1; i <= m; i++)
    {
        bool fg = true;
        for(int j = w[i].x - w[i].y + 1; j <= w[i].x && fg; j++) fg &= flag[j];
        if(fg) ret += w[i].v;
    }
    return ret;
}
void dfs(int i, int lian, long long sum)
{
    if(lian > k) return;
    if(i > n)
    {
        ans = max(ans, get() - sum);
        return ;
    }
    flag[i] = false;
    dfs(i+1, 0, sum);
    flag[i] = true;
    dfs(i+1, lian+1, sum + d);
}

void work2()
{
    ans = 0;
    dfs(0, 0, 0);
    cout << ans << endl;
}

int main()
{
    // work1    run5    AC  8pts
    // work2    run1    AC  8pts
    //freopen("run1.in", "r", stdin);
    //freopen("run1.out", "w", stdout);
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> m >> k >> d;
        for(int i = 1; i <= m; i++) scanf("%d %d %d", &w[i].x, &w[i].y, &w[i].v);
        if(c == 17 || c == 18) work1();
        else work2();
    }
    return 0;
}
