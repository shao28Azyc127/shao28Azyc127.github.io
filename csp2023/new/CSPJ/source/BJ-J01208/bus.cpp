#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int a[10005][2005];
int lj[10005];
int vis[10005][2005];
int dis[10005];
int n, m, k;

int bfs(int x)
{
    queue<int> q;
    memset(dis, -1, sizeof dis);
    q.push(x);
    dis[x] = 0;
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
            if(t == n && dis[t] % 3 == 0) return dis[t];
        for(int i = 1; i <= lj[t]; i++)
	{
            int nx = vis[t][i];
            if(dis[nx] != -1 || a[nx][t] > dis[t]) continue;
            q.push(nx);
            dis[nx] = dis[t] + 1;
	}
    }
    return -1;
}


int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.ans", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
     	int x, y, t;
	cin >> x >> y >> t;
	a[x][y] = t;
	a[y][x] = t;
	lj[x]++, lj[y]++;
        vis[x][lj[x]] = y;
        vis[y][lj[y]] = x;
    }
    cout << bfs(1) << endl;
    return 0;
}

