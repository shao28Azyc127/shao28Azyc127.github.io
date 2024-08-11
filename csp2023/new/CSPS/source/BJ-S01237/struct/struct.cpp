#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;
const int maxn = 1e4 + 10;
const string E = "ERR";
int n, x, op, tot;
string s[maxn];
unordered_map<string, int> B, S;
map<string, vector<pair<int, string> > > P;
int main() {
    ios::sync_with_stdio(false);
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    cin >> n; B["byte"] = 1; B["short"] = 2; B["int"] = 4; B["long"] = 8;
    while (n--) {
        cin >> op;
        string a, b;
        if (op == 1) {
            cin >> a >> x;
            P[a].resize(x); int cur = 0;
            for (auto& [w, u] : P[a]) cin >> b >> u, B[a] = max(B[a], w = B[b]), cur += w;
            while (cur % B[a] != 0) ++cur;
            cout << cur << ' ' << B[a] << '\n';
        }
        else if (op == 2) {
            cin >> a >> b; int st;
            for (st = tot; st % B[a] != 0; st++); S[b] = st;
            cout << st << '\n';
            string cur;
            cur = b + '.';
            if (P[a].empty()) {
                for (int i = st; i < st + B[a]; i++) s[i] = b;
                tot = st + B[a] - 1;
            } else {
                for (auto [w, u] : P[a]) {
                    S[cur + u] = st;
                    for (int i = 1; i <= w; i++) s[st++] = cur + u;
                }
                while (st % B[a] != 0) ++st;
                tot = st;
            }
        }
        else if (op == 3) cin >> a, cout << S[a] << '\n';
        else {
            cin >> x;
            if (s[x].empty()) cout << "ERR\n";
            else cout << s[x] << '\n'; 
        }
    }
    return 0;
}