#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0, ans1 = 1, ans2, num = 1, num2;
bool a[1000000005];

int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    scanf("%d", &n);
    while (cnt < n) {
        if (a[num] == 0) {
            if (num2 == 0) {
                a[num] = 1;
                if (num == n) ans2 = ans1;
                cnt++;
            }
            num2 = (num2 + 1) % 3;
        }
        if (cnt == n) break;
        num++;
        if (num > n) num = 1, num2 = 0, ans1++;
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}
