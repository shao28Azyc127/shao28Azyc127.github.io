#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int a[20005];
int f[10005][1000];
bool b[10005];
struct node
{
    int x,t;
};
int n,m,k;
int ans = 1e9;
queue <node> q;

int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin >>n >>m>> k;
    for (int i = 1; i <= m; i++)
    {
        int u,v;
        cin >> u >> v >> a[i];
        f[u][0] ++;
        f[u][f[u][0]] = v;
    }

    q.push({1,k});
    b[1] = 1;
    bool flag = 0;
    while (!q.empty())
    {

        if (flag == 1) break;
        int x = q.front().x,t = q.front().t;
        if (x == n)
        {
            if (t %k == 0)
            {
                ans = t;
                flag = 1;
                break;
            }
            b[n] = 0;
        }
        q.pop();
        for (int i = 1; i <= f[x][0]; i++)
        {
            if (!b[f[x][i]])
            {
                b[f[x][i]] = 1;
                q.push({f[x][i],t+1});

            }
        }
    }
    if (flag == 1) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}
