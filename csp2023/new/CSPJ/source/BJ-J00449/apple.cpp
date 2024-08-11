#include <cstdio>
using namespace std;

int n;

int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    scanf("%d", &n);
    int cnt = 0, ans = -10;
    bool lock_ans = false;
    while (n) {
        if (!lock_ans && n % 3 == 1) {
            ans = cnt + 1;
            lock_ans = true;
        }
        if (n % 3 == 0)
            n = n / 3 * 2;
        else
            n -= n / 3 + 1;
        cnt++;
    }
    printf("%d %d\n", cnt, ans);
    return 0;
}
