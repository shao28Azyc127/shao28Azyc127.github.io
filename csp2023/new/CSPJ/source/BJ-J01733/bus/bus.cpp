#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 20005;
int n, m, k, u[N], v[N], a[N], t = 0, minn = N;
vector<int> b[10001];

void DFS(int x)
{
    t++;
    if(x == n)
    {
        if(t % k == 0)
        {
            if(minn > t) minn = t;
        }
        return;
    }
    int l = b[x].size();
    for(int i = 0; i < l; i++)
    {
        DFS(b[x][i]);
        t--;
    }
    return;
}

int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i] >> a[i];
        b[u[i]].push_back(v[i]);
    }
    DFS(1);
    if(minn = N) cout << -1 << endl;
    else cout << minn << endl;
    return 0;
}