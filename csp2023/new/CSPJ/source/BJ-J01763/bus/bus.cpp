#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 10;

int n, m, k;
int u[N], v[N], a[N];
bool go[N][N], flag;
int minn = 1e9, maxn = -1;

void dfs(int x, int t){
        if(x == n && t % k == 0){
                flag = true;
                minn = min(minn, t);
                return ;
        }

        for(int i = 1; i <= n; i++){
                if(go[x][i] && a[i] <= t){
                        dfs(i, t + 1);
                }
        }

        return ;
}

int main(){
        freopen("bus.in", "r", stdin);
        freopen("bus.out", "w", stdout);

        scanf("%d%d%d", &n, &m, &k);

        for(int i = 1; i <= m; i++){
                scanf("%d%d%d", &u[i], &v[i], &a[i]);
                maxn = max(maxn, a[i]);
                go[u[i]][v[i]] = true;
        }
        
        for(int i = 0; i <= maxn; i += k){
                dfs(1, i);
        }

        if(!flag) cout << -1 << endl;
        else cout << minn << endl;
        return 0;
}
