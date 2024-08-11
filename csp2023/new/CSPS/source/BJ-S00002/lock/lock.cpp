#include <bits/stdc++.h>
using namespace std;
int a[10][6];
int b[6];
int main() {
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    int ans1 = 0;
    int ans2 = 0;
    cin >> n;
    if(n == 1) {
        cout << 81;
        return 0;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 5; j++) {
            cin >> a[i][j];
        }
    }
    int cnt;
    for(int i = 1; i <= 5; i++) {
        for(int j = 0; j <= 9; j++) {
            if(j != a[1][i]) {
                for(int k = 1; k <= 5; k++) {
                    b[k] = a[1][i];
                }
                b[i] = j;
                for(int k = 2; k <= n; k++) {
                    cnt = 0;
                    for(int x = 1; x <= 5; x++) {
                        if(a[k][x] != b[x]) {
                            cnt++;
                            if(cnt > 1) {
                                break;
                            }
                        }
                    }
                    if(cnt != 1) {
                        ans1++;
                        break;
                    }
                }
                for(int k = 1; k <= 5; k++) {
                    b[k] = a[1][i];
                }
                if(j == 0) {
                    continue;
                }
                for(int k = 2; k <= n; k++) {
                    for(int x = 1; x <= 4; x++) {
                        for(int y = 1; y <= 9; y++) {
                            if((a[k][x] + y) % 10 == b[i] - j && (a[k][x + 1] + y) % 10 == b[i + 1] - j || (a[k][x] - y) % 10 == b[i] - j && (a[k][x + 1] - y) % 10 == b[i + 1] - j) {
                                ans2++;
                            }
                            if((a[k][x] + y) % 10 == (b[i] + j) && (a[k][x + 1] + y) % 10 == b[i + 1] + j || (a[k][x] - y) % 10 == b[i] + j && (a[k][x + 1] - y) % 10 == b[i + 1] + j) {
                                ans2++;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << 45 - ans1 + ans2;
    return 0;
}