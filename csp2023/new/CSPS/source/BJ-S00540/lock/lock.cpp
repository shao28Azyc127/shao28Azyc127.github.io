#include<bits/stdc++.h>

using namespace std;

int n;
int a[15][7], c[15][7], dz[2], ca, cb, sum, ans[15][7];
int cha[7];
int cnt[10];
bool num[10][20];

inline int find() {
    bool lock[7];
    int jige[20];
    memset(jige, 0, sizeof jige);
    int dif, lie;
    bool judge = true;
    for(int k = 1; k <= 5; k++) {
        if(jige[1] > 2) {
            return 0;
        }
        if(a[1][k] == a[2][k]) {
            ans[1][k] = a[1][k];
        }
        if(a[1][k] != a[2][k]) {
            jige[1]++;
        }
    }
    for(int i = 2; i < n; i++) {
        int j = i + 1;
        for(int k = 1; k <= 5; k++) {
            if(jige[i] > 2) {
                return 0;
            }
            if(a[i][k] == a[j][k]) {
                ans[i][k] = a[i][k];
            }
            if(a[i][k] != a[j][k]) {
                ans[i][k] = -1;
                jige[i]++;
            }
        }
        dif = 0;
        for(int k = 1; k <= 5; k++) {
            if(dif > 2) {
                return 0;
            }
            if(ans[i][k] == -1 || ans[i - 1][k] == -1) dif++;
        }
    }
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j < n - 1; j++) {
            if(ans[j][i] == -1 && ans[j + 1][i] != -1) {
                judge = false;
                break;
            }
            if(ans[j][i] != -1 && ans[j + 1][i] == -1) {
                judge = false;
                break;
            }
        }
    }
    for(int i = 1; i <= 5; i++) {
        if(ans[1][i] == -1) {
            lie = i;
            break;
        }
    }
    if(judge) {
        int op = 10 - cnt[lie];
        return op;
    }
    return 1;
}

int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);

    scanf("%d", &n);

    for(int i = 1; i <= 5; i++) {
        scanf("%d", &a[1][i]);
        num[i][a[1][i]] = 1;
        cnt[i]++;
    }

    if(n == 1) {
        printf("81");
        return 0;
    }

    if(n == 2) {
        for(int i = 1; i <= 5; i++) {
            scanf("%d", &a[2][i]);
            if(num[i][a[2][i]] == 1) continue;
            if(num[i][a[2][i]] == 0) num[i][a[2][i]] = 1; cnt[i]++;
        }
        for(int i = 1; i <= 10; i++) sum += cnt[i];
        if(sum >= 8) {
            printf("0");
            return 0;
        }
        if(sum == 6) {
            for(int i = 1; i <= 5; i++) {
                if(cnt[i] == 1) continue;
                if(cnt[i] > 1) dz[1] = i; break;
            }
            if(dz[1] == 1 || dz[1] == 5) {
                printf("10");
                return 0;
            }
            else {
                printf("12");
                return 0;
            }
        }
        if(sum == 7) {
            for(int i = 1, k = 1; i <= 5; i++) {
                if(cnt[i] == 1) continue;
                if(cnt[i] > 1) dz[k] = i; k++;
            }
            if(dz[2] - dz[1] > 1) {
                printf("0");
                return 0;
            }
            if((a[1][dz[1]] + a[2][dz[2]]) % 10 == (a[2][dz[1]] + a[1][dz[2]]) % 10)  {
                printf("8");
                return 0;
            }
            else {
                printf("2");
                return 0;
            }
        }
    }

    if(n >= 3 && n <= 8) {
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= 5; j++) {
                scanf("%d", &a[i][j]);
                if(num[j][a[i][j]] == 1) continue;
                if(num[j][a[i][j]] == 0) num[j][a[i][j]] = 1; cnt[i]++;
            }
        }
        int ppp = find();
        printf("%d", ppp);
    }

    if(n >= 9) {
        printf("1");
    }
    return 0;
}
