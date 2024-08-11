

#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long

using namespace std;

struct Opt {
    ll l;
    ll r;
    ll v;
} Q[100009];

int C;
int T;
int N;
int M;
int K;
ll D;
ll dp1[10009][1009];
ll dp2[100009][109];
ll dp3[100009];
ll tr[100009];
ll res;

bool Cmp (Opt a, Opt b) {
    return a.r < b.r;
}

void Add (int x, ll v) {
    if (x <= 0) return;
    for (; x <= N; x += (x & -x)) tr[x] += v;
}

ll Query (int x) {
    ll ans = 0;
    if (x <= 0) return 0;
    for (; x; x -= (x & -x)) ans += tr[x];
    return ans;
}

ll Get_S (int l, int r) {
    return Query(r) - Query(l - 1);
}

ll Max (ll a, ll b) {
    return a > b ? a : b;
}

int main () {
    int t;
    int tt;

    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    scanf("%d%d", &C, &T);
    while (T--) {
        scanf("%d%d%d%lld", &N, &M, &K, &D);
        for (int i = 1; i <= M; i++) scanf("%lld%lld%lld", &Q[i].r, &Q[i].l, &Q[i].v), Q[i].l = Q[i].r - Q[i].l + 1;
        sort(Q + 1, Q + M + 1, Cmp);
        if (C <= 9) {
            memset(dp1, 0xf1, sizeof(dp1));
            memset(tr, 0, sizeof(tr));
            t = 1, dp1[0][0] = 0;
            for (int i = 1; i <= N; i++) {
                tt = t;
                while (t <= M && Q[t].r == i) Add(Q[t].l, Q[t].v), t++;
                for (int j = 0; j <= K && j <= i - 1; j++) dp1[i][0] = Max(dp1[i][0], dp1[i - 1][j]);
                for (int j = 1; j <= K && j <= i; j++) dp1[i][j] = Max(dp1[i][j], dp1[i - 1][j - 1] + Get_S(i - j + 1, i) - D);
                for (int j = tt; j < t; j++) Add(Q[j].l, -Q[j].v);
            }
            res = -1e18;
            for (int j = 0; j <= K && j <= N; j++) res = Max(res, dp1[N][j]);
            printf("%lld\n", res);
        }
        else {
            memset(dp3, 0xf1, sizeof(dp3));
            dp3[0] = 0;
            for (int i = 1; i <= M; i++) {
                dp3[i] = dp3[i - 1];
                if (Q[i].l > 0) dp3[i] = Max(dp3[i], dp3[i - 1] + Q[i].v - (Q[i].r - Q[i].l + 1) * D);
            }
            printf("%lld\n", dp3[M]);
        }
    }
    fclose(stdin), fclose(stdout);
    return 0;
}