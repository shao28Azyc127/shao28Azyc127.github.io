#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1E6;
char s[N + 1];
char c[N + 1];
int main() {
    freopen("game.in","r", stdin);
    freopen("game.out","w",stdout);
    int n;
    cin >> n;
    int flag = 1;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        if(i != 1 && flag && s[i] == s[i - 1]) {
            flag = 0;
        }
    }
    if(!flag) {
        int t = 1;
        int an = 0;
        while(t < n) {
            an += n - t;
        }
        cout << an;
        return 0;
    }
    int ans = 0;
    int p;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j += 2) {
            if(p != 0) {
                for(int k = 1; k <= j - i + 1; k++) {
                    c[k] = NULL;
                }
            }
            p = 1;
            c[p] = s[i];
            for(int k = i + 1; k <= j; k++) {
                if(s[k] == c[p]) {
                    c[p] = NULL;
                    p--;
                }
                else {
                    p++;
                    c[p] = s[k];
                }
            }
            if(p == 0) {
                cout << ans << ' ' << i << ' ' << j << endl;
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}