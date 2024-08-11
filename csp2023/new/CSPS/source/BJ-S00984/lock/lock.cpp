#include <cstdio>
using namespace std;

const int N = 15;
int n, cnt;
int d[N][10];
bool wr[10];

int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 5; j++) {
            scanf("%d", &d[i][j]);
            if (i > 1 && d[i][j] != d[i-1][j]) wr[j] = 1;
        }
    }
    for (int i = 1; i <= 5; i++) if (wr[i]) cnt++;
    if (cnt == 0) puts("81");
    else if (cnt == 1) puts("10");
    else if (cnt > 2) puts("0");
    else {
        int pos = 0;
        for (int i = 1; i <= 5; i++) {
            if (wr[i] && wr[i+1]) {
                pos = i; break;
            }
        }
        if (!pos) {
            puts("0");
            return 0;
        }
        for (int i = 2; i <= n; i++) {
            if ((d[i][pos] + 10 - d[i-1][pos]) % 10 != (d[i][pos+1] + 10 - d[i-1][pos+1]) % 10) puts("0");
            else puts("10");
        }
    }
    return 0;
}
