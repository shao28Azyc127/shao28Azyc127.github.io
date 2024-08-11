#include<bits/stdc++.h>
using namespace std;
struct sta{
    int dif1 = 0;
    int dif2 = 0;
}diff[9][5];
int st[9][5];
int n;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> st[i][1] >> st[i][2] >> st[i][3] >> st[i][4] >> st[i][5];
    }
    int cnt = 0,ans,dc;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= 5;j++){
            if(st[i][j] != st[1][j]){
                if(st[i][j - 1] != st[1][j - 1]){
                    if(st[i][j - 2] != st[1][j - 2]){
                        diff[1][j].dif2++;
                    }
                }
                else{
                    diff[1][j].dif1++;
                }
            }
        }
    }
    for(int i = 1;i <= 5;i++){
        if(diff[1][i].dif2 != 0){
            cnt++;
            dc += 2;
            if(diff[1][i].dif1 != 0){
                cnt++;
                dc += 1;
            }
        }
        else if(diff[1][i].dif1 != 0){
            cnt++;
            dc += 1;
        }
    }
    if(cnt >= 2){
        ans = 0;
        cout << ans << endl;
        return 0;
    }
    cnt = 1;
    if(n == 1){
        int a[4][2];
        a[1][1] = st[1][1];
        a[1][2] = st[1][2];
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= 4;j++){
                if(st[1][i] == a[j][1] && st[1][i + 1] == a[j][2]){
                    continue;
                }
                cnt++;
                a[j][1] = st[1][i];
                a[j][2] = st[1][i + 1];
            }
        }
        ans = 45 + cnt * 9;
        cout << ans << endl;
        return 0;
    }
    cout << 10 - n << endl;
    return 0;
}
