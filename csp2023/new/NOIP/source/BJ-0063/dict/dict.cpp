#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
const int N = 3005;
char s[N];
int n, m, lst[N], fst[N];
signed main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    scanf("%d%d", &n, &m);
    rep(i, 1, n) {
        scanf("%s", s + 1);
        fst[i] = 0x3f3f3f3f;
        lst[i] = -1;
        rep(j, 1, m) {
            // ++bok[i][s[j] - 'a'];
            lst[i] = max(lst[i], s[j] - 'a');
            fst[i] = min(fst[i], s[j] - 'a');
        }
    }
    rep(i, 1, n) {
        // bok[i], bok[j]
        rep(j, 1, n) if (j != i) {
            if (fst[i] >= lst[j]) goto fail;
            // else if (fst[i] == lst[j]) {
                // if (bok[i][fst[i]] <= bok[j][lst[j]]) goto fail;
            // }
        }
        putchar('1');
        continue;
        fail:
        putchar('0');
    }
    return 0;
}