// CPU: Intel(R) Core(TM) i5-7500 CPU @ 3.40GHz # too slow...
// Memory: 8GB
#include <bits/stdc++.h>

#define getchar getchar_unlocked
#define putchar putchar_unlocked

using namespace std;

template<typename T = int>
T read() {
    T x = 0, f = 1;
    char ch = 0;
    while (!isdigit(ch)) {
        ch = getchar();
        if (ch == '-') f = -1;
    }
    do {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    while (isdigit(ch));
    return x * f;
}

const int N = 100005;
int64_t n, ans, a[N], b[N], c[N];

int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    n = read<int64_t>();
    for (int i = 1; i <= n; i++) {
        a[i] = read<int64_t>(), b[i] = read<int64_t>(), c[i] = read<int64_t>();
        ans = max(ans, a[i] / b[i] + i - 1);
    }
    printf("%ld\n", ans);
    fflush(stdout);
    return 0;
}