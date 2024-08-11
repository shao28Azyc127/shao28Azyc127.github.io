#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 2e6 + 5;

int n;
string s;
int cnt[MAXN], nxt[MAXN], pos[30];
bool reach[MAXN];
vector<int> vec[30];
char t[MAXN];

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> s, s = ' ' + s;
    if (n <= 8000) {
        int ans = 0;
        for (int l = 1; l <= n - 1; l++) {
            int st = 0; t[++st] = s[l];
            int cnt = 0;
            for (int r = l + 1; r <= n; r++) {
                t[++st] = s[r];
                while (st >= 2 && t[st] == t[st - 1]) st -= 2;
                if (!st) ans++;
            }
        }
        cout << ans << '\n';
        return 0;
    }
    for (int i = n; i; i--) {
        nxt[i] = pos[s[i] - 'a'], pos[s[i] - 'a'] = i;
        vec[s[i] - 'a'].push_back(i);
    }
    for (int i = 0; i < 26; i++) {
        for (auto x : vec[i]) {
            if (!nxt[x]) continue;
            int st = 0;
            for (int j = x + 1; j < nxt[x]; j++) {
                t[++st] = s[j];
                while (st >= 2 && t[st] == t[st - 1]) st -= 2;
            }
            if (!st) reach[x] = 1;
        }
    }
    LL ans = 0;
    for (int i = n; i; i--) {
        if (!reach[i]) continue;
        cnt[i] = cnt[nxt[i] + 1] + 1;
        ans += cnt[i];
    }
    cout << ans << '\n';
    return 0;
}