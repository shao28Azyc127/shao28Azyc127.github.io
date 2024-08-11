# include <bits/stdc++.h>
# define int long long
# define maxn 100005
using namespace std;
int n, ans;
int cnt[maxn];
int nxt(int i, int w)
{
    if(i + w >= 10) return i + w - 10;
    return i + w;
}
void sol(int b[])
{
    for(int i = 1; i <= 5; i++)
        for(int j = 1; j <= 9; j++){
            int cur = b[i];
            b[i] = nxt(b[i], j);
            int now = 0;
            for(int k = 1; k <= 5; k++)  now *= 10, now += b[k];
            cnt[now]++;
            b[i] = cur;
        }
    for(int i = 1; i <= 4; i++)
        for(int j = 1; j <= 9; j++){
            int curx = b[i];
            b[i] = nxt(b[i], j);
            int cury = b[i + 1];
            b[i + 1] = nxt(b[i + 1], j);
            int now = 0;
            for(int k = 1; k <= 5; k++)  now *= 10, now += b[k];
            cnt[now]++;
            b[i] = curx;
            b[i + 1] = cury;
        }
}
signed main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int b[6];
        for(int i = 1; i <= 5; i++) cin >> b[i];
        sol(b);
    }
    for(int i = 0; i < 100000; i++){
        if(cnt[i] == n) ans++;
    }
    cout << ans << '\n';
    return 0;
}
