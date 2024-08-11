#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int c, t, n, m, k, d;
struct node{
    int x, y, v;
}f[N];
bool cmp(node a, node b)
{
    return a.x<b.x;
}
int main ()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    cin >> c >>t;
    while (t--)
    {
        long long ans = 0;
        cin >> n >> m >> k >> d;
        for (int i=1;i<=m;i++)
        {
            cin >>f[i].x >>f[i].y >> f[i].v;
            ans+=max(f[i].v-f[i].y*d, 0);
        }
        cout << ans;
    }
    return 0;
}
