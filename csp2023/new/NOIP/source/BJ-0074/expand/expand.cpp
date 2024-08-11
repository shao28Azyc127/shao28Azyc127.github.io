#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for (auto i=(a);i<=(b);++i)
#define per(i,a,b) for (auto i=(a);i>=(b);--i)

#define N int(2010)
#define N1 int(500010)

int n,m;
bool dp[N][N][2];
int a[N1];
int b[N1];
vector<pair<int,int>> dx,dy;

void work()
{
    if (a[1]>b[1]) dp[1][1][1]=true;
    else if (a[1]<b[1]) dp[1][1][0]=true;
    rep (i,1,n) rep (j,1,m)
    {
        rep (k,0,1)
        {
            dp[i+1][j][k]|=dp[i][j][k]&&(k?a[i+1]>b[j]:a[i+1]<b[j]);
            dp[i][j+1][k]|=dp[i][j][k]&&(k?a[i]>b[j+1]:a[i]<b[j+1]);
            dp[i+1][j+1][k]|=dp[i][j][k]&&(k?a[i+1]>b[j+1]:a[i+1]<b[j+1]);
        }
    }
    // cerr<<dp[1][1][0]<<','<<dp[1][1][1]<<'\n';
    cout<<(dp[n][m][0]||dp[n][m][1]);
    rep(i,0,n)rep(j,0,m)rep(k,0,1)dp[i][j][k]=false;
}

bool _8_14_P1()
{
    int x=1,y=1;
    while (y<=m)
    {
        if (a[x]>=a[y]) return 0;
        while (a[x]<b[y]&&x<=n) x++;
        if (x==n+1) break;
        else y++;
    }
    while (y<=m) if (b[y++]<=a[n]) return 0;
    return 1;
}

bool _8_14_P2()
{
    int x=1,y=1;
    while (x<=n)
    {
        if (a[x]>=a[y]) return 0;
        while (a[x]<b[y]&&y<=m) y++;
        if (y==n+1) break;
        else x++;
    }
    while (x<=n) if (b[m]<=a[x++]) return 0;
    return 1;
}

void work_8_14()
{
    cout<<(_8_14_P1()||_8_14_P2());
}

int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int c,q;
    cin>>c>>n>>m>>q;
    rep (i,1,n) cin>>a[i];
    rep (i,1,m) cin>>b[i];
    if (c<=7) work();
    else work_8_14();
    while (q--)
    {
        int xx,yy;
        cin>>xx>>yy;
        while (xx--)
        {
            int u,v;
            cin>>u>>v;
            dx.emplace_back(u,a[u]);
            a[u]=v;
        }
        while (yy--)
        {
            int u,v;
            cin>>u>>v;
            dy.emplace_back(u,b[u]);
            b[u]=v;
        }
        if (c<=7) work();
        else work_8_14();
        for (auto&p:dx) a[p.first]=p.second;
        for (auto&p:dy) b[p.first]=p.second;
        dx.clear();
        dy.clear();
    }
    return 0;
}
