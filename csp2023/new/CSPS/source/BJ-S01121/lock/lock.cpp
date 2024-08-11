#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, cnt, tong[N], a[10][10];
void check(int x) {
    int sum = 0;
    for (int i = 1; i <= 5; ++i) {
        sum = sum * 10 + a[x][i];
    }
    ++tong[sum];
}
int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    int t;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 5; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 5; ++j) {
            int x = a[i][j];
            for (int k = 1; k <= 9; ++k) {
                a[i][j] = (a[i][j] + k) % 10;
                check(i);
                a[i][j] = x;
            }
        }
        for (int j = 1; j < 5; ++j) {
            int xa = a[i][j], xb = a[i][j + 1];
            for (int k = 1; k <= 9; ++k) {
                a[i][j] = (a[i][j] + k) % 10;
                a[i][j + 1] = (a[i][j + 1] + k) % 10;
                check(i);
                a[i][j] = xa;
                a[i][j + 1] = xb;
            }
        }
    }
    for (int i = 0; i <= 99999; ++i) 
        if (tong[i] == n) 
            ++cnt;
    printf("%d", cnt);
    return 0;
}
