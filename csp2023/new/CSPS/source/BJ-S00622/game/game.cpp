#include<iostream>
#include<cstdio>
using namespace std;

int n, ans = 0;
char str[10001];
bool f[40002][40002];

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n >> str;

    for (int i = 1;i <= n + 1;i++) {
        if (i < n && str[i - 1] == str[i]) {
            f[i][i + 1] = true;
            ans++;
        }
        f[i][i - 1] = true;
    }

    for (register int len = 4;len <= n;len += 2)
        for (register int fir = 1;fir <= n - len + 1;fir++)

            for (register int i = fir;i <= fir + len - 1;i += 2)
                for (register int j = i + 1;j <= fir + len - 1;j += 2) {
                    if (str[i - 1] != str[j - 1])
                        continue;

                    if (f[fir][i - 1] && f[i + 1][j - 1] && f[j + 1][fir + len - 1]) {
                        f[fir][fir + len - 1] = true;
                        ans++;
                        i = fir + len;
                        break;
                    }
                }

    cout << ans;
    return 0;
}
