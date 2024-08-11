#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll a[25], b[25], c[25];
int s[25] = {1};
const ll inf = 1e18+10000;
int n;
ll ret = inf;
vector<int> g[25];
bool vis[25];
ll get(int p, int s)
{
    auto f = [&](int t){ return (long long)(t-s+1)*b[p]+(long long)(t+s)*(t-s+1)/2*c[p]; };
    int x = c[p]?(b[p]-1)/(-c[p]):-1;
    if(c[p] < 0 && x < s) return inf;
    if(c[p] >= 0 || f(x) >= a[p])
    {
        int l = s, r = 1e9+100;
        if(c[p] < 0) r = x;
        while(l <= r)
        {
            int mid = (l+r)>>1;
            if(f(mid) >= a[p]) r = mid-1;
            else l = mid+1;
        }
        return l;
    }
    if(p == 4) cerr << "! " << s << " " << x+a[p] << " " << f(x) << endl;
    return x+a[p]-f(x);
}
void check()
{
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans = max(ans, get(s[i], i));
        cerr << i << " " << s[i] << " " << get(s[i], i) << endl;
    }
    // cerr << ans << endl;
    ret = min(ret, ans);
}
void dfs(int p)
{
    if(p > n) return check();
    // int tmp[25] = {0};
    for(int i = 1; i < p; i++)
    {
        int u = s[i];
        for(auto v: g[u])
        {
            cerr << ": " << p << " " << u << " " << v << endl;
            if(vis[v]) continue;
            // tmp[v] = 1;
            vis[v] = 1;
            s[p] = v;
            dfs(p+1);
            vis[v] = 0;
        }
    }
}
int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vis[1] = 1;
    s[1] = 1;
    dfs(2);
    cout << ret;
    return 0;
}