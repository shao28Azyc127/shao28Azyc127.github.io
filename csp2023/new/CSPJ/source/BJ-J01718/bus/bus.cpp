//I'm sorry but........no time left enough to write the AC code....
//And no enough time to make it clear :(

//So sorry..........
//Anyway this will be a great memory
//And great experience..........
//Wish this kind of fault will never happen again
//Never ever...

#include <bits/stdc++.h>
using namespace std;

const int uplim = 2e2 + 10, NR = 1e6 + 10;
int ans = 2147483647, n, m, k;
vector <pair<int, int> > adj[NR];

void dfs(int u, int erl, int stp)
{
    if(u == 1 && (stp % k) == 0)
    {
        ans = min(ans, (erl + (k - 1)) / k * k + stp);
        return;
    }
    if(stp > uplim) return;
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i].first, w = adj[u][i].second;
        dfs(v, max(erl - 1, w), stp + 1);
    }
}

int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        //adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    dfs(n, 0, 0);
    cout << ans << endl;
    return 0;
}