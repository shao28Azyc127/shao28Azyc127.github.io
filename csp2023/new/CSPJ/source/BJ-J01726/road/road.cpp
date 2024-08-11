#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n, d;
int a[N], b[N], c[N][3], ans;

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    scanf("%d %d", &n, &d);

    for (int i = 1; i < n; i++) {
        scanf("%d", a + i);
    }

    int ma = 11451419, cnt = 0, mdx = 0, cc = 0, mi = -114514, mxi;

    for (int i = 1; i <= n; i++) {
        scanf("%d", b + i);
        //d[i] = b[i];
        if (b[i] > mi) {
            mi = b[i];
            mxi = i;
        }

        if (b[i] < ma) {
            ma = b[i];
            c[cc][1] = mdx;
            c[cc][2] = cnt;
            cc++;
            mdx = i;
            cnt = 1;
        } else cnt++;
    }

    //sort(d + 1, d + n + 1);
    //reverse(d + 1, d + n + 1);

    c[cc][1] = mdx;
    c[cc][2] = cnt;
    int tmp = 1, ry = 0;
    for (int i = 1; i <= cc; i++) {
        int cnt = 0, rtmp = tmp, tta;
        for (;tmp < rtmp + c[i][2]; tmp++) {
            cnt += a[tmp];
        }
        cnt -= ry;
        ry = 0;
        tta = (cnt % d == 0 ? cnt / d: (cnt / d) + 1);
        ry += tta * d - cnt;
        ans += b[c[i][1]] * tta;
        //if (ry / d >= 1) {
        //    ans -= b[c[i + 1][1]] * (ry / d);
        //    ry -= (ry / d) * d;
        //}
        //printf("%d %d\n", ry, tta);
    }

    printf("%d", ans);

    return 0;
}
