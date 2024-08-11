#include<cstdio>
using namespace std;
typedef long long LL;
LL r1 = 0, v1[15], n, a[18][15];
bool valid() {
    for (int i = 0; i < n; i ++ ) {
        int cnt = 0;
        for (int j = 0; j < 5; j ++ ) {
            if (v1[j] < 0 || v1[j] > 9) return false;
            if (a[i][j] != v1[j]) {
                cnt++;
                if (cnt == 2 && a[i][j - 1] - v1[j - 1] != a[i][j] - v1[j]) return false;
            }
        }

        if (cnt == 0 || cnt > 2) return false;
    }


    return true;
}
int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%lld", &n);
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < 5; j ++ ) {
            scanf("%lld", &a[i][j]);
        }
    }

    for (int i = 0; i < 5; i ++ ) {
        for (int j = 0; j < 10; j ++ ) {
            if (a[0][i] == j) continue;
            for (int k = 0; k < 5; k ++ ) {
                v1[k] = (i == k) ? j : a[0][k];
            }

            if (valid()) r1++;
        }
    }

    for (int i = 0; i < 4; i ++ ) {
        for (int j = 0; j < 10; j ++ ) {
            if (a[0][i] == j) continue;
            for (int k = 0; k < 5; k ++ ) {
                if (k == i || k == i + 1) {
                    v1[k] = a[0][k] + j - a[0][i];
                } else {
                    v1[k] = a[0][k];
                }
            }

            if (valid()) r1++;
        }
    }

    printf("%lld\n", r1);
    return 0;
}
