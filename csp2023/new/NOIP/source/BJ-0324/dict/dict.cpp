#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 3005;
const int INF = 0x3f3f3f3f;

int n, m;
string s[MAXN];
int bucket[26][MAXN];

void bucketify(string s, int id) {
    for (int i = 0; i < s.length(); i++) {
        bucket[s[i] - 'a'][id]++;
    }
}

bool cmp(string x, string y) { // true if x < y
    for (int i = 0; i < x.length(); i++) {
        if ((x[i] - 'a') > (y[i] - 'a')) {
            return false;
        }
        if ((x[i] - 'a') < (y[i] - 'a')) {
            return true;
        }
    }
    return false;
}

bool cmpByBucket(int x, int y) {
    int alphx = 0;
    int alphy = 25;
    while (bucket[alphx][x] == 0) {
        alphx++;
    }
    while (bucket[alphy][y] == 0) {
        alphy--;
    }
    if (alphx < alphy) {
        return true;
    }
    if (alphx > alphy) {
        return false;
    }
    if (bucket[alphx][x] > bucket[alphy][y]) {
        return false;
    }
    if (bucket[alphx][x] < bucket[alphy][y]) {
        return false;
    }
    return false;
}


int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n >> m;
    string minstr;
    int minstrid = 1;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        bucketify(s[i], i);
        if (i == 1) {
            minstr = s[i];
        }
        else {
            if (cmp(s[i], minstr)) {
                minstr = s[i];
                minstrid = i;
            }
        }
    }
    // for (int i = 0; i < 26; i++) {
    //     cout << char(i + 'a') << " " << bucket[i][minstrid] << endl;
    // }
    // cout << endl;
    for (int i = 1; i <= n; i++) {
       /* 
        int cnt = 0;
        int curalph = 0;
        string cur = s[i];
        int changeid = 0;
        char change = '#';
        for (int j = 0; j < m; j++) {
            changeid = j;
            for (int k = 0; k < (s[i][j] - 'a'); k++) {
                if (bucket[k][i] != 0) {
                    change = char(k + 'a');
                    break;
                }
            }
            if (change != '#') {
                break;
            }
        }
        cout << "change: " << change  << " changeid: " << changeid << endl;
        if (change != '#') {
            for (int j = m - 1; j >= 0; j--) {
                if (s[i][j] == change) {
                    s[i][j] = s[i][changeid];
                    s[i][changeid] = change;
                }
            }
        }
        */
        if (0 && i == 3) {
            for (int j = 0; j < 26; j++) {
                cout << char(j + 'a') << " " << bucket[j][i] << endl;
            }
        }
        //cout << "cur: " << cur << ", minstr: " << minstr << endl;
        bool ok = true;
        for (int j = 1; j <= n; j++) {
            if (j == i) continue;
            if (!cmpByBucket(i, j) && s[i] != minstr) {
                ok = false;
            }
        }
        if (ok) {
            cout << 1;
        }
        else {
            cout << 0;
        }
    }
    cout << endl;
    return 0;
}