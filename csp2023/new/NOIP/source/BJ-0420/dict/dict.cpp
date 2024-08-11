#include<bits/stdc++.h>
using namespace std;
int n, m;
char pre[3010];
char suf[3010];
char s[3010][3010];
bool cmp(char x, char y) {
    return x>y;
}
bool cmp2(int x, int y) {
    for(int i=1; i<=m; ++i) {
        if(s[x][m-i+1]<s[y][i]) return true;
    }
    return false;
}
int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) cin >> s[i][j];
        sort(s[i]+1, s[i]+m+1, cmp);
        //for(int j=1; j<=m; ++j) cout <<s[i][j];
        //cout << '\n';
    }
    pre[0] = suf[n+1] = 255;
    for(int i=1; i<=n; ++i) {
        pre[i] = min(pre[i-1], s[i][1]);
    }
    for(int i=n; i>0; --i) {
        suf[i] = min(suf[i+1], s[i][1]);
    }
    for(int i=1; i<=n; ++i) {
        //sort(s[i]+1, s[i]+m+1, cmp1);
        if(s[i][m]<min(pre[i-1], suf[i+1])) {
            cout << 1;
            continue;
        }
        bool flag = true;
        for(int j=1; j<=n; ++j) {
            if(i==j) continue;
            if(!cmp2(i, j)) {
                flag = false;
                break;
            }
        }
        //sort(s[i]+1, s[i]+m+1, cmp);
        cout <<flag?1:0;
    }
    //cout << '\n';
    return 0;
}
