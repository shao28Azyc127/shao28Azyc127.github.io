#include <bits/stdc++.h>
using namespace std;
int n, d, v[100010], a[100010], ans = 1e9;
//zai x,hua sum, youshu y
void dfs(int x, int sum, int y){
    if(x == n){
        ans = min(ans, sum);
        return ;
    } else {
        int p;
        if(v[x - 1] % d == 0){
            p =  v[x - 1] / d;
        } else {
            p = v[x- 1] / d + 1;
        }
        y = y - p;
        if(y < 0){
            return ;
        }
        int s = 0, k;
        for(int i = x; i <= n; i++){
                s = s + v[i];
        }
        if(s % d == 0){
            k =  s / d;
        } else {
            k = s / d + 1;
        }
        for(int i = 0; i <= k - y; i++){
            dfs(x + 1, sum + i * a[i], y + i);
        }
    }
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for(int i = 1; i <= n - 1; i++){
        cin >> v[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dfs(1, 0, 0);
    cout << ans;
    return 0;
}