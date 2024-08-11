#include <stdio.h>
#define N 500005
int n, m, x[N], y[N], nn, mm, xx[N], yy[N];
void cp() {
    nn = n; for (int i = 1; i <= nn; i++) xx[i] = x[i];
    mm = m; for (int i = 1; i <= mm; i++) yy[i] = y[i];
}
int work() {
    if (xx[1] < yy[1]) {
        for (int i = 1; i <= nn || i <= mm; i++)
            xx[i] ^= yy[i] ^= xx[i] ^= yy[i];
        nn ^= mm ^= nn ^= mm;
    }
    int a = 1, b = 1;
    while (a <= nn && b <= mm) {
        //only 30 min left, i'm still stuck on this stupid problem 3
        //**panicking**
        //i'm a 10th-grade student, and this is my 1st year at NOIP
        //despite the fact that i'm currently ill
        //and that i have already finished problem 1&2
        //but i still want to earn more scores to reach a relatively high total score
        //so that everyone around will be proud of me
        //and more importantly
        //i can be proud of myself
        //i know it's stupid
        //the whole idea of engaging in oi is stupid
        //but what do i have to show for myself then
        //this is my last chance
        //and i will not throw it away
        //eventually i will delete this if i ever solved problem 3
        //but if i can't
        //then i will submit this with my unfinished code
        //to commemorate the path i have determined to take
        //even though it might lead to nowhere

        while (b <= mm && xx[a] > yy[b]) b++; a++;//problem part
    }
    if (a <= nn && b > mm) {
        for (; a <= nn; a++) if (xx[a] < yy[mm]) return 0;
        return 1;
    }
    if (a > nn && b <= mm) {
        for (; b <= mm; b++) if (xx[nn] < yy[b]) return 0;
        return 1;
    }
    return 1;
}
int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    int c, q; scanf("%d%d%d%d", &c, &n, &m, &q);
    for (int i = 1; i <= n; i++) scanf("%d", x + i);
    for (int i = 1; i <= m; i++) scanf("%d", y + i);
    cp(); putchar(work() ^ '0'); while (q--) {
        int kx, ky; scanf("%d%d", &kx, &ky);
        for (int p, v; kx--; ) scanf("%d%d", &p, &v), xx[p] = v;
        for (int p, v; ky--; ) scanf("%d%d", &p, &v), yy[p] = v;
        putchar(work() ^ '0'); cp();
    }
    return 0;
}