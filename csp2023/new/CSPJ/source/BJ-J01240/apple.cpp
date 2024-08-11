#include <bits/stdc++.h>
using namespace std;
int n;
int ans, sum;
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    scanf("%d", &n);
    while (n) {
        sum ++;
        if (n % 3 == 1 && ans == 0)  ans = sum;
        int a = n / 3 + 1;
        if (n % 3 == 0)  a--;
        n -= a;
    }
    printf("%d %d", sum, ans);
    return 0;
}