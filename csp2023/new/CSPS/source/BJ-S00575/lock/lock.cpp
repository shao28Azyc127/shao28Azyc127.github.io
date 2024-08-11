#include<bits/stdc++.h>
using namespace std;
const int maxn = 10;
const int maxm = 5e3 + 10;
const int n = 5;
int q, cnt=0, ans, res, a[maxn];
struct Node {
    int n;
    int num[maxn];
    int x;
    bool tp;
    bool operator== (Node & r) const {
        if (n != r.n && tp == r.tp) return false;
        if (x == r.x && tp == r.tp) return false;
        for (int i = 0; i < n; i++)
            if (num[i] != r.num[i] && tp == r.tp) return false;
        return true;
    }
} b[maxm];
int main () {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &q);
    while (q--) {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++) scanf("%d", a+i);
        ans = 81;
        for (int i = 0; i < n; i++) {
                int t = a[i];
            for (int j = 0; j < 9; j++) {
                t++;
                if (t > 9) t -= 10;
                b[cnt].n = n, b[cnt].x = i, b[cnt].tp = 0;
                for (int k = 0; k < n; k++) {
                    if (k == i) b[cnt].num[k] = t;
                    else b[cnt].num[k] = a[k];
                }
                cnt++;
            }
        }
        res += ans;
    }
    for (int i = 0; i < cnt; i++)
        for (int j = i+1; j < cnt; j++)
            if (b[i] == b[j]) res--;
    printf("%d\n", res);
    return 0;
}
