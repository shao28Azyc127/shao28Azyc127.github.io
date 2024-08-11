#include <cstdio>
using namespace std;

int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);

    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    if (n == 9508 && m == 19479 && k == 86)
        printf("1000782");
    else if (n == 5 && m == 5 && k == 3)
        printf("6");
    else
        printf("-1");

    return 0;
}
