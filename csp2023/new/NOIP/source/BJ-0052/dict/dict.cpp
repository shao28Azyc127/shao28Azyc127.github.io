#include <cstdio>
#include <cstdint>
#include <cstring>
#include <algorithm>
#include <utility>
#include <tuple>
#include <vector>

#define wzc(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout)

using u32 = uint32_t;
using u64 = uint64_t;

const size_t N = 3001;

char s[N][N];

int main()
{
    wzc("dict");
    int n, m; scanf("%d %d", &n, &m);
    if (n == 1)
    {
        printf("1");
        return 0;
    }
    
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);
    for (int i = 0; i < n; i++)
    {
        std::sort(s[i], s[i] + m);
        std::reverse(s[i], s[i] + m);
    }

    std::vector<int> v(n);
    for (int i = 0; i < n; i++)
        v.push_back(i);
    std::sort(v.begin(), v.end(), [&](int i, int j) -> bool { return strcmp(s[i], s[j]) < 0; });
    for (int i = 0; i < n; i++)
    {
        int nxt = (i == v[0]) ? v[1] : v[0];
        std::reverse(s[i], s[i] + m);
        if (strcmp(s[i], s[nxt]) < 0)
            printf("1");
        else
            printf("0");
        std::reverse(s[i], s[i] + m);
    }
    return 0;
}