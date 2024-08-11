#include <bits/stdc++.h>
using namespace std;
int n, ans1, ans2;
int x;
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    scanf("%d", &n);

    x = n;
    while (x > 0) {
        if (x % 3 != 0) x--;
        x -= ceil(x / 3);
        ans1++;
        //printf("%d", x);
    }
    x = n;
    while (x % 3 != 1) {
        if (x % 3 != 0) x--;
        x -= ceil(x / 3);
        ans2++;
    }
    ans2++;
    printf("%d %d", ans1, ans2);
    return 0;
}
