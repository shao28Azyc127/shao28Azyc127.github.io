#include <iostream>
#include <string>
#include <cstring>
using namespace std;

char c[2000005];
bool vis[2000005];

bool check(int l,int r){
    for (int i = l;i <= r;i++){
        if (vis[i] == false){
            return false;
        }
    }
    return true;
}

bool f(int l,int r){
    memset(vis,false,sizeof(vis));
    while(true){
        a:
        bool flag = false;
        for (int i = l;i < r;i++){
            if (!vis[i]){
                for (int j = i+1;j <= r;j++){
                    if (!vis[j] && c[i] == c[j]){
                        flag = true;
                        vis[i] = true;
                        vis[j] = true;
                        goto a;
                    }
                }
            }
        }
        if (check(l,r)){
            return true;
        }
        if (!flag && !check(l,r)) return false;
    }
}

int main () {
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n,cnt = 0;
    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> c[i];
    }
    for (int l = 1;l < n;l++){
        for (int r = l+1;r <= n;r++){
            if (f(l,r)){
                cnt++;
                //cout <<l <<" " <<r <<endl;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
