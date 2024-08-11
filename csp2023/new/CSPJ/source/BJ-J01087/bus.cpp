#include <bits/stdc++.h>

using namespace std;

int n , m , d;
int t;
int G[10010][10010] , f[10010][10010];

int main(){
    freopen("bus.in" , "r" , stdin);
    freopen("bus.out" , "w" , stdout);
    cin >> n >> m >> d;
    int cnt = 0;
    memset(G , -1 , sizeof(G));
    for (int i = 1 ; i <= m ; i ++){
        int u , v1 , w;
        cin >> u >> v1 >> w;
        if (w == 0) cnt ++;
        G[u][v1] = G[v1][u] = w;
    }
    if (cnt == m){
        cout << d * 2 << endl;
        return 0;
    }

    t = d * 2;
    for (int i = 1 ; i <= n ; i ++){
        for (int j = 1 ; j <= n ; j ++){
            if (i == j) f[i][j] = 0;
            else if (G[i][j] > 0) f[i][j] = G[i][j];
            else G[i][j] = 0x3f3f3f3f;
        }
    }
    for (int k = 1 ; k <= n ; k ++){
        for (int i = 1 ; i <= n ; i ++){
            for (int j = 1 ; j <= n ; j ++){
                if (f[i][k] + f[k][j] < f[i][j]){
                    f[i][j] = f[i][k] + f[k][j];
                }
            }
        }
    }
    if (f[1][n] - t > t){
        t += d;
    }
    cout << t << endl;

    return 0;
}
