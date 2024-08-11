#include <bits/stdc++.h>
#define int long long
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define lob lower_bound
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int N = 1e5 + 10;
inline int read ()
{
    int x = 0, f = 1;
    char c = getchar ();
    while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c ^ 48); c = getchar (); }
    return x * f;
}
int n, m, k, d, test;
struct node {
    int x, y, z;
    bool operator < (const node &A) const {
        return x < A.x;
    }
} a[N];
int dp[N];
// struct Seg_tree {
//     int node;
//     struct node {
//         int ls, rs;
//         int sum;
//         #define ls(rt) tree[rt].ls
//         #define rs(rt) tree[rt].rs
//         #define sum(rt) tree[rt].sum
//     } tree[N << 5];
//     void pushup (int x) { sum(x) = sum(ls(x)) + sum(rs(x)); }
//     void modify (int &x, int l, int r, int p, int v)
//     {
//         if (!x) x = ++node;
//         if (l == r) { sum(x) += v; return ; }
//         int mid = (l + r) >> 1;
//         if (p <= mid) modify (ls(x), l, mid, p, v);
//         else modify(rs(x), mid + 1, r, p, v);
//         pushup (x);
//     }
//     int query (int x, int l, int r, int L, int R)
//     {
//         if (!x) return 0;
//         if (L <= l && r <= R) return sum(x);
//         int mid = (l + r) >> 1, res = 0;
//         if (L <= mid) res += query (ls(x), l, mid, L, R);
//         if (R > mid) res += query (rs(x), mid + 1, r, L, R);
//         return res;
//     }
// } T;
void solve ()
{
    n = read (), m = read (), k = read (), d = read ();
    for (int i = 1; i <= m; i++) a[i].x = read (), a[i].y = read (), a[i].z = read ();
    sort (a + 1, a + m + 1);
    memset (dp, 0, sizeof (dp));
    for (int i = 1; i <= m; i++)
    {
        dp[i] = max (dp[i], dp[i - 1]);
        if (a[i].y > k) continue;
        int sum = 0, p = i;
        int tmp = a[i].x - a[i].y + 1;
        for (int j = i; j >= 1; j--)
        {
            int tmp2 = min (tmp, a[j].x - a[j].y + 1);
            if ((a[i].x - tmp2 + 1) > k) continue;
            if (a[j].x < a[i].x - k + 1) break;
            tmp = min (tmp, a[j].x - a[j].y + 1);
            sum += a[j].z;
            while (p >= 1 && a[p].x + 1 >= tmp) p--;
            // cout << sum << " " << tmp << " " << (a[i].x - tmp + 1) << " " << (a[i].x - tmp + 1) * d << " " << p << " " << dp[p] << "\n";
            dp[i] = max (dp[i], sum - (a[i].x - tmp + 1) * d + dp[p]);
        }
        // dp[i] = max (dp[i], dp[tmp] + T.query (root, 1, n, a[i].x - a[i].y + 1, a[i].x) + a[i].z - k * d);
        // T.modify (root, 1, n, a[i].x - a[i].y + 1, a[i].z);
    }
    printf ("%lld\n", dp[m]);
}
signed main ()
{
    freopen ("run.in", "r", stdin);
    freopen ("run.out", "w", stdout);
    test = read (); int t = read ();
    while (t--) solve ();
    return 0;
}