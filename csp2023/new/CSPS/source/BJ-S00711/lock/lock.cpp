#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 10;
const int INF = 0x3f3f3f3f;

int n;
int a[MAXN][6];

int bucket[10][10][10][10][10] = {0};


int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 5; j++) {
            cin >> a[i][j];
        }    
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 9; j++) {
            bucket[(a[i][1] + j) % 10][a[i][2]][a[i][3]][a[i][4]][a[i][5]]++;
            bucket[a[i][1]][(a[i][2] + j) % 10][a[i][3]][a[i][4]][a[i][5]]++;
            bucket[a[i][1]][a[i][2]][(a[i][3] + j) % 10][a[i][4]][a[i][5]]++;
            bucket[a[i][1]][a[i][2]][a[i][3]][(a[i][4] + j) % 10][a[i][5]]++;
            bucket[a[i][1]][a[i][2]][a[i][3]][a[i][4]][(a[i][5] + j) % 10]++;
        }
        //bucket[a[i][1]][a[i][2]][a[i][3]][a[i][4]][a[i][5]] -= 5;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 9; j++) {
            bucket[(a[i][1] + j) % 10][(a[i][2] + j) % 10][a[i][3]][a[i][4]][a[i][5]]++;
            bucket[a[i][1]][(a[i][2] + j) % 10][(a[i][3] + j) % 10][a[i][4]][a[i][5]]++;
            bucket[a[i][1]][a[i][2]][(a[i][3] + j) % 10][(a[i][4] + j) % 10][a[i][5]]++;
            bucket[a[i][1]][a[i][2]][a[i][3]][(a[i][4] + j) % 10][(a[i][5] + j) % 10]++;;
        }
        //bucket[a[i][1]][a[i][2]][a[i][3]][a[i][4]][a[i][5]] -= 5;
    }
    int ans = 0;
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                for (int l = 0; l <= 9; l++) {
                    for (int m = 0; m <= 9; m++) {
                        if (bucket[i][j][k][l][m] == n) {
                            ans++;
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}