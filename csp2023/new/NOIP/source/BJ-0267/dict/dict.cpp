#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3005;

int n, m;
int pos1, pos2, cnt[26];
char s[MAXN][MAXN], t[MAXN][MAXN];
char fr[MAXN], sc[MAXN];

inline bool compare(char *a, char *b) {
    for (int i = 1; i <= m; i++) {
        if (a[i] != b[i])
            return a[i] < b[i];
    }
    return false;
}

int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= m; j++) {
            cnt[s[i][j] - 'a']++;
        }
        int q = 0;
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < cnt[j]; k++)
                s[i][++q] = j + 'a';
        }
        q = 0;
        for (int j = 25; j >= 0; j--) {
            for (int k = 0; k < cnt[j]; k++)
                t[i][++q] = j + 'a';
        }
        for (int j = 0; j < 26; j++)
            cnt[j] = 0;
    }
    if (n == 1) {
        printf("1\n");
        return 0;
    }
    for (int i = 1; i <= m; i++) {
        fr[i] = sc[i] = 'z';
    }
    for (int i = 1; i <= n; i++) {
        if (compare(t[i], fr)) {
            for (int j = 1; j <= m; j++) {
                sc[j] = fr[j];
            }
            for (int j = 1; j <= m; j++) {
                fr[j] = t[i][j];
            }
            pos1 = i;
        } else if (compare(t[i], sc)) {
            for (int j = 1; j <= m; j++) {
                sc[j] = t[i][j];
            }
            pos2 = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i != pos1) {
            if (compare(s[i], fr))
                putchar('1');
            else
                putchar('0');
        } else {
            if (compare(s[i], sc))
                putchar('1');
            else
                putchar('0');
        }
    }
}