#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;

const int N = 10010;

int n,m,k;

/*
struct edge
{
    int to, w, nxt;
}e[N*2];
int cnt,head[N];
void add(int x, int y, int z)
{
    e[++cnt] = (edge){y,z,head[x]};
    head[x]++;
}
*/

vector<int> g[N];
vector<int> w[N];

int ans = 1e9;
int vis[N];

void dfs(int x, int tm, int minn)
{
    //cout << x << "\n";
    vis[x]++;
    if(x == n)
    {
        //cout << tm << "*\n";
        if(tm % k == 0) ans = min((minn + k-1)/k*k + tm, ans);
        return;
    }
    if(vis[x] >= k-1) return;
    if((minn + k-1)/k*k + tm >= ans) return;
    for(int i = 0;i < g[x].size();i++)
    {
        int y = g[x][i];
        int t = w[x][i];
        dfs(y, tm+1, max(t-tm, minn));
    }
    vis[x]--;
}

int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back(y);
        w[x].push_back(z);
    }

    dfs(1,0,0);
    if(ans == 1e9) puts("-1");
    else cout << ans;
    return 0;
}
