# include <bits/stdc++.h>
using namespace std;
const int MAXN = 8e3 + 10;
int n, d[MAXN];
char ch[MAXN], st[MAXN];
int top = 0;
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
    cin >> n;
    cin >> (ch + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        top = 0;
        for (int j = i; j <= n; j++) {
            if (top && st[top] == ch[j]) top--;
            else st[++top] = ch[j];
            if (top == 0) ans++;
        }
    }
    cout << ans << endl ;
	return 0;
}