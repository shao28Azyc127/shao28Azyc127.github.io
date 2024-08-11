#include <bits/stdc++.h>
using namespace std;
int n,m,f0;
int a[1000001][6],s[1000001][6],cnt,ans,chek[500001];
int main() {
   freopen("lock.in", "r", stdin);
   freopen("lock.out", "w", stdout);
    cin >> n;
    m=0;
    while (m < n) {
        for (int i = 0; i < 5; i++) {
            cin >> a[m][i];
            f0 +=  a[m][i]*pow(10, 4-i);
        }
        m++;
    }
    for (int l = 0; l < n; l++) {
        for (int fudu = 1; fudu <= 9; fudu++) {
            for (int j = 0; j < 5;j++) {
                for (int k = 0; k < 5; k++) {
                    s[cnt + j][k] = a[l][k];
                    if (k == j) {
                        s[cnt + j][k] += fudu;
                        s[cnt + j][k]%= 10;
                    }
                }
            }
            cnt += 5;
        }
        for (int fudu = 1; fudu <= 9; fudu++) {
            for (int j = 0; j < 4;j++) {
                    for (int k = 0; k < 5; k++) {
                        s[cnt + j][k] = a[l][k];
                    }
                    for (int k = 0; k < 4; k++) {
                        if (k == j) {
                            s[cnt + j][k] += fudu;
                            s[cnt + j][k]%= 10;
                            s[cnt + j][k + 1] += fudu;
                            s[cnt + j][k + 1]%= 10;
                        }
                    }
                }
            cnt += 4;
        }
    }
    chek[f0] = 1;
    for (int j = 0;j < cnt; j++) {
        int flag = 0;
        for (int i = 0; i < 5; i++) {
            flag += s[j][i] * pow(10, 4-i);
        }
        chek[flag] += 1;
        if (chek[flag] == n) ans++;
    }
    cout << ans;
    return 0;
}