#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;

struct point
{
    int id, s;
    friend bool operator<(const point &a, const point &b)
    {
        return a.s < b.s;
    }

};

priority_queue<point> q;

int dis[100005];
long long sumdis[100005];
int a[100005], pos[100005];

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n - 1; ++i)
    {
        cin >> dis[i];
        sumdis[i] = sumdis[i - 1] + dis[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        while (!q.empty() && q.top().s > a[i])
        {
            pos[q.top().id] = i;
            q.pop();
        }
        q.push({i, a[i]});
    }
    while (!q.empty())
    {
        pos[q.top().id] = n;
        q.pop();
    }
    int poss = 1;
    long long sheng = 0;
    long long ans = 0;
    while (poss != n)
    {
        int x = ceil(1.0 * (sumdis[pos[poss] - 1] - sumdis[poss - 1] - sheng) / d);
        ans += x * a[poss];
        sheng %= d;
        sheng += x * d - (sumdis[pos[poss] - 1] - sumdis[poss - 1]);
        poss = pos[poss];
    }
    cout << ans;
    return 0;
}
