#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n, a[10][10], t[10], ans = 0, ans1 = 0;
void dfs(int u){
    if(u > 5){
        for(int i = 1; i <= n; i++){
            int cnt[10][2], k = 0;
            for(int j = 1; j <= 5; j++){
                if(a[i][j] != t[j]){
                    cnt[++k][0] = j;
                    cnt[k][1] = (a[i][j] - t[j]) > 0 ? (a[i][j] - t[j]) : (a[i][j] - t[j]) + 10;
                }
            }
            if(k > 2 && k == 0) return;
            else{
                if(k == 2){
                    if((cnt[2][0] - cnt[1][0] == 1) && (cnt[2][1] == cnt[1][1])){
                    } else {
                        return;
                    }
                } else if(k == 1){
                } else{
                    return;
                }
            }
        }
        ans++;
        return;
    }
    for(int i = 0; i <= 9; i++){
        t[u] = i;
        dfs(u + 1);
    }
}
int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 5; j++){
            cin >> a[i][j];
        }
    }
    dfs(1);
    cout <<ans;
    return 0;
}
