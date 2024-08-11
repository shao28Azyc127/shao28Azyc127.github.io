#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
int a[9][6], u[6];

bool check() {
    int d, f;
    for (int i = 1; i <= n; i++) {
        d = 0, f = 0;
        for (int j = 1; j <= 5; j++) {
            if (a[i][j] != u[j]) {
                if (f == 0)
                    d = j, f++;
                if (f == 1 && d+1 == j && a[i][j]-a[i][d] == u[j]-u[d])
                    d = j, f++;
                else
                    return 0;
            }
        }
        if (f == 0)
            return 0;
    }
    return 1;
}

void dfs(int cnt) {
    if (cnt == 5) {
        if (check())
            ans++;
        return;
    }
    for (int i = 0; i <= 9; i++) {
        u[cnt + 1] = i;
        dfs(cnt + 1);
    }
}


int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 5; j++)
            scanf("%d", &a[i][j]);
    if (n == 1)
        printf("81");
    else {
        dfs(0);
        printf("%d", ans);
    }

    return 0;
}
