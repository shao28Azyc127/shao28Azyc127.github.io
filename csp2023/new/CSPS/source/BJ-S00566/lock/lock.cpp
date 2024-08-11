#include <bits/stdc++.h>

#define ff(i, a, b) for(int i = (a); i <= (b); i++)

#define ull unsigned long long

using namespace std;

inline int Read () {
    char c = getchar();
    while (c != '-' && (c > '9' || c < '0'))  c = getchar();
    int res = 0;
    int sign = (c == '-')? -1 : 1;
    if (c != '-')
        res += c - '0', res = (res << 3) + (res << 1);
    c = getchar ();
    while (c <= '9' && c >= '0'){
        res += c - '0';
        res = (res << 3) + (res << 1);
        c = getchar ();
    }
    return res * sign / 10;
}


int main () {
    
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    
    int lock[10][10][10][10][10] = {};
    int n;
    cin >>n;
    int a [6] = {};
    int s [6][10] = {};
    for (int t = 1; t <= n; t ++){
        for (int i = 1; i <= 5; i ++) {
            cin >>a[i];
            s[i][t] = a[i];
        }
        t --;
        for (int i = 0; i < 10; i ++)
            lock [i][a[2]][a[3]][a[4]][a[5]] |= 1 << t;
        for (int i = 0; i < 10; i ++)
            lock [a[1]][i][a[3]][a[4]][a[5]] |= 1 << t;
        for (int i = 0; i < 10; i ++)
            lock [a[1]][a[2]][i][a[4]][a[5]] |= 1 << t;
        for (int i = 0; i < 10; i ++)
            lock [a[1]][a[2]][a[3]][i][a[5]] |= 1 << t;
        for (int i = 0; i < 10; i ++)
            lock [a[1]][a[2]][a[3]][a[4]][i] |= 1 << t;
        
        for (int i = 0; i < 10; i ++) {
            int l = a[1] + i;
            int r = a[2] + i;
            l %= 10;
            r %= 10;
            lock [l][r][a[3]][a[4]][a[5]] |= 1 << t;
        }
        
        
        for (int i = 0; i < 10; i ++) {
            int l = a[2] + i;
            int r = a[3] + i;
            l %= 10;
            r %= 10;
            lock [a[0]][l][r][a[4]][a[5]] |= 1 << t;
        }
        
        
        for (int i = 0; i < 10; i ++) {
            int l = a[3] + i;
            int r = a[4] + i;
            l %= 10;
            r %= 10;
            lock [a[1]][a[2]][l][r][a[5]] |= 1 << t;
        }
        
        
        for (int i = 0; i < 10; i ++) {
            int l = a[4] + i;
            int r = a[5] + i;
            l %= 10;
            r %= 10;
            lock [a[1]][a[2]][a[3]][l][r] |= 1 << t;
        }
        t++;
    }
    
    ff(i, 1, n){
        lock[s[1][i]][s[2][i]][s[3][i]][s[4][i]][s[5][i]] = 0;
    }
    
    ull ans = 0;
    ff(aa, 0, 9)
    ff(bb, 0, 9)
    ff(cc, 0, 9)
    ff(dd, 0, 9)
    ff(ee, 0, 9)
    if ((lock[aa][bb][cc][dd][ee]) == (1 << n) - 1)
        ans ++;
    printf ("%lld\r\n", ans);
    return 0;
}
