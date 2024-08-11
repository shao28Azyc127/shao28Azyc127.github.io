#include <bits/stdc++.h>
using namespace std;
int suo[10][6];
int ans = 0,bh;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int num = 0;
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < 5;j++){
            cin >> suo[i][j];
        }
    }
    if(n == 1){
        cout << 81 << endl;
        return 0;
    }else{
        for(int i = 0;i < 5;i++){
            set<int> su;
            for(int j = 0;j < n;j++){
                su.insert(suo[j][i]);
            }
            int dj = su.size();
            //cout << i << ' ' << dj << endl;
            if(dj > ans){
                ans = dj;
                bh = 1;
            }else if(dj == ans){
                bh++;
            }
        }
        if(bh == 1){
            cout << 10 - ans << endl;
        }else{
            cout << 1 << endl;
        }
        //cout << 10 - ans << endl;
    }
    return 0;
}
