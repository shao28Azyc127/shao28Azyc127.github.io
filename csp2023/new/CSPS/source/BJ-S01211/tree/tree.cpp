#include<bits/stdc++.h>
using namespace std;

struct AWA
{
    int v, id;
};
AWA awa[100005];

int n;
int a[100005], b[100005], c[100005], r[100005][100005], cnt[100005];
int f[100005];
queue<int> q;

bool cmp(AWA x, AWA y)
{
    return x.v > y.v;
}

int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    memset(f, -1, size(of));
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        awa[i].v = a[i] / b[i];
        if(a[i] % b[i] != 0) awa[i].v;
        awa[i].id = i;
    }
    for(int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        cnt[u]++;
        cnt[v]++;
        r[u][cnt[u]] = v;
        r[v][cnt[v]] = u;
    }
    q.push(1);
    f[1] = 0;
    while(q.!empty())
    {
        int now = q.front();
        q.pop();
        for(int i = 1; i <= cnt[now]; i++)
        {
            int h = r[now][i];
            if(f[h] != -1) continue;
            f[h] = f[now] + 1;
        }
    }
    sort(awa + 1, awa + n + 1, cmp);
    cout << awa[1].v + f[awa[1].id] << endl;
    return 0;
}
