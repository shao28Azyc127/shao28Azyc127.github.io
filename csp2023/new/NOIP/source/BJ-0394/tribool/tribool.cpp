#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100100;
int n, m;
int tp[MAXN << 1], a[MAXN << 1], fa[MAXN << 1], val[MAXN << 1];
int findff(int x) { return (fa[x] == x) ? x : (fa[x] = findff(fa[x])); }
void work(void) {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) tp[i] = 2, a[i] = i;
    while(m--) {
        char ch; int x, y;
        scanf(" %c %d", &ch, &x);
        if(ch == 'U') tp[x] = a[x] = 0;
        else if(ch == 'T') tp[x] = 1, a[x] = 0;
        else if(ch == 'F') tp[x] = -1, a[x] = 0;
        else {
            scanf("%d", &y);
            int op = (ch == '+') ? 1 : -1;
            tp[x] = tp[y] * op;
            a[x] = a[y];
        }
    }
    for(int i = 1; i <= (n << 1); i++) fa[i] = i, val[i] = 3;
    for(int x = 1; x <= n; x++) {
        if(!a[x]) continue;
        int fu = findff(x), fv = findff(a[x]);
        int ifu = findff(n + x), ifv = findff(n + a[x]);
        if(tp[x] == 2) {
            int fu = findff(x), fv = findff(a[x]);
            if(fu != fv) fa[fu] = fv;
            int ifu = findff(n + x), ifv = findff(n + a[x]);
            if(ifu != ifv) fa[ifu] = ifv;
        }else {
            int ifu = findff(n + x), fv = findff(a[x]);
            if(ifu != fv) fa[ifu] = fv;
            int fu = findff(x), ifv = findff(n + a[x]);
            if(ifv != fu) fa[fu] = ifv;
        }
    }
    for(int x = 1; x <= n; x++) {
        if(a[x]) continue;
        val[findff(x)] = tp[x];
        val[findff(x + n)] = -tp[x];
    }
    for(int x = 1; x <= (n << 1); x++) {
        if(fa[x] != x) continue;
        if(val[x] != 3) continue;
        int xn = (x > n) ? (x - n) : (x + n);
        if(x == findff(xn)) val[x] = 0;
        else val[x] = 1, val[findff(xn)] = -1;
    }
    for(int x = 1; x <= (n << 1); x++) {
        if(fa[x] == x) continue;
        int xn = (x > n) ? (x - n) : (x + n);
        val[x] = val[findff(xn)];
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++)
        if(!val[i]) cnt++;
    printf("%d\n", cnt);
}
int main() {
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int C, T; scanf("%d%d", &C, &T);
    while(T--) work();
    return 0;
}
