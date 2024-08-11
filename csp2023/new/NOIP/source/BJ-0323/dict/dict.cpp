#include <bits/stdc++.h>

using namespace std;

const int N = 3e3 + 5;

vector<pair<string, pair<int, int> > > ls;

bool cmp(char x, char y) {
    return x > y;
}

int tcnt = 0;
pair<int, int> a[N * 2 + 5];

bool cmp2(pair<int, int> x, pair<int, int> y) {
    return ls[x.first] < ls[y.first];
}

bool res[N];
bool dst[N];

char zs[N][N], ds[N][N];

int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) {
        cin >> zs[i];
        dst[i] = true;
        for (int j = 0; j < m; j ++ ) {
            ds[i][j] = zs[i][j];
            if (j < m - 1 && zs[i][j] != zs[i][j + 1]) {
                dst[i] = false;
            }
        }
        sort(ds[i], ds[i] + m, cmp);
        string s1 = "";
        for (int j = 0; j < m; j ++ ) {
            s1 += ds[i][j];
        }
        ls.push_back({s1, {0, i}});
        sort(zs[i], zs[i] + m);
        s1 = "";
        for (int j = 0; j < m; j ++ ) {
            s1 += zs[i][j];
        }
        ls.push_back({s1, {1, i}});
    }
    sort(ls.begin(), ls.end());
    for (auto t : ls) {
        if (t.second.first == 0) {
            if (dst[t.second.second]) {
                res[t.second.second] = 1;
            }
            break;
        }
        res[t.second.second] = 1;
    }
    for (int i = 1; i <= n; i ++ ) {
        cout << res[i];
    }
    return 0;
}