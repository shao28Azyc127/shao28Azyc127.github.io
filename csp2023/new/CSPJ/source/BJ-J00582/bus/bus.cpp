#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#define int long long

using namespace std;

const int N = 1e4 + 5, K = 105;
struct node{
    int id, ti;
};
int n, m, k, u, v, t;
bool cnt[N][K];
priority_queue <node> q;
vector <node> e[N];

inline bool operator < (node x, node y){return x.ti > y.ti;}

signed main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    scanf("%lld %lld %lld", &n, &m, &k);
    for(register int i = 1;i <= m;i++)
    {
        scanf("%lld %lld %lld", &u, &v, &t);
        e[u].push_back({v, t});
    }
    q.push({1, 0});
    while(!q.empty())
    {
        node x = q.top();
        q.pop();
        if(cnt[x.id][x.ti % k])
            continue;
        cnt[x.id][x.ti % k] = true;
        if(x.id == n && x.ti % k == 0)
        {
            printf("%lld", x.ti);
            return 0;
        }
        for(register int i = 0;i < e[x.id].size();i++)
        {
            node y;
            y.id = e[x.id][i].id;
            if(x.ti + 1 >= e[x.id][i].ti)
                y.ti = x.ti + 1;
            else
            {
                y.ti = x.ti + 1 + ((e[x.id][i].ti - x.ti - 1) / k) * k;
                if(y.ti < e[x.id][i].ti)
                    y.ti += k;
            }
            q.push(y);
        }
    }
    printf("-1");
    return 0;
}
