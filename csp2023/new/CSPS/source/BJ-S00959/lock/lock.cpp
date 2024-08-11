// rui_er is kawaii!!!
#include <bits/stdc++.h>
using namespace std;

#ifndef RUIER
ifstream fin("lock.in");
ofstream fout("lock.out");
#define cin fin
#define cout fout
#endif

int n, A[6], B[6], ans;
bool ok[10][10][10][10][10][10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < 5; ++j) {
            cin >> A[j];
        }
        for(int j = 0; j < 5; ++j) {
            for(int delta = 1; delta < 10; ++delta) {
                for(int k = 0; k < 5; ++k) {
                    if(j == k) B[k] = (A[k] + delta) % 10;
                    else B[k] = A[k];
                    // cerr << B[k] << " \n"[k == 4];
                }
                ok[i][B[0]][B[1]][B[2]][B[3]][B[4]] = true;
            }
        }
        for(int j = 0; j < 4; ++j) {
            int k = j + 1;
            for(int delta = 1; delta < 10; ++delta) {
                for(int l = 0; l < 5; ++l) {
                    if(l == j || l == k) B[l] = (A[l] + delta) % 10;
                    else B[l] = A[l];
                    // cerr << B[l] << " \n"[l == 4];
                }
                ok[i][B[0]][B[1]][B[2]][B[3]][B[4]] = true;
            }
        }
    }
    for(int a = 0; a < 10; ++a) {
        for(int b = 0; b < 10; ++b) {
            for(int c = 0; c < 10; ++c) {
                for(int d = 0; d < 10; ++d) {
                    for(int e = 0; e < 10; ++e) {
                        bool now = true;
                        for(int i = 1; i <= n; ++i) {
                            now &= ok[i][a][b][c][d][e];
                        }
                        if(now) {
                            ++ans;
                        }
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}