#include <bits/stdc++.h>

using namespace std;

struct dian
{
    int l;
    vector <int> v;
    vector <int> a;
};
dian st[10005];
int ans = (1 << 30);
int n, m, k;
int h[10005];

void dfs(int wz, int shi_jian, int maxn)
{
    if(wz == n)
    {
        if(shi_jian % k != 0)
        {
            return ;
        }
        ans = min(ans, (maxn + k - 1) / k * k + shi_jian);
        return ;
    }
    if(h[wz] == 1) return ;
    h[wz] = 1;
    int i, j;
    for(i=1; i<=st[wz].l; i++)
    {
        dfs(st[wz].v[i], shi_jian + 1, max(maxn, st[wz].a[i] - shi_jian));
    }
    return ;
}


int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    int i, j;
    cin >> n >> m >> k;
    int u, vv, aa;
    for(i=1; i<=m; i++)
    {
        cin >> u >> vv >> aa;
        st[u].l++;
        if(st[u].l == 1)
        {
            st[u].v.push_back(0);
            st[u].a.push_back(0);
        }
        st[u].v.push_back(vv);
        st[u].a.push_back(aa);

    }
    dfs(1, 0, 0);
    //cout << ans << endl;
    if(ans == (1 << 30)) cout << -1 << endl;
    else cout << ans << endl;


    return 0;
}
