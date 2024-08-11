#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <utility>
#include <tuple>
#include <vector>

#define wzc(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout)

using u32 = uint32_t;
using u64 = uint64_t;

const size_t N = 100008;
const int T = 0, F = 1, U = 2;

int f[N * 2], x[N];

inline void init(int n)
{
    for (int i = 0; i <= 2 * n + 3; i++)
        f[i] = i;
    for (int i = 1; i <= n; i++)
        x[i] = 2 * i + 2;
}

inline int rep(int u)
{
    if (u == f[u]) return u;
    return f[u] = rep(f[u]);
}

inline void merge(int u, int v)
{
    u = rep(u), v = rep(v);
    f[u] = v;
}

int main()
{
    wzc("tribool");
    int _, q; scanf("%d %d", &_, &q);
    while (q--)
    {
        int n, m; scanf("%d %d", &n, &m);
        init(n);

        while (m--)
        {
            char c; int i, j; scanf(" %c %d", &c, &i);
            if (c == 'T')
                x[i] = T;
            else if (c == 'F')
                x[i] = F;
            else if (c == 'U')
                x[i] = U;
            else
            {
                scanf("%d", &j);
                if (c == '+')
                    x[i] = x[j];
                else if (c == '-')
                    x[i] = (x[j] == U) ? U : (x[j] ^ 1);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            merge(2 * i + 2, x[i]);
            merge(2 * i + 3, (x[i] == U) ? U : (x[i] ^ 1));
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            int xi = rep(2 * i + 2);
            if (xi == rep(U) || xi == rep(2 * i + 3))
                cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}