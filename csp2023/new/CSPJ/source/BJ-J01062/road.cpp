#include <iostream>
using namespace std;

int n, d, ans;
int v[100005], a[100005];

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    scanf("%d%d", &n, &d);
    for (int i=1; i<n; i++) {
        scanf("%d", &v[i]);
    }
    for (int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
    }

    int l=0, y=0, f=1;
    for (int u=1; u<n; u++) {
        if (y <= v[u]) {
            l=(v[u]-y)/d;
            if (d*l+y < v[u]) l++;
            y=d*l+y-v[u];
            if (a[u] < a[f]) f=u;
            ans+=a[f]*l;

            //printf("%d %d %d %d\n", l, y, f, ans);
        }
        else {
            y-=v[u];
            //printf("-1\n");
        }
    }

    printf("%d\n", ans);
    return 0;
}
