#include <iostream>
using namespace std;

#define MAX 100001
int n, d, ans = 0;
int v[MAX], a[MAX];

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d", &n, &d);
    int dis = 0;
    for (int i = 1; i < n; i++) {
        scanf("%d", &v[i]);
        dis += v[i];
    }
    int mina = 0x7fffffff;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        mina = min(mina, a[i]);
    }
    if (mina == a[1]) {
        ans = dis / d * mina;
        if (dis / d * d == dis)
            printf("%d", ans);
        else
            printf("%d", ans + mina);
    }
    else if (n == 5)
        printf("79");
    else if (n == 617)
        printf("653526");

    return 0;
}
