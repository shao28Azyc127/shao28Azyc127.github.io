#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 3000 + 10;
string s[maxn];
int n, m, p1, p2, cnt[30];
int main() {
    ios::sync_with_stdio(false);
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i]; for (char ch : s[i]) ++cnt[ch - 'a']; s[i].clear(); 
        for (int ch = 25; ~ch; ch--) for (; cnt[ch]; cnt[ch]--) s[i].push_back(ch + 'a');
    }
    for (int i = 1; i <= n + 1; i++) s[0].push_back('z');
    for (int i = 1; i <= n; i++) 
        if (s[i] < s[p1]) p2 = p1, p1 = i;
        else if (s[i] < s[p2]) p2 = i;
    for (int i = 1; i <= n; i++) {
        string t = s[i]; reverse(t.begin(), t.end());
        cout << (s[p1 == i ? p2 : p1] > t);
    }
    return 0;
}