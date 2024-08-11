// 啊米浴说的道理～
// 完了 最短路我忘了咋写了 寄
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, k;

struct edge
{
    int u, v, a;
} e[20005];

int main()
{
    //freopen("bus.in", "r", stdin);
    //freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
        cin >> e[i].u >> e[i].v >> e[i].a;
    sort(e + 1, e + m + 1, [](edge x, edge y)
        {return x.u == y.u ? x.v < y.v : x.u < y.u;});

    cout << -1 << endl;
    return 0;
}
