#include <bits/stdc++.h>
using namespace std;
int n, cnt, ans;
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    scanf("%d", &n);
    while (n) {
        cnt++;
        if (n % 3 == 1 && !ans) ans = cnt;
        if (n % 3) n = n - (n / 3 + 1);
        else n = n - n / 3;
    }
    printf("%d %d", cnt, ans);
    return 0;
}