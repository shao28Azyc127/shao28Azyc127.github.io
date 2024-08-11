#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <utility>
#include <tuple>
#include <vector>

#define wzc(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout)

using u32 = uint32_t;
using u64 = uint64_t;

const size_t N = 2048;

constexpr inline int log2(int x) { return 31 ^ __builtin_clz(x); }

int x[N], y[N];
int mx[N][log2(N)], my[N][log2(N)];
bool dp[N][N];
int l[N][N], r[N][N];

bool solve(int n, int m)
{
    if (x[1] == y[1]) return false;
    bool b = x[1] < y[1];
    dp[0][0] = true;
    l[0][0] = r[0][0] = 0;

    for (int i = 1; i <= n; i++)
        dp[i][0] = false, l[i][0] = 0, r[i][0] = -100;
    for (int i = 1; i <= m; i++)
        dp[0][i] = false, l[0][i] = -100, r[0][i] = 0;

    for (int i = 1; i <= n; i++)
        mx[i][0] = x[i];
    for (int j = 1; j <= log2(n); j++)
        for (int i = (1 << j); i <= n; i++)
            mx[i][j] = b ? std::max(mx[i][j - 1], mx[i - (1 << (j - 1))][j - 1]) : std::min(mx[i][j - 1], mx[i - (1 << (j - 1))][j - 1]);
    for (int i = 1; i <= m; i++)
        my[i][0] = y[i];
    for (int j = 1; j <= log2(m); j++)
        for (int i = (1 << j); i <= m; i++)
            my[i][j] = b ? std::min(my[i][j - 1], my[i - (1 << (j - 1))][j - 1]) : std::max(my[i][j - 1], my[i - (1 << (j - 1))][j - 1]);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int i_ = l[i - 1][j - 1], j_ = r[i - 1][j - 1];
            int l1 = log2(i - i_), l2 = log2(j - j_);
            if (b)
                dp[i][j] = i_ >= 0 && std::max(mx[i_ + (1 << l1)][l1], mx[i][l1]) < y[j]
                        || j_ >= 0 && x[i] < std::min(my[j_ + (1 << l2)][l2], my[j][l2]);
            else
                dp[i][j] = i_ >= 0 && std::min(mx[i_ + (1 << l1)][l1], mx[i][l1]) > y[j]
                        || j_ >= 0 && x[i] > std::max(my[j_ + (1 << l2)][l2], my[j][l2]);
            l[i][j] = dp[i][j] ? i : l[i - 1][j];
            r[i][j] = dp[i][j] ? j : r[i][j - 1];
        }

    return dp[n][m];
}

int main()
{
    wzc("expand");
    int _, n, m, q; scanf("%d %d %d %d", &_, &n, &m, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &x[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d", &y[i]);
    printf("%d", (int) solve(n, m));

    std::vector<std::pair<int&, int>> hist;
    for (int i = 0; i < q; i++)
    {
        int kx, ky, p, v; scanf("%d %d", &kx, &ky);
        for (int i = 0; i < kx; i++)
            scanf("%d %d", &p, &v), hist.emplace_back(x[p], x[p]), x[p] = v;
        for (int i = 0; i < ky; i++)
            scanf("%d %d", &p, &v), hist.emplace_back(y[p], y[p]), y[p] = v;
        printf("%d", (int) solve(n, m));
        for (auto [to, old] : hist)
            to = old;
        hist.clear();
    }
    return 0;
}