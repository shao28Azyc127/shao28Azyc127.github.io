#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Edge {
    int v, next;

    Edge(int x = 0, int y = 0) {
        v = x;
        next = y;
    }
} E[200001];
int head[100001], cnt;

void addEdge(int u, int v) {
    E[++cnt] = Edge(v, head[u]);
    head[u] = cnt;
}

int n;
long long a[100001];
long long b[100001];
long long c[100001];
long long ans = 0;

int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    bool fA = 1, fB = 1, fC = 1, fD = 1;
    scanf("%d", &n);
    for(int i = 1;i <= n;i++) {
        scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
        if(c[i] == 0) fA = 0;
    }
    for(int i = 1;i < n;i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
        if(u > 1) fD = 0;
        if(u != i || v != i + 1) fB = 0;
    }
    if(fA) {
    } else if(fB) {
        for(int i = 1;i <= n;i++) {
            long long s = 0, t = i;
            for(long long k = b[i] + i * c[i];k >= 1 && s < a[i];t++, k += c[i]) s += k;
            if(s < a[i]) t += (a[i] - s);
            t--;
            ans = max(ans, t);
        }
    } else if(fC) {
    } else if(fD) {
    } else if(n <= 20) {
    } else {}
    printf("%lld", ans);
    return 0;
}
