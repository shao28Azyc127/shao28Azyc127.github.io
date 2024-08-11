/*
this problem is too hard!

i can`t solve it, so i will afo!

*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int csq, t;

int s[N], vs[N];
int n, m;

vector<pair<char, pair<int, int> > > qs;

int cres = 0;

char ns[15];
char qt[4] = "TFU"; 
char la[15];

bool qiu() {
    for (int i = 1; i <= n; i ++ ) {
        la[i] = ns[i];
    }
    for (int i = 0; i < m; i ++ ) {
        auto t = qs[i];
        if (t.first == 'T') {
            la[t.second.first] = 'T';
        } else if (t.first == 'U') {
            la[t.second.first] = 'U';
        } else if (t.first == 'F') {
            la[t.second.first] = 'F';
        } else if (t.first == '+') {
            la[t.second.first] = la[t.second.second];
        } else {
            la[t.second.first] = la[t.second.second] == 'U' ? 'U' : (la[t.second.second] == 'T' ? 'F' : 'T');
        }
    }
    for (int i = 1; i <= n; i ++ ) {
        if (la[i] != ns[i]) {
            return false;
        }
    }
    return true;
}

void query(int u, int xs) {
    if (u == n + 1) {
        if (qiu()) {
            cres = min(cres, xs);
        }
        return ;
    }
    for (int i = 0; i < 3; i ++ ) {
        ns[u] = qt[i];
        if (i == 2) {
            query(u + 1, xs + 1);
        } else {
            query(u + 1, xs);
        }
    }
}

int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> csq >> t;
    while (t -- ) {
        cin >> n >> m;
        if (csq >= 3 && csq <= 6) {
            for (int i = 1; i <= n; i ++ ) {
                s[i] = 0;
                vs[i] = 0;
            }
        }
        qs.clear();
        for (int i = 1; i <= m; i ++ ) {
            char op;
            int x;
            int y;
            cin >> op >> x;
            
            if (op == 'U' || op == 'T' || op == 'F')
                qs.push_back({op, {x, 0}});
            else {
                cin >> y;
                qs.push_back({op, {x, y}});
            }
            if (csq == 3 || csq == 4) {
                if (op == 'U') {
                    s[x] = 1;
                } else {
                    s[x] = 0;
                }
            }
            if (csq == 5 || csq == 6) {
                if (op == 'U') {
                    s[x] = 1;
                } else {
                    s[x] = s[y];
                }
            }

        }
        if (csq <= 2) {
            cres = 1000;
            query(1, 0);
            cout << cres << '\n';
            continue;
        }
        if (csq >= 5 && csq <= 6) {
            for (int i = 0; i < m; i ++ ) {
                auto t = qs[i];
                if (t.first == '+') {
                    if (s[t.second.second])
                        s[t.second.first] = s[t.second.second];
                }
            }
            for (int i = 0; i < m; i ++ ) {
                auto t = qs[i];
                if (t.first == '+') {
                    if (s[t.second.second])
                        s[t.second.first] = s[t.second.second];
                }
            }
        }
        if (csq >= 3 && csq <= 6) {
            int res = 0;
            for (int i = 1; i <= n; i ++ ) {
                if (s[i]) {
                    res ++;
                }
            }
            cout << res << "\n";
            continue;
        }
    }
    return 0;
}