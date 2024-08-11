#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int n;
int a[10][6];
int st[6], t[6], cnt;

int dfs(int d) {
    if(d == 6) {
        for(int i = 1;i <= n;i++) {
            cnt = 0;
            for(int j = 1;j <= 5;j++) {
                if(a[i][j] != st[j]) {
                    t[++cnt] = j;
                }
            }
            if(cnt == 0 || cnt > 2) return 0;
            if(cnt == 1) continue;
            if(abs(t[1] - t[2]) == 1
            && (a[i][t[1]] - st[t[1]] + 10) % 10
            == (a[i][t[2]] - st[t[2]] + 10) % 10) continue;
            return 0;
        }
        return 1;
    }
    int s = 0;
    for(int i = 0;i <= 9;i++) {
        st[d] = i;
        s += dfs(d + 1);
    }
    return s;
}

int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= 5;j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("%d", dfs(1));
    return 0;
}
