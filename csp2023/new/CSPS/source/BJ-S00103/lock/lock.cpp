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

const int N = 100005, M = 10, K = 5;
int n, t[K];
bitset<N> b[M], sum;

int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    n = read();
    sum.set();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= K; j++) t[K - j] = read();
        for (int j = 0; j < K; j++) {
            for (int d = 1; d < M; d++) {
                #define calc() (t[0] + t[1] * 10 + t[2] * 100 + t[3] * 1000 + t[4] * 10000)
                #define mset(p, k) t[p] = (t[p] + k) % M
                #define mreset(p, k) t[p] = (t[p] - k + M) % M
                mset(j, d);
                b[i].set(calc());
                if (j != K - 1) {
                    mset(j + 1, d);
                    b[i].set(calc());
                    mreset(j + 1, d);
                }
                mreset(j, d);
            }
        }
        sum &= b[i];
    }
    printf("%ld\n", sum.count());
    fflush(stdout);
    return 0;
}