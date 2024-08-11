#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e6 + 10;
int n, f[810][810];
char s[N];

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    ios :: sync_with_stdio(0), cin.tie(0);
    cin >> n >> s + 1;
    if(n <= 8000) {
        for(int len = 2; len <= n; len++) for(int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            if(s[i] == s[j]) {
                if(len == 2) f[i][j] = 1;
                else f[i][j] = f[i + 1][j - 1];
            }
            for(int k = i + 1; k < j; k++) {
                f[i][j] |= (f[i][k] && f[k + 1][j]);
            }
        }
        ll ans = 0;
        for(int i = 1; i <= n; i++) for(int j = i; j <= n; j++) ans += f[i][j];
        cout << ans << endl;
        return 0;
    }
    int ans = 0;
    for(int i = 1; i < n; i++) if(s[i] == s[i + 1]) ans++;
    cout << ans << endl;
    return 0;
}

