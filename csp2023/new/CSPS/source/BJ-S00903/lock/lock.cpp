#include<cstdio>
using namespace std;
int wrong[8][5];
int cur[5];
int change[9][5] = {
    {1, 0, 0, 0, 0},
    {1, 1, 0, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 1, 0},
    {0, 0, 0, 1, 1},
    {0, 0, 0, 0, 1}
};
bool check(int id) {
    int x[5];
    for (int i = 0; i < 5; ++i) {
        x[i] = (10 + wrong[id][i] - cur[i]) % 10;
    }
    if (!(x[0] | x[1] | x[2] | x[3] | x[4])) return false;
    if (!(x[1] | x[2] | x[3] | x[4])) return true;
    if (!(x[2] | x[3] | x[4] | (x[0] ^ x[1]))) return true;
    if (!(x[0] | x[2] | x[3] | x[4])) return true;
    if (!(x[0] | x[3] | x[4] | (x[1] ^ x[2]))) return true;
    if (!(x[0] | x[1] | x[3] | x[4])) return true;
    if (!(x[0] | x[1] | x[4] | (x[2] ^ x[3]))) return true;
    if (!(x[0] | x[1] | x[2] | x[4])) return true;
    if (!(x[0] | x[1] | x[2] | (x[3] ^ x[4]))) return true;
    if (!(x[0] | x[1] | x[2] | x[3])) return true;
    return false;
}
int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            scanf("%d", &wrong[i][j]);
        }
    }
    int ans = 0;
    for (int c = 1; c < 10; ++c) {
        for (int t = 0; t < 9; ++t) {
            for (int i = 0; i < 5; ++i) {
                if (change[t][i]) cur[i] = (wrong[0][i] + c) % 10;
                else cur[i] = wrong[0][i];
            }
            bool flag = true;
            for (int i = 1; flag && i < n; ++i) {
                flag = flag && check(i);
            }
            if (flag) ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}