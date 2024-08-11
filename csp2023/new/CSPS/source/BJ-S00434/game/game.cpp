#include <cstdio>
#include <cstdint>
#include <utility>
#include <tuple>
#include <vector>
#include <stack>
#include <algorithm>
#include <random>
#include <chrono>

#define wzc(f) freopen(f".in", "r", stdin); freopen(f".out", "w", stdout)

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using i128 = __int128;
using u128 = unsigned i128;

const size_t N = 2e6 + 1;
const u64 p = (u64(1) << 61) - 1;

char s[N];
u64 hs[N];

u64 muladd(u64 x, u64 y, u64 z)
{
    u128 prod = u128(x) * y;
    u64 res = (prod & p) + (prod >> 61) + z;
    if (res >= p) res -= p;
    if (res >= p) res -= p;
    return res;
}

int main()
{
    wzc("game");
    int n; scanf("%d %s", &n, s);
    std::mt19937_64 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
    u64 base = rnd() >> 3;

    std::stack<std::pair<int, u64>> st;
    u64 h = 0;
    for (int i = 0; i < n; i++)
    {
        hs[i] = h;
        if (st.size() && s[st.top().first] == s[i])
        {
            h = st.top().second;
            st.pop();
        }
        else
        {
            st.emplace(i, h);
            h = muladd(h, base, s[i]);
        }
    }
    hs[n] = h;

    std::sort(hs, hs + n + 1);
    int i = 0;
    u64 ans = 0;
    while (i <= n)
    {
        int j = i;
        while (j <= n && hs[i] == hs[j]) j++;
        ans += u64(j - i) * u64(j - i - 1) >> 1;
        i = j;
    }
    printf("%llu\n", ans);
}