#include <iostream>
#include <algorithm>
using namespace std;
string s, mx[3005], mn[3005];
int buc[1<<7];
int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    int n, m; cin >> n >> m;
    for (int i = 1, tot; i <= n; i++) {
        cin >> s; for (char c : s) buc[c]++; mn[i] = mx[i] = s;
        tot = 0; for (char j = 'a'; j <= 'z'; j++)
            for (int k = 0; k < buc[j]; k++) mn[i][tot++] = j;
        tot = 0; for (char j = 'z'; j >= 'a'; j--)
            for (int k = 0; k < buc[j]; k++) mx[i][tot++] = j;
        for (char c : s) buc[c] = 0;
    }
    for (int i = 1; i <= n; i++) {
        int f = 1;
        for (int j = 1; j <= n; j++) {
            if (j == i) continue;
            if (mn[i] >= mx[j]) { f = 0; break; }
        }
        putchar(f ^ '0');
    }
    return 0;
}