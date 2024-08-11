#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int T, n, m;

struct tribool {
    char c; // 0, 1, -1

    void neg() {
        if (c != -1)
            c = 1 - c;
    }

    tribool()
      { c = 0; }
    tribool(int v)
      { c = v; }
} x[15], xr[15];
const tribool TRU(1), FLS(0), UKN(-1);

struct cmd {
    char t;
    int p1, p2;

    void read() {
        scanf(" %c%d", &t, &p1);
        if (t == '+' || t == '-')
            scanf("%d", &p2);
    }

    void exec() {
             if (t == 'T')
            x[p1] = TRU;
        else if (t == 'F')
            x[p1] = FLS;
        else if (t == 'U')
            x[p1] = UKN;
        else if (t == '+')
            x[p1] = x[p2];
        else if (t == '-') {
            x[p1] = x[p2];
            x[p1].neg();
        }
    }
} c[15];

int ans;
tribool xb[15];

void dfs(int step) {
    if (step > n) {
        memcpy(x, xr, sizeof x);
        for (int i = 1; i <= m; i++)
            c[i].exec();
        for (int i = 1; i <= n; i++)
            if (x[i].c != xr[i].c)
                return;
        int tans = 0;
        for (int i = 1; i <= n; i++)
            tans += (xr[i].c == -1);
        if (ans > tans) {
            ans = tans;
            memcpy(xb, xr, sizeof xb);
        }
        return;
    }

    xr[step] = TRU; dfs(step + 1);
    xr[step] = FLS; dfs(step + 1);
    xr[step] = UKN; dfs(step + 1);
}

int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    scanf("%*d%d", &T);
    while (T--) {
        ans = 2e9;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
            c[i].read();
        dfs(1);
        printf("%d\n", ans);
    }
    return 0;
}
