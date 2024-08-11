#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int MAXN = 10005;
const int MAXM = 100005;
int c, t, n, m, k;
LL f[MAXN][MAXN], g[MAXN][MAXN], d;
vector<pair<int, LL> > Adj[MAXN];
struct node {
    int x, y; LL v;
}a[10005];

bool cmp(node a , node b) {
    return a.y < b.y;
}

int main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    cin >> c >> t;
    while(t--) {
        cin >> n >> m >> k >> d;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) f[i][j] = g[i][j] = -1e17;

        }
        for(int i = 1; i <= n; i++) Adj[i].clear();
        for(int i = 1; i <= m; i++)
            cin >> a[i].x >> a[i].y >> a[i].v;
        sort(a + 1, a + m + 1, cmp);
        for(int i = 1; i <= m; i++)
            Adj[a[i].x].push_back(make_pair(a[i].y, a[i].v));
       //
        f[0][0] = 0; g[0][0] = 0;
        for(int i = 1; i <= n; i++) {
            int nowst = -1; LL nans = 0;
            f[i][1] = f[i - 1][0];
            for(int j = 1; j <= min(i, k); j++) {

                    //cout <<nowst << "-="<< (int)Adj[i].size() - 1<< endl;
                while(nowst < (int)Adj[i].size() - 1 && (j >= (int)Adj[i][nowst + 1].first)) nowst++, nans += Adj[i][nowst].second;
                //cout << i << " " << j << " -> " << (nowst < (int)Adj[i].size() - 1?Adj[i][0].first:-123) << " " << nowst << endl;
                LL ta = -1e17;
                f[i][j] = max(f[i][j], f[i - 1][j - 1] - d * j + nans);

            }
        }
        LL ans = -1e17;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                ans = max(ans, f[i][j]);
        cout << ans << endl;
    }
    return 0;
}
