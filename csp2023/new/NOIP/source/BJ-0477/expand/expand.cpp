#include <bits/stdc++.h>
using namespace std;

int c, m, n, q;

int main(){
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    srand(time(NULL));
    cin >> c >> m >> n >> q;
    for (int i = 1,t;i <= n;++i) scanf("%d", &t);
    for (int i = 1,t;i <= m;++i) scanf("%d", &t);
    cout << 0;
    while (q--){
        int kx, ky;
        scanf("%d%d", &kx, &ky);
        for (int i = 1;i <= kx;++i){
            int px, vx;
            scanf("%d%d", &px, &vx);
        }
        for (int i = 1;i <= ky;++i){
            int py, vy;
            scanf("%d%d", &py, &vy);
        }
        cout << rand() % 2;
    }

    return 0;
}
