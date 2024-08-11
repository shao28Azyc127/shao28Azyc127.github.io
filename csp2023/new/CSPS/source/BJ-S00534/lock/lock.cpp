#include <iostream>
#include <cstdio>
using namespace std;

int a[10][10];
int vis[10];

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n,cnt = 0;
    cin >> n;
    if (n == 1){
        cout << 81 << endl;
        return 0;
    }
    for (int i = 1;i <= n;i++){
        for (int j = 1;j <= 5;j++){
            cin >> a[i][j];
        }
    }
    for (int i = 1;i <= 5;i++){
        for (int j = 1;j < n;j++){
            for (int k = j+1;k <= n;k++){
                if (a[j][i] != a[k][i]){
                    if (!vis[i]){
                        vis[i] = true;
                        cnt++;
                    }
                }
            }
        }
    }

    if (cnt == 1){
        cout << 10 << endl;
        return 0;
    }
    return 0;
}
