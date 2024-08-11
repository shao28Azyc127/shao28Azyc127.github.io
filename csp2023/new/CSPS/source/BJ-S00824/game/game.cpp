#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    string s, str;
    int a[100005];
    cin >> n >> s;
    for (int i = 1; i <= n; i++) str = str + '.';
    stack <char> ch;
    stack <int> num;
    for (int i = 0; i < n; i++) {
        if (ch.size() == 0) {
            ch.push(s[i]), num.push(i);
            continue;
        }
        if (ch.top() == s[i]) {
            str[min(num.top(), i)] = '(', str[max(num.top(), i)] = ')';
            ch.pop(), num.pop();
        } else {
            ch.push(s[i]), num.push(i);
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == '.') {
            a[i] = -1;
            continue;
        }
        if (str[i] == '(') {
            cnt++;
        } else {
            cnt--;
        }
        if (str[i] == '(') a[i] = cnt;
        else a[i] = cnt + 1;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) continue;
        for (int j = i; j < n; j++) {
            if (a[j] == -1 || a[j] < a[i]) break;
            if (str[i] == '(' && str[j] == ')' && a[i] == a[j]) ans++;
        }
    }
    cout << ans;
    return 0;
}