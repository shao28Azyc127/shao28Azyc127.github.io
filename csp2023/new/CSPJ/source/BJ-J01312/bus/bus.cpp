#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define int long long
using namespace std;
const int N = 1e4 + 10;
vector<int> v[N];
int ans = 1e9;
map<int, int> j[N];
int n, m, k;
void bfs(int u)
{
    queue<int> q, t;
    q.push(u);
    t.push(3);
    while(!q.empty())
    {
        int nx = q.front(), tx = t.front();
        q.pop(), t.pop();
        if(nx == n) ans = min(tx, ans);
        for(auto x : v[nx])
        {
            int ux = x;
            if(j[nx][ux] > tx) continue;
            q.push(ux);
            t.push(tx + 1);
        }
    }
}
signed main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        j[a][b] = c;
        v[a].push_back(b);
    }
    bfs(1);
    if(ans == 1e9) cout <<- 1;
    else if(ans % k == 0) cout << ans;
    else cout << ans + (k - ans % k);
    return 0;
}
