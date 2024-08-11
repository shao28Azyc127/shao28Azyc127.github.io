#include <bits/stdc++.h>
using namespace std;
int n;
bool a[1005];
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    scanf("%d", &n);
    if (n <= 1000) {
        int t = n, l = 0, ans;
        while (t) {
            ++l;
            int cnt = 2, d = 0;
            for (int i = 1; i <= n; ++i) {
                if (!a[i]) ++cnt;
                if (cnt == 3) {
                    cnt = 0;
                    --t;
                    a[i] = true;
                    if (i == n) ans = l; 
                }
            }
        }
        printf("%d %d", l, ans);
    }
    else if (n <= 1e6) {
        int cnt = 0;
        while (n) {
            if (n % 3 == 0) n -= n / 3;
            else n -= n / 3 + 1;
            ++cnt;
        }
        printf("%d %d", cnt, 1);
    }
    return 0;
}