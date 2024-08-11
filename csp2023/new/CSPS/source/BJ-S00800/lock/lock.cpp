#include <bits/stdc++.h>
const int MAXN = 10;
int n, a[MAXN][MAXN], now[MAXN], ans;

bool equal(int a[], int b[]) {
    for(int i = 1; i <= 5; ++i)
        if(a[i] != b[i])
            return 0;
    return 1;
}

bool check(int a[], int b[]) {
    int t[10];
    for(int i = 1; i <= 5; ++i) {
        for(int j = 1; j <= 5; ++j)
            t[j] = a[j];
        for(int j = 1; j <= 9; ++j) {
            ++t[i], t[i] %= 10;
            if(equal(t, b))
                return 1;
        }
    }
    for(int i = 1; i < 5; ++i) {
        for(int j = 1; j <= 5; ++j)
            t[j] = a[j];
        for(int j = 1; j <= 9; ++j) {
            ++t[i], ++t[i + 1];
            t[i] %= 10, t[i + 1] %= 10;
            if(equal(t, b))
                return 1;
        }
    }
    return 0;
}

bool check(int b[]) {
    for(int i = 1; i <= n; ++i)
        if(!check(a[i], b))
            return 0;
    return 1;
}

void DFS(int x) {
    if(x > 5) {
        ans += check(now);
        return ;
    }
    for(int i = 0; i <= 9; ++i) {
        now[x] = i;
        DFS(x + 1);
    }
}

int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    std::cin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= 5; ++j)
            std::cin >> a[i][j];
    DFS(1);
    std::cout << ans;
    return 0;
}