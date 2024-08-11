#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 10;
int n,a[maxn][maxn],b[maxn],ans;
bool flag[maxn];
int d(int x,int y){
    return (x - y + 10) % 10;
}
void dfs(int x){
    if (x > 5){
        for (int i = 1;i <= n;i++){
            memset(flag,0,sizeof(flag));
            int cnt = 0;
            for (int j = 1;j <= 5;j++){
                if (a[i][j] != b[j]){
                    flag[j] = 1;
                    cnt++;
                }
            }
            if (cnt > 2 || cnt == 0) return;
            bool flag2 = true;
            if (cnt == 2){
                for (int j = 1;j <= 4;j++){
                    if (flag[j] && flag[j+1]){
                        if (d(a[i][j] , b[j]) != d(a[i][j + 1] , b[j+1])) return;
                        if (d(a[i][j] , b[j]) == 0) return;
                        flag2 = false;
                    }
                }
                if (flag2) return;
            }

        }
        ans++;
        return;
    }
    for (int i = 0;i <= 9;i++){
        b[x] = i;
        dfs(x + 1);
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++){
        for (int j = 1;j <= 5;j++){
            cin >> a[i][j];
        }
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}

