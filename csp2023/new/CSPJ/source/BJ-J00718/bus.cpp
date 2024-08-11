// stO xingcunzhe Orz
// stO PEKKA_l Orz
// stO SUPERTIG Orz
// yangyang1000 is caiji
#include <cstdio>
#include <iostream>
using namespace std;

const int NR = 1e4 + 10;
const int MR = 2e4 + 10;
int n, m, k, ans = 2e9;
int u[MR], v[MR], a[MR];
int cur[NR], vis[NR];

void dfs(int last, int step)
{
    if (last == n)
    {
        if ((step - 1) % k == 0)
        {
            int ckkk = 0;
            for (int i = 1; i <= step - 1; i++) ckkk = max(ckkk, cur[vis[i]]);
            if ((step - 1) % k == 0) ans = step + ckkk;
        }
        return;
    }
    if (step > ans) return;
    for (int i = 1; i <= m; i++)
    {
        if (u[i] == last)
        {
            cur[v[i]] = max(0, a[i] - step + 1);
            vis[step] = v[i];
            dfs(v[i], step + 1);
            cur[v[i]] = 0;
            vis[step] = 0;
        }
    }
}
int main()

{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++) scanf("%d%d%d", &u[i], &v[i], &a[i]);
    dfs(1, 1);
    if (ans == 2e9) printf("-1\n");
    else printf("%d", ans);
    return 0;
}

// CSP-J2023 rp++
