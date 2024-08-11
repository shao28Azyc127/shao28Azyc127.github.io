#include<bits/stdc++.h>
using namespace std;
const int N = 20010;
int n, m, k;
int h[N], e[N], ne[N], idx;
int dist[N];
int st[N];
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}
void spfa()
{
    memset(dist, 0x3f, sizeof dist);
    queue<int> q;
    q.push(1);
    st[1] = 1;
    dist[1] = 0;
    while(q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = 0;
        for(int i = h[t]; ~i ;i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[t] + 1)
            {
                dist[j] = dist[t] + 1;
                if(!st[j])
                {
                    st[j] = 1;
                    q.push(j);
                } 
            }
        }
    }
}
int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i ++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b);
    }
    spfa();
    if(dist[n] == 0x3f3f3f3f) cout << -1 << endl;
    else
    {
        if(dist[n] % k == 0) cout << dist[n] << endl;
        else cout << k * (dist[n] / k + 1) << endl;
    }
    return 0;
}
