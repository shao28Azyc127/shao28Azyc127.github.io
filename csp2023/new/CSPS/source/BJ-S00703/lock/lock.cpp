#include <bits/stdc++.h>
using namespace std;
int a[6], b[10][6];
int n;
bool check(){
    for (int i = 1; i <= n; i++){
        int pos1 = 0, pos2 = 0;
        int x1, x2;
        for (int j = 1; j <= 5; j++){
            if (b[i][j] != a[j]){
                if (!pos1){
                    pos1 = j;
                    x1 = (a[j] - b[i][j] + 10) % 10;
                }else if (!pos2){
                    pos2 = j;
                    x2 = (a[j] - b[i][j] + 10) % 10;
                    if (pos2 - pos1 > 1 || x1 != x2)
                        return false;
                }else
                    return false;
            }
        }
        if (!pos1)
            return false;
    }
    return true;
}
int ans = 0;
void dfs(int depth){
    if (depth == 5){
        if (check()){
            ans++;
        }
        return;
    }
    for (int i = 0; i <= 9; i++){
        a[depth + 1] = i;
        dfs(depth + 1);
    }
}
int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 5; j++){
            cin >> b[i][j];
        }
    }
    dfs(0);
    cout << ans;
    return 0;
}