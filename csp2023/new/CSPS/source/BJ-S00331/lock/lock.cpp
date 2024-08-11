#include <bits/stdc++.h>

using namespace std;

int T;
int st[199999];

int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> T;
    for(int i = 1; i <= T; i++) {
        int c1, c2, c3, c4, c5;
        int b[6], cnts, ans = 0;
        cin >> c1 >> c2 >> c3 >> c4 >> c5;
        for(int i1 = 0; i1 <= 9; i1++) {
            for(int i2 = 0; i2 <= 9; i2++) {
                for(int i3 = 0; i3 <= 9; i3++) {
                    for(int i4 = 0; i4 <= 9; i4++) {
                        for(int i5 = 0; i5 <= 9; i5++) {
                            int cnts = 0, tu = -1;
                            b[1] = b[2] = b[3] = b[4] = b[5] = 0;
                            b[1] = (c1 - i1 + 10) % 10; if(b[1] == 0) {cnts++;}
                            b[2] = (c2 - i2 + 10) % 10; if(b[2] == 0) cnts++; else if(cnts == 0){if(b[1] != 0) tu = 1;}
                            b[3] = (c3 - i3 + 10) % 10; if(b[3] == 0) cnts++; else if(cnts == 1){if(b[2] != 0) tu = 2;}
                            b[4] = (c4 - i4 + 10) % 10; if(b[4] == 0) cnts++; else if(cnts == 2){if(b[3] != 0) tu = 3;}
                            b[5] = (c5 - i5 + 10) % 10; if(b[5] == 0) cnts++; else if(cnts == 3){if(b[4] != 0) tu = 4;}
                            if(cnts == 4) st[i1 * 10000 + i2 * 1000 + i3 * 100 + i4 * 10 + i5]++;
                            if(cnts == 3) {
                                if(tu == -1) continue;
                                if(b[tu] == b[tu + 1]) st[i1 * 10000 + i2 * 1000 + i3 * 100 + i4 * 10 + i5]++;
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= 99999; i++) if(st[i] == T) ans++;
    cout << ans << endl;
    return 0;
}
