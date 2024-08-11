#include<bits/stdc++.h>
using namespace std;

bool a[1000000010];

int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    scanf("%d", &n);
    int les = n, pos, lun = 0;
    memset(a, 1, sizeof(a));
    while (les > 0) {
        lun ++;
        int ge = 2;
        for (int i = 1; i <= n; i ++) {
            if (ge == 2 && a[i] == true) {
                a[i] = false;
                ge = 0;
                les --;
                if (i == n) pos = lun;
            }
            else if (a[i] == true) ge ++;
        }
    }
    printf("%d %d", lun, pos);
    return 0;
}
