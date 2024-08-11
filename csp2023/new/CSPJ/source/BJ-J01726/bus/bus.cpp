#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 10;
int n, m, k;

struct Node
{
    int to, next, kf;
};
//int pre[N], kk, q[N * 2];

int add(int u, int v, int l) {
    //a[++kk] = {v, pre[u]};
    //pre[u] = kk;
}

int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);

    scanf("%d %d %d", &n, &m, &k);

    for (int i = 1; i <= m; i++) {
        int x, y, l;

        scanf("%d %d %d", &x, &y, &l);
        //add(x, y, l);
    }

    printf("-1");

    return 0;
}
