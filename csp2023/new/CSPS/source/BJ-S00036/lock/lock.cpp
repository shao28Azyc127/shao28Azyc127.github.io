#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
int n, a[10][10], ans[10];
LL tot;
bool check(int A, int b, int c, int d, int e) {
    ans[1] = A, ans[2] = b, ans[3] = c, ans[4] = d, ans[5] = e;
    for(int i = 1; i <= n; i++) {
        int havebug = 0, twobug = 0;
        for(int j = 1; j <= 5; j++) {
            if (ans[j] == a[i][j]) continue;
            else {
                if (twobug) return 0;
                if (!havebug) havebug = j;
                else {
                    if (havebug == j-1 && (a[i][j-1]-a[i][j]+10)%10 == (ans[j-1]-ans[j]+10)%10) twobug = 1;
                    else return 0;
                }
            }
        }
        if (!havebug) return 0;
    }
    return 1;
}
int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 5; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for(int a = 0; a <= 9; a++) {
        for(int b = 0; b <= 9; b++) {
            for(int c = 0; c <= 9; c++) {
                for(int d = 0; d <= 9; d++) {
                    for(int e = 0; e <= 9; e++) {
                        if (check(a, b, c, d, e)) tot++;
                    }
                }
            }
        }
    }
    printf("%lld\n", tot);
    return 0;
}
