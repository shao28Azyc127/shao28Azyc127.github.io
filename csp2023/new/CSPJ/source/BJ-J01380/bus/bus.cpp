#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k;
const int qwq = 1e4 + 5;
int a[qwq][qwq];
bool b[qwq][qwq];
ll ans = 1000000000;

void dfs(ll pos, ll res){
    if(pos == n){
        ans = min(ans, res);
        return ;
    }
    for(ll j = 1; j <= n; j ++){
        if(a[pos][j] <= res+k && b[pos][j] == true){
            if(j != pos) dfs(j, res+1);
        }
    }
}

int main(){
    freopen("bus.in", "r", stdin);
    freopen("bus.ans", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i ++){
        int x, y, t;
        scanf("%d%d%d", &x, &y, &t);
        a[x][y] = t;
        b[x][y] = true;
    }
    dfs(1, 0);
    if(ans == 1000000000){
        printf("-1");
        return 0;
    }
    ans += k;
    if(ans % k != 0){
        ans = ((ans / k) + 1) * k;
    }
    cout << ans;
    // cin >> n;
    return 0;
}

