#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <stack>
#include <cstring>
#define ll long long
using namespace std;
const int maxn = 1e5 + 10;
int a[9][11][11][11][11][11];
char s[maxn];
int pos[30];
int l[maxn];
int r[maxn];
int c[10][10];
int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 5; j++) {
            cin >> c[i][j];
        }
    }
   //   if (n == 1) {
   //     cout << 81 << endl;
   //     return 0;
 //   }
    memset(a,0,sizeof(a));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
        a[i][j][c[i][2]][c[i][3]][c[i][4]][c[i][5]] = 1;
        a[i][c[i][1]][j][c[i][3]][c[i][4]][c[i][5]] = 1;
        a[i][c[i][1]][c[i][2]][j][c[i][4]][c[i][5]] = 1;
        a[i][c[i][1]][c[i][2]][c[i][3]][j][c[i][5]] = 1;
        a[i][c[i][1]][c[i][2]][c[i][3]][c[i][4]][j] = 1;
    }
    a[i][c[i][1]][c[i][2]][c[i][3]][c[i][4]][c[i][5]] = 0;
        for (int k = 1; k <= 9; k++) {
            a[i][(c[i][1] + k) % 10][(c[i][2] + k) % 10][c[i][3]][c[i][4]][c[i][5]] = 1;
            a[i][c[i][1]][(c[i][2] + k) % 10][(c[i][3] + k) % 10][c[i][4]][c[i][5]] = 1;
             a[i][c[i][1]][c[i][2]][(c[i][3] + k) % 10][(c[i][4] + k) % 10][c[i][5]] = 1;
             a[i][c[i][1]][c[i][2]][c[i][3]][(c[i][4] + k) % 10][(c[i][5] + k) % 10] = 1;
        }
    }
    int ans = 0;
    for (int a1 = 0; a1 <= 9; a1++) {
        for (int a2 = 0;a2 <= 9; a2++) {
            for(int a3 = 0;a3 <= 9; a3++) {
                for (int a4 = 0; a4 <= 9; a4++) {
                    for (int a5 = 0;a5 <= 9; a5++) {
                        int t = 1;
                        for (int i = 1; i <= n; i++) {
                            if (a[i][a1][a2][a3][a4][a5] == 0) {
                                t = 0;
                                break;
                            }
                        } 
                        ans += t;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
