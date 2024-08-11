#include<bits/stdc++.h>
using namespace std;

int n, m, k;
bool flag, bigflag;
int ro[10005][20005], a[10005][20005], cnt[10005];
bool sy[10005][105];

void awa(int now, int t)
{
    if(flag || t < 0) return;
    if(now == 1)
    {
        if(t % k == 0 && t >= 0)
        {
            flag = 1;
            bigflag = 1;
        }
        return;
    }
    if(sy[now][t % k]) return;
    sy[now][t % k] = 1;
    for(int i = 1; i <= cnt[now]; i++)
        if(t >= a[now][i]) awa(ro[now][i], t - 1);
}

bool check(int x)
{
    flag = 0;
    memset(sy, 0, sizeof(sy));
    awa(n, x * k);
    return flag;
}

int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        cnt[v]++;
        ro[v][cnt[v]] = u;
        cin >> a[v][cnt[v]];
    }
    int l = 0, r = 1010000 / k;
    while(l < r)
    {
        int mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    if(bigflag) cout << r * k << endl;
    else cout << "-1" << endl;
    return 0;
}
