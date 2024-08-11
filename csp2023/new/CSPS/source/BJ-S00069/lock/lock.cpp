#include<bits/stdc++.h>
using namespace std;

int n;
int stt[10][7], pos[100][7];
bool flg[100];

int trans(int a){
    while(a < 0){
        a += 10;
    }
    while(a > 9){
        a -= 10;
    }
    return a;
}
bool good(int s, int p){
    int cnt = 0;
    // only one number?
    for(int i = 1; i <= 5; i++){
        if(stt[s][i] != pos[p][i]){
            cnt++;
        }
    }
    if(cnt == 1) return true;
    if(cnt > 2 || cnt == 0) return false;
    // 2 numbers together?
    for(int i = 1; i <= 4; i++){
        if(stt[s][i] != pos[p][i]){
            int tmp1 = stt[s][i] - pos[p][i], tmp2;
            if(tmp1 > 0){
                tmp2 = stt[s][i + 1] - pos[p][i + 1];
                if(tmp2 == tmp1){
                    return true;
                }
                if(tmp2 < 0 && tmp2 + 10 == tmp1){
                    return true;
                }
            }else if(tmp1 < 0){
                tmp2 = stt[s][i + 1] - pos[p][i + 1];
                if(tmp2 == tmp1){
                    return true;
                }
                if(tmp2 > 0 && tmp2 - 10 == tmp1){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    for(int i = 1; i <= 81; i++){
        flg[i] = true;
    }
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 5; j++){
            cin >> stt[i][j];
        }
    }
    // use the first stt to generate all possible codes.
    for(int i = 1; i <= 90; i++){
        for(int j = 1; j <= 5; j++){
            pos[i][j] = stt[1][j];
        }
    }
    int cur = 0;
    // change one number.
    for(int i = 1; i <= 5; i++){
        for(int j = 0; j <= 9; j++){
            if(j == stt[1][i]){
                continue;
            }
            cur++;
            pos[cur][i] = j;
        }
    }
    // change 2 numbers.
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= 9; j++){
            cur++;
            pos[cur][i] = trans(pos[cur][i] - j);
            pos[cur][i + 1] = trans(pos[cur][i + 1] - j);
        }
    }
    // compare.
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= 81; j++){
            if(flg[j]){
                if(!good(i, j)){
                    flg[j] = false;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= 81; i++){
        if(flg[i]){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
