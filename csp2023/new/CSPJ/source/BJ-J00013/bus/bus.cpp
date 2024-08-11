#include <bits/stdc++.h>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define lowbit(x) ((x)&-(x))
#define abs(x) (((x)>=0)?(x):((-x)))
#define MAXN 200005
#define MAXK 105
#define pipii pair<int,pair<int,int> >
#define pii pair<int,int>
#define se second
#define fi first
#define gettime(now,lim) ((now >= lim) ? (now + 1) : (now + (lim - now + k - 1) / k * k + 1))
using namespace std;
// priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > q;
queue<pair<int,pair<int,int> > > q;
vector<pair<int,int> > e[MAXN];
int n, m, k, u, v, a, dis[MAXN][MAXK];
bool cmp(pii x, pii y)
{
    return x.second < y.second;
}
signed main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for (register int i = 1; i <= m; i++)
    {
        scanf("%lld%lld%lld",&u,&v,&a);
        e[u].push_back({v,a});
    }
    for (register int i = 1; i <= n; i++)
    {
        sort(e[i].begin(),e[i].end(),cmp);
    }
    memset(dis,0x3f,sizeof(dis));
    dis[1][0] = 0;
    q.push({0,{1,0}});
    while (!q.empty())
    {
        const pipii t = q.front();
        q.pop();
        if (dis[t.se.fi][t.se.se] != t.fi)
        {
            continue;
        }
        for (register pii i : e[t.se.fi])
        {
            const int nowtime = gettime(t.fi, i.se);
            const int nowtimemodk = nowtime % k;
            if (dis[i.fi][nowtimemodk] > nowtime)
            {
                dis[i.fi][nowtimemodk] = nowtime;
                q.push({nowtime,{i.fi,nowtimemodk}});
            }
        }
    }
    /*
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }
    */
    if (dis[n][0] >= 1e12)
    {
        cout << -1;
        return 0;
    }
    cout << dis[n][0];
    return 0;
}
