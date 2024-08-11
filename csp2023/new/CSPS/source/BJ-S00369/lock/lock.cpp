#include <iostream>
using namespace std;
int n,a[10][6],now[6],dis[6],ans;
void dfs(int x){
    if(x == 5){
        bool flag = 1;
        for(int i = 1;i <= n;i++){
            int cnt = 0;
            for(int j = 1;j <= 5;j++){
                dis[j] = (a[i][j] + 10 - now[j]) % 10;
                if(dis[j] > 0) cnt++;
            }
            if(cnt > 2) flag = 0;
            else if(cnt == 2){
                flag = 0;
                for(int j = 1;j <= 4;j++){
                    if(dis[j] > 0 && dis[j + 1] > 0 && dis[j] == dis[j + 1]){
                        flag = 1;
                        break;
                    }
                }
            }
            else if(cnt == 0) flag = 0;
            if(!flag) break;
        }
        if(flag) ans++;
        return;
    }
    for(int i = 0;i <= 9;i++){
        now[x + 1] = i;
        dfs(x + 1);
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= 5;j++){
            cin >> a[i][j];
        }
    }
    dfs(0);
    cout << ans;
    return 0;
}