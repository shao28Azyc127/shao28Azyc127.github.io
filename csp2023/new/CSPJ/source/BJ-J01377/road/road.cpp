#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, d;
int v[100005], a[100005];
int nxt[100005];
struct node
{
    int dis, id;
};
bool operator < (node x, node y)
{
    return x.dis < y.dis;
}
priority_queue<node> q;
signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%lld%lld", &n, &d);
    for (int i = 2; i <= n; i++)
    {
        cin >> v[i];
        v[i] += v[i - 1];
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        while(!q.empty() && q.top().dis > a[i])
        {
            nxt[q.top().id] = i;
            q.pop();
        }
        q.push(node{a[i], i});
    }
    int nowid = 1, nowdis = 0, sum = 0;
    while(nowid != n)
    {
        if (nxt[nowid] == 0)
        {
            if (nowdis >= v[n] - v[nowid]) break;
            else
            {
                sum += ((v[n] - v[nowid] - nowdis) % d == 0 ? (v[n] - v[nowid] - nowdis) / d * a[nowid] : ((v[n] - v[nowid] - nowdis) / d + 1) * a[nowid]);
                break;
            }
        }
        else
        {
            if (nowdis >= v[nxt[nowid]] - v[nowid])
            {
                nowdis -= v[nxt[nowid]] - v[nowid];
                nowid = nxt[nowid];
            }
            else
            {
                int ret = ((v[nxt[nowid]] - v[nowid] - nowdis) % d == 0 ? (v[nxt[nowid]] - v[nowid] - nowdis) / d : (v[nxt[nowid]] - v[nowid] - nowdis) / d + 1);
                sum += ret * a[nowid];
                nowdis += ret * d;
                nowdis -= (v[nxt[nowid]] - v[nowid]);
                nowid = nxt[nowid];
            }
        }
    }
    printf("%lld\n", sum);
    return 0;
}
