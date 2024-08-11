#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

typedef long long l;
l n, cnt = 0, x = 0;

int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    scanf("%lld", &n);
    while (n != 0) {
        if (n % 3 == 1 && x == 0) x = cnt + 1;
        n = n - (n + 2) / 3;
        cnt++;
    }
    printf("%lld %lld", cnt, x);
    return 0;
}
