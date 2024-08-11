#include <bits/stdc++.h>
using namespace std;

string s, s1 = "  ";
int n, x, cnt;
int b[100000];
char a;

int main() {
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n >> s;
    a = s[0];
    x = 1;
    for (int i = 1; i <= n; i++) {
        b[i] = b[i - 1] + i / 2;
    }
    s = s + ' ';
    while (s != s1) {
        a = s[0];
        s1 = s;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != a) {
                cout << s;
                s.erase(i - x, x / 2 * 2);
                cout << " " << s << " " << b[x] << endl;
                a = s[i];
                cnt += b[x];
                x = 0;
            }
            x++;
        }
    }
    cout << cnt;
	return 0;
}
