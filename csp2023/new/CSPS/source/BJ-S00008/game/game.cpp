#include <bits/stdc++.h>

using namespace std;

int n;
string s;
int cnt;

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    cin >> n >> s ;

    int n1 = n - 1;

    for (int i = 0; i < n; i++) {
        for (int j = 2; i + j <= n; j += 2) {
            string s2 = s.substr(i, j);

            bool ok = 1;

            while (ok) {
                ok = 0;
                int lens21 = s2.length() - 1;
                for (int k = 0; k < lens21; k++) {
                    if (s2[k] == s2[k + 1]) {
                        s2.erase(k, 2);
                        ok = 1;
                    }
                }
            }

            if (s2.length() == 0) {
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
