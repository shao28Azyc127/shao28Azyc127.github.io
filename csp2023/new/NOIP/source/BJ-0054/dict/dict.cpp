#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define nrep(i, a, b) for(int i = (a); i >= (b); --i)
#define endl() putchar('\n')
using namespace std;

typedef long long ll;
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') x = (x << 1) +(x << 3) + (ch ^ 48), ch = getchar();
    return x * f;
}
const int N = 3010;
char s[N][N];
int f[N], g[N];
int n, m;

bool cmp(const char *s1, const char *s2) {
    rep(i, 1, m) {
        if(s1[i] != s2[i]) return s1[i] < s2[i];
    }
    return 0;
}

//int fr[30], bk[30];
//vector<int> bk[]

//void solve(int i) {
//    if((f[i - 1] && g[i + 1]) == 0) return 0;
//    memset(fr, 0, sizeof fr);
//    memset(bk, 0, sizeof bk);
//    rep(j, 1, m) ++bk[s[i][j] - 'a'];
//    int used = 0;
//    rep(j, 1, m) {
//        int c1 = s[i - 1][j] - 'a', c2 = s[i + 1][j] - 'a';
//        if()
//    }
//}

namespace TRIE {
    const int N = 3010 * 3010 * 3;
    int a[N];
    int alloc;
    int nxt[N], head[N];
    char p[N];
    int find(int x, char c) {
        int *i;
        for(i = &head[x]; *i; i = &nxt[*i]) {
            if(p[*i] == c) return *i;
        }
        *i = ++alloc;
        p[*i] = c;
        return *i;
    }
    void insert(char *s, int k) {
        int x = 0;
        rep(i, 1, m) {
            x = find(x, s[i]);
            a[x] += k;
        }
    }
    bool check(char *s) {
        int x = 0;
        rep(i, 1, m) {
            int lsiz = 0;
            for(int j = head[x]; j; j = nxt[j]) {
                if(p[j] <= s[i]) lsiz += a[j];
            }
            if(lsiz) return 0;
            x = find(x, s[i]);
//            if(!x) break;
        }
        if(a[x]) return 0;
        return 1;
    }
}


int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);

    n = read(), m = read();
    rep(i, 1, n) scanf("%s", s[i] + 1);
//    f[0] = f[1] = 1;
//    rep(i, 2, n) if(cmp(s[i - 1], s[i])) f[i] |= f[i - 1];
//    g[n + 1] = g[n] = 1;
//    nrep(i, n - 1, 1) if(cmp(s[i], s[i + 1])) g[i] |= g[i + 1];
    rep(i, 1, n) sort(s[i] + 1, s[i] + m + 1, greater<>());
    rep(i, 1, n) TRIE ::insert(s[i], 1);
    rep(i, 1, n) {
        TRIE :: insert(s[i], -1);
        sort(s[i] + 1, s[i] + m + 1);
        int ans = TRIE :: check(s[i]);
        sort(s[i] + 1, s[i] + m + 1, greater<>());
        TRIE ::insert(s[i], 1);
        printf("%d", ans);
    }
    return 0;
}

