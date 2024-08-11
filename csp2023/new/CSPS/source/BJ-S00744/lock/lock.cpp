#include <bits/stdc++.h>
using namespace std;

const int MAXN = 9;
int n, t, i_lock[MAXN][5];

int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < 5; j ++){
            cin >> t;
            i_lock[i][j] = t;
        }
    }

    if (n == 1){
        cout << 81;
        return 0;
    }

    int dfr = 0;
    bool same[5] = {1,1,1,1,1};
    for (int i = 0; i < 5; i ++){
        for (int j = 0; j < n; j ++){
            if (i_lock[0][i] != i_lock[j][i]){
                same[i] = 0;
                dfr ++;
                break;
            }
        }
    }

    if (dfr > 2){
        cout << 0;
        return 0;
    }

    if (dfr == 1){
        cout << 10;
        return 0;
    }

    if (dfr == 0){
        cout << 81;
        return 0;
    }

    for (int i = 0; i < 4; i ++){
        if (same[i] == 0){
            if (same[i+1] == 0){
                bool flag = 1;
                for (int j = 1; j < n; j ++){
                    if ((i_lock[0][i] - i_lock[0][i+1] + 10) % 10 != (i_lock[j][i] - i_lock[j][i+1] + 10) % 10){
                        flag = 0;
                        break;
                    }
                }

                if (flag == 1) {
                    cout << 10;
                    return 0;
                }
                cout << 0;
                return 0;
            }
            cout << 0;
            return 0;
        }
    }

    return 0;
}
