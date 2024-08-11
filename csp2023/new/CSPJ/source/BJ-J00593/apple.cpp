#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    scanf("%d", &n);
    int sy = n;
    int nbh = n;
    int ans1 = 0, ans2 = -1;
    while(sy > 0) {
        ans1++;
        int sy_ = sy;
        sy -= 1 + (sy - 1) / 3;
        if(ans2 == -1 && nbh % 3 == 1)
            ans2 = ans1;
        nbh -= 1 + (sy_ - 1) / 3;
    }
    printf("%d %d", ans1, ans2);
    return 0;
}

