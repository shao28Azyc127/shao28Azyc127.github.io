#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int c, ns, ms, n, m, t, Xs[500005], Ys[500005], X[500005], Y[500005];
int kx, ky, p, v, minn1, maxx1, minn2, maxx2;
bool vis[2005][2005];
void swapp()
{
    swap(n, m);
    for (int i = 1; i <= max(n, m); i++)
        swap(X[i], Y[i]);
}
bool check()
{
    if (X[1] == Y[1] || X[n] >= Y[m])
        return false;
    maxx1 = maxx2 = -1;
    minn1 = minn2 = 2000000000;
    for (int i = 1; i <= n; i++)
    {
        minn1 = min(minn1, X[i]);
        maxx1 = max(maxx1, X[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        minn2 = min(minn2, Y[i]);
        maxx2 = max(maxx2, Y[i]);
    }
    if (minn1 >= minn2 || maxx1 >= maxx2)
        return false;
    if (n > 2000 || m > 2000)
        return true;
    queue<pair<int, int> > q;
    memset(vis, false, sizeof(vis));
    q.push({1, 1});
    while (!q.empty() && !vis[n][m])
    {
        pair<int, int> now = q.front();
        q.pop();
        int x = now.first;
        int y = now.second;
        vis[x][y] = true;
        int xd[3] = {1, 0, 1};
        int yd[3] = {0, 1, 1};
        for (int k = 0; k < 3; k++)
        {
            if (x + xd[k] <= n && y + yd[k] <= m && X[x + xd[k]] < Y[y + yd[k]])
                q.push({x + xd[k], y + yd[k]});
        }
    }
    return vis[n][m];
}
int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    cin >> c >> ns >> ms >> t;
    n = ns, m = ms;
    for (int i = 1; i <= n; i++)
    {
        cin >> Xs[i];
        X[i] = Xs[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> Ys[i];
        Y[i] = Ys[i];
    }
    if (X[1] > Y[1])
        swapp();
    cout << check();
    while (t--)
    {
        cin >> kx >> ky;
        n = ns, m = ms;
        for (int i = 1; i <= n; i++)
            X[i] = Xs[i];
        for (int i = 1; i <= m; i++)
            Y[i] = Ys[i];
        for (int i = 1; i <= kx; i++)
        {
            cin >> p >> v;
            X[p] = v;
        }
        for (int i = 1; i <= ky; i++)
        {
            cin >> p >> v;
            Y[p] = v;
        }
        if (X[1] > Y[1])
            swapp();
        cout << check();
    }
    cout << endl;
    return 0;
}
