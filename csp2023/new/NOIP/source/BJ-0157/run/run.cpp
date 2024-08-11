#include <cstdio>
#include <algorithm>
using namespace std;

int T, n, m, k, d;

struct Challenge {
    int x, y;
    long long v;
} ch[105];

bool run[23];
int IAR[23];
long long ans;

void dfs(int day) {
    if (day > n) {
        long long tans = 0;
        for (int i = 1; i <= n; i++)
            tans -= run[i] * d;
        for (int i = 1; i <= m; i++)
            if (IAR[ch[i].x] >= ch[i].y)
                tans += ch[i].v;
        ans = max(ans, tans);
        return;
    }

    if (IAR[day - 1] < k) {
        IAR[day] = IAR[day - 1] + 1, run[day] = true;
        dfs(day + 1);
    }
    IAR[day] = 0, run[day] = false;
    dfs(day + 1);
}

int main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    scanf("%*d%d", &T);
    while (T--) {
        scanf("%d%d%d%d", &n, &m, &k, &d);
        for (int i = 1; i <= m; i++)
            scanf("%d%d%lld", &ch[i].x, &ch[i].y, &ch[i].v);
        ans = 0;
        dfs(1);
        printf("%lld\n", ans);
    }
    return 0;
}
