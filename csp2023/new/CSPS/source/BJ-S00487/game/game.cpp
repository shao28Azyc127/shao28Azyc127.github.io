#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    int n, ans = 0;
    char s[2000001];
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++)
        scanf("%c", &s[i]);
    for (int l = 1; l < n; l++) {
        for (int r = l+1; r <= n; r+=2) {
            stack<char> c;
            for (int i = l; i <= r; i++) {
                if (c.empty() || c.top() != s[i])
                    c.push(s[i]);
                else
                    c.pop();
            }
            if (c.empty())
                ans++;
        }
    }
    printf("%d", ans);

    return 0;
}
