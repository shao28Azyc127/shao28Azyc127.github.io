#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int a[10005][10005];
int n,m,k;

int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++)
    {
        int u,v,x;
        cin >> u >> v >> x;
        a[u][v] = x;
        a[v][u] = x;
    }

    cout << k << endl;
    return 0;
}
