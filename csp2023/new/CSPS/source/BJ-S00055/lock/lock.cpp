

#include <iostream>
#include <vector>

const int MAXN = 19;
using namespace std;

vector<int> def[MAXN];
int N, ans;

inline int chk (int a, int b) {
    int cnt = 0;
    for (int i = 1; i < 6; i++) cnt += (def[a][i] == def[b][i]);
    if (cnt < 3) return 0;
    if (cnt == 3) {
        int k = 0;
        for (int i = 1; i < 5; i++) if (def[a][i] != def[b][i] && def[a][i+1] != def[b][i+1]) {k = i;break;}
        if (!k) return 0;
        if (def[a][k] > def[b][k]) swap(a, b);
        return (def[a][k+1] + def[b][k] - def[a][k]) % 10 == def[b][k+1];
    }
    return cnt != 5;
}

int main () {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);

    cin >> N;
    for (int i = 1; i < N+1; i++) {
        def[i].reserve(10);
        for (int j = 1; j < 6; j++) cin >> def[i][j];
    }
    def[0].reserve(10);
    int flg = 0;
    for (int i = 1; i < 6; i++) def[0][i] = def[1][i];
    for (int i = 1; i < 6; i++) {
        for (int t = 0; t < 10; t++) {
            if (t != def[1][i]) {
                def[0][i] = t;
                flg = 1;
                for (int j = 2; j < N+1; j++) flg *= chk(0, j);
                ans += flg;
            }
        }
        def[0][i] = def[1][i];
    }

    for (int i = 1; i < 5; i++) {
        for (int t = 1; t < 10; t++) {
            def[0][i] = (def[0][i] + t) % 10;
            def[0][i+1] = (def[0][i+1] + t) % 10;
            flg = 1;
            for (int j = 2; j < N+1; j++) flg *= chk(0, j);
            ans += flg;
            def[0][i] = def[1][i], def[0][i+1] = def[1][i+1];
        }
    }

    cout << ans << '\n';
    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}