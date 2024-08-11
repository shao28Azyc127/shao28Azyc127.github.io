#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
const int N = 8005;
int n;
string s;
int ans = 0;
int ln;
char ch[N];
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n;
    cin >> s;
    s = " " + s;
    for(int i = 1; i <= n; i++) {
        ln = 0;
        int tp = n;
        if(n > 8000) {
            tp = min(n, i + 30 - 1);
        }
        for(int j = i; j <= tp; j++) {
            if(ln > 0 && ch[ln] == s[j]) {
                ln--;
            } else {
                ln++;
                ch[ln] = s[j];
            }
            if(ln == 0) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
