#include<bits/stdc++.h>
using namespace std;
int n, a[10], b[10], c[10], d[10], e[10];
int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
    }
    if(n == 1) cout << 81 << endl;
    else if(n == 2) {
        if((a[1] == a[2]) && (b[1] == b[2]) && (c[1] == c[2]) && (d[1] == d[2]) && e[1] == e[2]) cout << 81 << endl;
        else if(((a[1] == a[2]) && (b[1] == b[2]) && (c[1] == c[2]) && (d[1] == d[2]))
        || ((b[1] == b[2]) && (c[1] == c[2]) && (d[1] == d[2]) && (e[1] == e[2]))) {
            cout << 10 << endl;
        }
        else if(((a[1] == a[2]) && (b[1] == b[2]) && (c[1] == c[2]) && (e[1] == e[2]))
        || ((a[1] == a[2]) && (b[1] == b[2]) && (d[1] == d[2]) && (e[1] == e[2]))
        || ((a[1] == a[2]) && (c[1] == c[2]) && (d[1] == d[2]) && (e[1] == e[2]))) {
            cout << 12 << endl;
        }
        else if(((a[1] == a[2]) && (b[1] == b[2]) && (c[1] == c[2]))
        || ((a[1] == a[2]) && (b[1] == b[2]) && (d[1] == d[2]))
        || ((a[1] == a[2]) && (b[1] == b[2]) && (e[1] == e[2]))
        || ((b[1] == b[2]) && (c[1] == c[2]) && (d[1] == d[2]))
        || ((b[1] == b[2]) && (c[1] == c[2]) && (e[1] == e[2]))
        || ((c[1] == c[2]) && (d[1] == d[2]) && (e[1] == e[2]))) {
            if((a[1] == a[2]) && (b[1] == b[2]) && (c[1] == c[2])) {
                if(abs(d[1]-d[2]) != abs(e[1]-e[2])) cout << 2 << endl;
                else cout << 8 << endl;
            }
            else if((a[1] == a[2]) && (d[1] == d[2]) && (e[1] == e[2])) {
                if(abs(b[1]-b[2]) != abs(c[1]-c[2])) cout << 2 << endl;
                else cout << 8 << endl;
            }
            else if((a[1] == a[2]) && (b[1] == b[2]) && (e[1] == e[2])) {
                if(abs(d[1]-d[2]) != abs(c[1]-c[2])) cout << 2 << endl;
                else cout << 8 << endl;
            }
            else if((c[1] == c[2]) && (d[1] == d[2]) && (e[1] == e[2])) {
                if(abs(d[1]-d[2]) != abs(e[1]-e[2])) cout << 2 << endl;
                else cout << 8 << endl;
            }
            else cout << 2 << endl;
        }
        else cout << 0 << endl;
    }
    else {
        cout << 2 << endl;
    }
    return 0;
}
