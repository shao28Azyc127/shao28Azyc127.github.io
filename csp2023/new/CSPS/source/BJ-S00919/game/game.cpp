#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e6 + 10;
int n, t[N][26], ans[N], f[N];
ll ret;
char s[N];

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d%s", &n, s + 1);
    for (int i=1; i<=n; ++i) {
        int c = s[i] - 'a';
        if (i > 1 && s[i - 1] == s[i]) f[i] = i - 1;
        else f[i] = t[f[i - 1]][c];
        if (f[i]) ans[i] = 1 + ans[f[i] - 1];
        ret += ans[i];
        for (int j=0; j<26; ++j) {
            if (j == s[f[i] - 1] - 'a') t[f[i]][j] = f[i] - 1;
            else t[f[i]][j] = t[f[f[i] - 1]][j];
        }
    }
    //for (int i=1; i<=n; ++i) printf("%d ", f[i]); putchar(10);
    //for (int i=1; i<=n; ++i) printf("%d ", ans[i]); putchar(10);
    printf("%lld\n", ret);
    return 0;
}