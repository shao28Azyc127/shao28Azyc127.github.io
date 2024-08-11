#include <iostream>
using namespace std;
int n,a[100010],b[100010],c[100010],atti[100010] = {},t = 1,grap[100010][100010] = {};
void dfs(int day){
    t = 1;
    for(int i = 0;i < n;i++){
        if(atti[i] < a[i]) t = 0;
    }
    if(t == 1){
        cout << day - 1 << endl;
        return ;
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(atti[i] != 0 && grap[i][j] != 0){
                atti[j] += max(b[j] + day * c[i],1);
                dfs(day + 1);
                atti[j] -= max(b[j] + day * c[i],1);
            }
        }
    }
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    for(int i = 0;i < n - 1;i++){
        int x,y;
        cin >> x >> y;
        grap[x][y] = 1;
    }
    atti[0] = -1;
    grap[0][1] = 1;
    dfs(1);
    return 0;
}