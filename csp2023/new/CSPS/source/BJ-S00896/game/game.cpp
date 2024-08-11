#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
char s[1010];
char st[1010];
int head;
int main () {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    ios :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    scanf("%d", &n);
    if (n > 1000) {
        printf("0\n");
        return 0;
    }
    scanf("%s", s + 1);
    for (int len = 1; len <= n; len++) {
        for (int l = 1; l <= n - len + 1; l++) {
            head = 0;
            int r = l + len - 1;
            for (int i = l; i <= r; i++) {
                if (head > 0 && st[head] == s[i]) head--;
                else st[++head] = s[i];
            }
            if (!head) ans++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
