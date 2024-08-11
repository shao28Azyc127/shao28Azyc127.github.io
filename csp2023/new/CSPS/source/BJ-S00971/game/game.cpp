#include <stdio.h>
#include <string.h>
char s[2000005];
bool cnt[26];
int a[67108870];//memory danger!!
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n; scanf("%d", &n);
    scanf("%s", s); long long ans = 0; a[0] = 1;
    for (int i = 0; i < n; i++) {
        cnt[s[i]-'a'] ^= 1;
        int x = 0;
        for (int i = 25; i >= 0; i--)
            x = x << 1 | cnt[i];
        ans += a[x]++;
    }
    printf("%lld\n", ans);
    return 0;
}