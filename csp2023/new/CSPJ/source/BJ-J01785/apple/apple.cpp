#include<bits/stdc++.h>
using namespace std;
int n, ans1, ans2;
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    scanf("%d", &n);
    while(n) {
        ++ans1;
        if(!((n - 1) % 3) && !ans2) ans2 = ans1;
        n -= (n + 2) / 3;
    }
    printf("%d %d", ans1, ans2);
    return 0;
}