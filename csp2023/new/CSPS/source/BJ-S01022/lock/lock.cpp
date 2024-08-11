#include <iostream>
#include <cstdio>

using namespace std;
int n;
int a[10][10];

int vis[10];
int ans = 0;
bool check(){
    for(int i = 1; i <= n; i++){
        bool flag = true;
        int cnt = 0;
        int first_false = 0;
        for(int j = 1; j <= 5; j++){
            if(vis[j] != a[i][j]){
                if(flag == true){
                    first_false = j;
                }else{
                    if(first_false != j - 1){
                        return false;
                    }
                }
                flag = false;
                cnt++;
            }
        }
        if(flag){
            return false;
        }
        if(cnt >= 3){
            return false;
        }
        if(cnt == 1){
            continue;
        }
        int cha1, cha2;
        int x1 = a[i][first_false], x2 = vis[first_false];
        int y1 = a[i][first_false + 1], y2 = vis[first_false + 1];
        if(x1 < x2){
            cha1 = x2 - x1;
        }else{
            cha1 = (x2 + 10) - x1;
        }
        if(y1 < y2){
            cha2 = y2 - y1;
        }else{
            cha2 = (y2 + 10) - y1;
        }
        if(cha1 != cha2){
            return false;
        }
    }
    return true;
}
void dfs(int x){
    if(x > 5){
        if(check()){
           // for(int i = 1; i <= 5; i++){
                //cout << vis[i] << ' ';
            //}
           // cout << endl;
            ans ++;
        }
        return;
    }
    for(int i = 0; i <= 9; i++){
        vis[x] = i;
        dfs(x + 1);
    }
}
int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 5; j++){
            cin >> a[i][j];
        }
    }
   // if(n == 1){
    //    cout << 9 * (5 + 4) << endl;
    //}else if(n == 2){
      //  cout << 10
    //}
    dfs(1);
    cout <<ans <<endl;
    return 0;
}
