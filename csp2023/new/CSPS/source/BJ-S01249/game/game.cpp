#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define nrep(i, a, b) for(int i = (a); i >= (b); --i)
#define put(x) printf("%d ", x)
#define putl(x) printf("%lld ", x)
#define endl() putchar('\n')
using namespace std;

typedef long long ll;
inline int read() {
    int x = 0, k = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') k = -1; c = getchar(); }
    while(c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c & 15), c = getchar();
    return x * k;
}

const int N = 2e6 + 10;

int lst[N], f[N];
char c[N];
ll sum;

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    int n = read();
    scanf("%s", c + 1);
    // rep(i, 1, n) putchar(c[i]);
    rep(i, 1, n) {
        if(c[i] == c[i - 1]) lst[i] = i - 2;
        else {
            lst[i] = lst[i - 1];
            while(lst[i] && c[lst[i]] != c[i]) lst[i] = lst[lst[i]];
            lst[i] --;
        }
        if(lst[i] >= 0) f[i] = f[lst[i]] + 1;
        sum += f[i];
    }
    // rep(i, 1, n) putchar(c[i]), putchar(' '); endl();
    // rep(i, 1, n) put(lst[i]); endl();
    // rep(i, 1, n) put(f[i]); endl();
    putl(sum);
    return 0;
}
