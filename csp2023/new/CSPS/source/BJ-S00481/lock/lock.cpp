

#include <bits/stdc++.h>

using namespace std;

int n, ans, a[15][8], s[8];
bool b[8];
void dfs(int dep){
    if(dep > 5){
        bool chk = true;
        for(int i = 1; i <= n; i++){
            int u = 0;
            memset(b, 0, sizeof(b));
            for(int j = 1; j <= 5; j++){
                if(s[j] != a[i][j]) b[j] = true, u++;
            }
            if(u == 0){
                chk = false;
                break;
            }
            else if(u == 1) continue;
            if(u > 2){
                chk = false;
                break;
            }
            int pos = 0;
            for(int j = 1; j <= 5; j++){
                if(b[j] && !b[j - 1] && !b[j + 1]){
                    chk = false;
                    break;
                }
                if(b[j] && b[j + 1]) pos = j;
            }
            if(!chk) break;
            if((s[pos] - s[pos + 1] + 10) % 10 == (a[i][pos] - a[i][pos + 1] + 10) % 10) continue;
            else{
                chk = false;
                break;
            }
        }
        if(chk) ans++;
        return;
    }
    for(int i = 0; i <= 9; i++){
        s[dep] = i;
        dfs(dep + 1);
    }
}
int main (){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 5; j++){
            cin >> a[i][j];
        }
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}