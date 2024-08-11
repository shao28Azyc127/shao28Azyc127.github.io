#include <bits/stdc++.h>
using namespace std;
int n, m;
string s[3005];
int a[3005][35], sm[3005][35];
bool f1, f2;
int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            a[i][s[i][j] - 'a' + 1]++;

        }
        for (int j = 1; j <= 26; j++) {
            sm[i][j] = sm[i][j - 1] + a[i][j];
        }
    }
    /*for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 26; j++) {
            printf("%d", sm[i][j]);
        }
        printf("\n");
    }*/

    for (int i = 1; i <= n; i++) {
        f2 = 0;
        for (int j = 1; j <= n; j++) {
            if (j == i) continue;
            f1 = 0;
            for (int k = 1; k <= 26; k++) {
                if (sm[i][k] > 0 && sm[j][k] < m) {
                    f1 = 1;
                    break;
                }
            }
            if (f1 == 0) {
                f2 = 1;
                break;
            }
        }
        if (f2 == 1) printf("0");
        else printf("1");
    }

    return 0;
}
