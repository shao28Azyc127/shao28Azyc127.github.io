#include <bits/stdc++.h>
using namespace std;
int n, a[10][10], ans;
map<int, int> mp;
void get(int h) {
    int tmp = 0;
    for(int i = 1; i <= 5; i++) {
        tmp *= 10, tmp += a[h][i];
    }
    if(h == n) {
        for(int i = 1; i <= 5; i++) {
            for(int j = 0; j <= 9; j++) {
                if(j == a[h][i]) {
                    continue;
                }
                int ttmp = tmp + (j - a[h][i]) * pow(10, 5 - i);
                mp[ttmp]++;
                if(mp[ttmp] >= n) ans++;
            }
        }
        for(int i = 1; i < 5; i++) {
            for(int j = 1; j <= 9; j++) {
                int tt1 = (a[h][i] + j) % 10, tt2 = (a[h][i + 1] + j) % 10;
                int ttmp = tmp + (tt1 - a[h][i]) * pow(10, 5 - i) + (tt2 - a[h][i + 1]) * pow(10, 4 - i);
                mp[ttmp]++;
                if(mp[ttmp] >= n) ans++;
            }
        }
    } else {
        for(int i = 1; i <= 5; i++) {
            for(int j = 0; j <= 9; j++) {
                if(j == a[h][i]) {
                    continue;
                }
                int ttmp = tmp + (j - a[h][i]) * pow(10, 5 - i);
                mp[ttmp]++;
            }
        }
        for(int i = 1; i < 5; i++) {
            for(int j = 1; j <= 9; j++) {
                int tt1 = (a[h][i] + j) % 10, tt2 = (a[h][i + 1] + j) % 10;
                int ttmp = tmp + (tt1 - a[h][i]) * pow(10, 5 - i) + (tt2 - a[h][i + 1]) * pow(10, 4 - i);
                mp[ttmp]++;
            }
        }
    }
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
    for(int i = 1; i <= n; i++) {
        get(i);
    }
    printf("%d", ans);
    return 0;
}
