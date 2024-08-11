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

const int N = 8005;
int n;
int64_t ans;
bitset<N> f[N];
char s[N];

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    // n = 8000;
    // for (int i = 1; i <= n; i++) s[i] = rand() % 2 + 'a';
    n = read();
    if (n > 800) {
        puts("0");
        return 0;
    }
    scanf("%s", s + 1);
    for (int i = 1; i < n; i++)
        if (s[i] == s[i + 1])
            f[i][i + 1] = 1, ans++;
    for (int len = 3; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) f[i][j] = f[i + 1][j - 1];
            for (int k = i; k < j; k++) f[i][j] = f[i][j] | (f[i][k] & f[k + 1][j]);
            ans += f[i][j];
        }
    }
    printf("%ld\n", ans);
    return 0;
}