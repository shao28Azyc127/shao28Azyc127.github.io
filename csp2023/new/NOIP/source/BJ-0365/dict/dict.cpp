#include<bits/stdc++.h>
using namespace std;
const int N = 3000 + 5;
const int M = 30;
int n, m, t[M], amin[N][N], amax[N][M];
int bmx[M], bidx, cmx[M], cidx;
int b[N], c[N];
char s[N][N];
bool checkb(int k) {
    for(int i = 0; i < 26; i++) {
        if (amax[k][i] < bmx[i]) return 1;
        if (amax[k][i] > bmx[i]) return 0;
    }
    return 0;
}
bool checkc(int k) {
    for(int i = 0; i < 26; i++) {
        if (amax[k][i] < cmx[i]) return 1;
        if (amax[k][i] > cmx[i]) return 0;
    }
    return 0;
}
bool checkbb(int k) {
    for(int i = 1; i <= m; i++) {
        if (amin[k][i] < b[i]) return 1;
        if (amin[k][i] > b[i]) return 0;
    }
    return 0;
}
bool checkcc(int k) {
    for(int i = 1; i <= m; i++) {
        if (amin[k][i] < c[i]) return 1;
        if (amin[k][i] > c[i]) return 0;
    }
    return 0;
}
int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) cin >> s[i][j];
        memset(t, 0, sizeof(t));
        for(int j = 1; j <= m; j++) t[s[i][j]-'a']++;
        for(int j = 0; j < 26; j++) amax[i][j] = t[26-j-1];
        int p = 0;
        for(int j = 0; j < 26; j++) {
            while (t[j]) {
                amin[i][++p] = j;
                t[j]--;
            }
        }
    }
    if (n == 1) {
        cout << "1\n";
        return 0;
    }
    for(int i = 0; i < 26; i++) bmx[i] = amax[1][i];
    bidx = 1;
    memset(cmx, 0x3f, sizeof(cmx));
    cidx = -1;
    for(int i = 2; i <= n; i++) {
        bool cb = checkb(i), cc = checkc(i);
        if (cb) {
            for(int j = 0; j < 26; j++) cmx[j] = bmx[j];
            cidx = bidx;
            for(int j = 0; j < 26; j++) bmx[j] = amax[i][j];
            bidx = i;
        } else if (cc) {
            for(int j = 0; j < 26; j++) cmx[j] = amax[i][j];
            cidx = i;
        }
    }
    int p = 0;
    for(int i = 0; i < 26; i++) {
        while (bmx[i]) {
            b[++p] = 26-i-1;
            bmx[i]--;
        }
    }
    p = 0;
    for(int i = 0; i < 26; i++) {
        while (cmx[i]) {
            c[++p] = 26-i-1;
            cmx[i]--;
        }
    }
    for(int i = 1; i <= n; i++) {
        if (bidx != i) {
            bool cb = checkbb(i);
            cout << cb;
        } else {
            bool cc = checkcc(i);
            cout << cc;
        }
    }
    return 0;
}
