#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int read()
{
    int n = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') n = n*10+(ch^48), ch = getchar();
    return n*f;
}
int C, n, m, q;
int cx[500005], cy[500005];
int x[500005], y[500005], yy[500005];
int pre[500005][22], nxt[500005][22];
int st[500005], top;
bool work()
{
    memset(pre, 0, sizeof(int)*(n+2));
    memset(nxt, 0, sizeof(int)*(n+2));
    x[0] = 2e9;
    st[top = 1] = 0;
    for(int i = 1; i <= n; i++)
    {
        while(top && x[st[top]] <= x[i]) top--;
        pre[i][0] = st[top];
        st[++top] = i;
    }
    x[n+1] = -2e9;
    st[top = 1] = n+1;
    for(int i = n; i >= 1; i--)
    {
        while(top && x[st[top]] >= x[i]) top--;
        nxt[i][0] = st[top];
        st[++top] = i;
    }
    nxt[n+1][0] = n+1;
    nxt[0][0] = 1;
    pre[n+1][0] = n;
    pre[0][0] = 0;
    const int lim = 16;
    for(int i = 0; i <= n+1; i++) for(int j = 1; j <= lim; j++) pre[i][j] = pre[pre[i][j-1]][j-1];
    for(int i = n+1; i >= 0; i--) for(int j = 1; j <= lim; j++) nxt[i][j] = nxt[nxt[i][j-1]][j-1];
    yy[1] = y[1], yy[2] = y[2];
    top = 2;
    for(int i = 3; i <= m; i++)
    {
        if(yy[top-1] <= yy[top] && yy[top] <= y[i]) yy[top] = y[i];
        else if(yy[top-1] >= yy[top] && yy[top] >= y[i]) yy[top] = y[i];
        else yy[++top] = y[i];
    }
    int cur = 1;
    for(int i = 1; i <= top; i++)
    {
        for(int j = lim; j >= 0; j--) while(x[nxt[cur][j]] > yy[i]) cur = nxt[cur][j];
        for(int j = lim; j >= 0; j--) while(x[pre[cur][j]] <= yy[i]) cur = pre[cur][j];
        if(x[cur] <= yy[i]) cur = pre[cur][0];
        cur = nxt[cur][0]-1;
        if(!cur) return 0;
    }
    if(nxt[cur][0] == n+1) return 1;
    return 0;
}
void solve()
{
    bool flag = 0;
    if(x[1] < y[1])
    {
        for(int i = 1; i <= n; i++) x[i] *= -1;
        for(int j = 1; j <= m; j++) y[j] *= -1;
        flag = 1;
    }
    putchar(work()?'1':'0');
    if(flag)
    {
        for(int i = 1; i <= n; i++) x[i] *= -1;
        for(int j = 1; j <= m; j++) y[j] *= -1;
    }
}
int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    C = read(), n = read(), m = read(), q = read();
    for(int i = 1; i <= n; i++) cx[i] = read();
    for(int i = 1; i <= m; i++) cy[i] = read();
    memcpy(x, cx, sizeof(x));
    memcpy(y, cy, sizeof(y));
    solve();
    vector<int> aa, bb;
    for(int i = 1; i <= q; i++)
    {
        int kx = read(), ky = read();
        for(int i = 1; i <= kx; i++)
        {
            int p = read(), v = read();
            x[p] = v;
            aa.emplace_back(p);
        }
        for(int i = 1; i <= ky; i++)
        {
            int p = read(), v = read();
            y[p] = v;
            bb.emplace_back(p);
        }
        solve();
        for(auto p: aa) x[p] = cx[p];
        for(auto p: bb) y[p] = cy[p];
    }
    putchar('\n');
    return 0;
}