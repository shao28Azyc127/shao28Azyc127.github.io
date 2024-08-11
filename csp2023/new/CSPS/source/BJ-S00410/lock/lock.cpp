#include <cstdio>
#include <iostream>
using namespace std;
int n;
int a[105][10];
bool vis[105];
int main () {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    if(n == 1){
        printf("81");
        return 0;
    }
    scanf("%d%d%d%d%d", &a[0][1], &a[0][2], &a[0][3], &a[0][4], &a[0][5]);
    int ans = 0;
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= 9; j++) {
            ans++;
            vis[ans] = 1;
            for(int k = 1; k <= 5; k++) {
                if(k == i) a[ans][k] = (a[0][i] + j) % 10;
                else a[ans][k] = a[0][k];
            }
        }
    }
    for(int i = 1; i <= 4; i++) {
        for(int j = 1; j <= 9; j++) {
            ans++;
            vis[ans] = 1;
            for(int k = 1; k <= 5; k++) {
                if(k == i) {
                    a[ans][k] = (a[0][k] + j) % 10;
                    k++;
                    a[ans][k] = (a[0][k] + j) % 10;
                }else a[ans][k] = a[0][k];
            }
        }
    }
    for(int i = 2; i <= n; i++) {
        int b[6];
        scanf("%d%d%d%d%d", &b[1], &b[2], &b[3], &b[4], &b[5]);
        for(int j = 1; j <= 81; j++) {
            if(vis[j] == 0) continue;
            int cnt = 0, c[6];
            for(int k = 1; k <= 5; k++) {
                if(a[j][k] != b[k]) {
                    cnt++;
                    c[cnt] = k;
                }
            }
            if(cnt == 0){
                vis[j] = 0;
                ans--;
                continue;
            }
            if(cnt == 1){
                continue;
            }
            if(cnt == 2){
                if(c[2] != c[1] + 1){
                    vis[j] = 0;
                    ans--;
                    continue;
                }
                if(b[c[1]] - a[j][c[1]] == b[c[2]] - a[j][c[2]])
                    continue;
                else{
                    vis[j] = 0;
                    ans--;
                    continue;
                }
            }
            if(cnt >= 3){
                vis[j] = 0;
                ans--;
                continue;
            }
        }
    }
    printf("%d", ans);
    return 0;
}