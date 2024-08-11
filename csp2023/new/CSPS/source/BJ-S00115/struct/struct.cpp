#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int maxn = 1e2 + 5;
int n, cnt1;
bool C, D = 1;
struct Node {
    string id, type;
    int l, r, p; // p DuiQiYaoQiu
};
Node a[maxn][maxn];
int op[maxn], x[maxn];
string str[maxn], id[maxn];
inline bool comp(string s) { return s != "byte" && s != "short" && s != "int" && s != "long"; }

pii rl[maxn];
int pos[maxn];
map<string, int> mp;
inline void up(int &x, int v) {
    while (x % v) x++;
}
inline void solveA() {
    int tot = 0, cur = 0;
    for (int i = 1; i <= n; i++) if (op[i] == 2) mp[id[i]] = i;
    for (int i = 1; i <= n; i++) {
        if (op[i] == 2) {
            pos[++tot] = i;
            if (str[i] == "byte") rl[i] = {cur, cur};
            else if (str[i] == "short") {
                up(cur, 2);
                rl[i] = {cur, cur+1};
                cur++;
            } else if (str[i] == "int") {
                up(cur, 4);
                rl[i] = {cur, cur+3};
                cur += 3;
            } else if (str[i] == "long") {
                up(cur, 8);
                rl[i] = {cur, cur+7};
                cur += 7;
            }
        } else if (op[i] == 3) {
            int j = mp[str[i]];
            cout << rl[j].first << '\n';
        } else {
            int l = 1, r = tot, ans = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                pii t = rl[pos[mid]];
                if (t.first <= x[i] && x[i] <= t.second) {
                    ans = pos[mid]; break;
                } else if (t.first > x[i]) {
                    r = mid - 1;
                } else l = mid + 1;
            }
            if (ans == -1) cout <<"ERR\n";
            else cout << id[ans] <<'\n';
        }
    }
    // for (int i = 1; i <= n; i++) if (op[i] == 2) cout << id[i] << ' ' << rl[i].first << ' ' << rl[i].second << '\n';
}

inline void solveC() {
    int cur = 0;
    for (int i = 1; i <= n; i++) if (op[i] == 2) mp[id[i]] = i;
    for (int i = 1; i <= n; i++) {
        if (op[i] == 2) {
            rl[i] = {cur, cur + 7};
            cur += 7;
        } else if (op[i] == 3) {
            int j = mp[str[i]];
            cout << rl[j].first << '\n';
        } else {
        }
    }
}

int main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> op[i];
        if (op[i] == 1) {
            cin >> str[i] >> x[i]; cnt1++; D = 0;
            for (int j = 1; j <= x[i]; j++) {
                cin >> a[i][j].type >> a[i][j].type;
                if (comp(a[i][j].type)) C = 0;
            }
        } else if (op[i] == 2) {
            cin >> str[i] >> id[i]; if (str[i] != "long") D = 0;
        } else if (op[i] == 3) cin >> str[i];
        else cin >> x[i];
    }
    if (cnt1 == 0) {
        solveA();
    } else if (C) {
        solveC();
    }
    return 0;
}
