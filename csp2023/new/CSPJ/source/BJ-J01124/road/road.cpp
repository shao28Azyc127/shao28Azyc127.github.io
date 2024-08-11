#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("./road.in", "r", stdin);
    freopen("./road.out", "w", stdout);

    int n, d;
    scanf("%d %d", &n, &d);

    int v[n];
    for (int i = 1; i <= n-1; i++) {
        scanf("%d", &v[i]);
    }

    int a[n+1];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    int totalPrice = 0;
    double hasSpaceD = 0;
    int nextI = 1;
    for (int i = 1; i <= n-1; i++) {
        if (nextI == i) {
            int price = a[i];

            for (int j = i + 1; j <= n; j ++) {
                if (a[j] < price) {
                    nextI = j;
                    break;
                }
            }
            if (i == nextI) {
                nextI = n;
            }

            int distance = 0;
            for (int j = i; j < nextI; j++) {
                distance += v[j];
            }
            distance -= (int)hasSpaceD;
            hasSpaceD -= (int)hasSpaceD;
            int totalD = distance / d;
            if (distance % d != 0) {
                totalD += 1;
                hasSpaceD += (double)(totalD * d) - (double)distance;
            }
            totalPrice += totalD * a[i];
        }
    }
    printf("%d", totalPrice);
}
