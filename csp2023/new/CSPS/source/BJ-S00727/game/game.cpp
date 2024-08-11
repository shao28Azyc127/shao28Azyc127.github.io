#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n, top, ans, st[N];
string s;
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d", &n);
    cin >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        top = 0;
        for (int j = i; j <= n; j++) {
            if (top && s[j] == s[st[top]]) top--;
            else st[++top] = j;
            if (!top) ans++;
        }
    }
    printf("%d", ans);
    return 0;
}