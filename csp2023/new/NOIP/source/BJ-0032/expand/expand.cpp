#include <iostream>
#include <algorithm>

typedef long long ll;
typedef double lf;

namespace FastIO
{
    const int MAXSIZE = 1 << 20;
    char buf[MAXSIZE], *p1, *p2;
    #define gc() (p1 == p2 && ((p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin)), p1 == p2) ? EOF : *p1++)
    template <typename T>
    inline void Read(T &x)
    {
        x = 0; bool sgn = 0; char ch = gc();
        while (ch < '0' || ch > '9') {if (ch == '-') sgn = 1; ch = gc();}
        while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = gc();
        if (sgn) x = -x;
    }
}

using FastIO::Read;
using namespace std;

const int MAXN = 5e5 + 10;

int n, m, q, a[MAXN], b[MAXN];
int CApos[MAXN], CBpos[MAXN], CAval[MAXN], CBval[MAXN];

int a1[MAXN], a2[MAXN], b1[MAXN], b2[MAXN], ta1, ta2, tb1, tb2;
// a inc, a dec, b inc, b dec
bool ans = 1;
inline void Solve()
{
    ta1 = ta2 = tb1 = tb2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!ta1 || a[a1[ta1]] < a[i]) a1[++ta1] = i;
        if (!ta2 || a[a2[ta2]] > a[i]) a2[++ta2] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        if (!tb1 || b[b1[tb1]] < b[i]) b1[++tb1] = i;
        if (!tb2 || b[b2[tb2]] > b[i]) b2[++tb2] = i;
    }
    if (a[1] == b[1] || a[n] == b[m]) {ans = 0; return;}
    // for (int i = 1; i <= ta1; i++) cout << a1[i] << " "; cout << "\n";
    if (a[1] > b[1])
    {
        if (a[n] < b[m]) {ans = 0; return;}
        int ra = n, rb = m;
        for (int i = ta2, j = ta1, u = tb1, v = tb2; i >= 1; i--)
        {
            while (j >= 1 && a1[j] > ra) j--;
            while (u >= 1 && b1[u] > rb) u--;
            if (u && a[a1[j]] <= b[b1[u]]) {ans = 0; break;}
            while (v >= 1 && b[b2[v]] < a[a2[i]]) v--; v++;
            if (v > tb2) {ans = 0; break;}
            // cout << a2[i] << " " << a1[j] << " " << b1[u] << " " << b2[v] << "\n";
            // if (v > tb1 || b2[v] > rb) {ans = 0; break;}
            ra = a2[i] - 1, rb = b2[v] - 1;
        }
    }
    else
    {
        if (a[n] > b[m]) {ans = 0; return;}
        int ra = n, rb = m;
        for (int i = tb2, j = tb1, u = ta1, v = ta2; i >= 1; i--)
        {
            while (j >= 1 && b1[j] > rb) j--;
            while (u >= 1 && a1[u] > ra) u--;
            if (u && b[b1[j]] <= a[a1[u]]) {ans = 0; break;}
            while (v >= 1 && a[a2[v]] < b[b2[i]]) v--; v++;
            if (v > ta2) {ans = 0; break;}
            // if (!q) cout << v << "\n";
            // if (!q)
            // cout << b2[i] << " " << b1[j] << " " << a1[u] << " " << a2[v] << "\n";
            // if (v > ta1 || a2[v] > ra) {ans = 0; break;}
            rb = b2[i] - 1, ra = a2[v] - 1;
        }
    }
}

inline void Check()
{
    ans = 1;
    Solve();
    reverse(a + 1, a + n + 1), reverse(b + 1, b + m + 1);
    Solve();
    reverse(a + 1, a + n + 1), reverse(b + 1, b + m + 1);
    if (ans) cout << "1";
    else cout << "0";
        // cout << "\n";
}

int tmp[MAXN], tot;

int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    int CASE;
    Read(CASE), Read(n), Read(m), Read(q);
    for (int i = 1; i <= n; i++) Read(a[i]);
    for (int i = 1; i <= m; i++) Read(b[i]);

        // tot = 0;
        // for (int i = 1; i <= n; i++) tmp[++tot] = a[i];
        // for (int i = 1; i <= m; i++) tmp[++tot] = b[i];
        // sort(tmp + 1, tmp + tot + 1);
        // tot = unique(tmp + 1, tmp + tot + 1) - tmp - 1;
        // for (int i = 1; i <= n; i++) cout << lower_bound(tmp + 1, tmp + tot + 1, a[i]) - tmp << " "; cout << "\n";
        // for (int i = 1; i <= m; i++) cout << lower_bound(tmp + 1, tmp + tot + 1, b[i]) - tmp << " "; cout << "\n";
    Check();
    int k1, k2;
    while (q--)
    {
        Read(k1), Read(k2);
        for (int i = 1; i <= k1; i++) Read(CApos[i]), Read(CAval[i]), swap(a[CApos[i]], CAval[i]);
        for (int i = 1; i <= k2; i++) Read(CBpos[i]), Read(CBval[i]), swap(b[CBpos[i]], CBval[i]);
//         if (!q)
//         {
// tot = 0;
//         for (int i = 1; i <= n; i++) tmp[++tot] = a[i];
//         for (int i = 1; i <= m; i++) tmp[++tot] = b[i];
//         sort(tmp + 1, tmp + tot + 1);
//         tot = unique(tmp + 1, tmp + tot + 1) - tmp - 1;
//         for (int i = 1; i <= n; i++) cout << lower_bound(tmp + 1, tmp + tot + 1, a[i]) - tmp << " "; cout << "\n";
//         for (int i = 1; i <= m; i++) cout << lower_bound(tmp + 1, tmp + tot + 1, b[i]) - tmp << " "; cout << "\n";
//         }
        
        Check();
        for (int i = 1; i <= k1; i++) swap(a[CApos[i]], CAval[i]);
        for (int i = 1; i <= k2; i++) swap(b[CBpos[i]], CBval[i]);
    }
    return 0;
}