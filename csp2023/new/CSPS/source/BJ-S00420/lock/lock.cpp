#include<bits/stdc++.h>
using namespace std;
typedef array<int, 5> pwd_t;
bool isok(pwd_t pwd1, pwd_t pwd2){
    int stat = 0;
    for(int i = 0; i < 5; i++){
        switch(stat){
            case 0:{
                if(pwd1[i] != pwd2[i]){
                    stat = 1;
                }
                break;
            }
            case 1:{
                if(pwd1[i] != pwd2[i] && (pwd1[i]+10-pwd2[i])%10 != (pwd1[i-1]+10-pwd2[i-1])%10){
                    return false;
                }
                stat=2;
                break;
            }
            case 2:{
                if(pwd1[i] != pwd2[i]){
                    return false;
                }
                break;
            }
        }
    }
    return stat != 0;
}
inline void read_pwd(pwd_t & pwd){
    for(int i = 0; i < 5; i++) cin >> pwd[i];
}
int n;
pwd_t pwd[10];
vector<pwd_t> ans;
int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++) read_pwd(pwd[i]);
    pwd_t & pwd_0 = pwd[0];
    for(int i = 0; i < 5; i++){
        for(int j = 0; j <= 9; j++){
            if(pwd_0[i] == j) continue;
            ans.push_back(pwd_0);
            ans.back()[i] = j;
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 1; j <= 9; j++){
            ans.push_back(pwd_0);
            ans.back()[i] += j;
            ans.back()[i] %= 10;
            ans.back()[i+1] += j;
            ans.back()[i+1] %= 10;
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < ans.size(); j++){
            if(ans[j][0] == -1) continue;
            if(isok(pwd[i], ans[j])) continue;
            ans[j][0] = -1;
        }
    }
    int cnt = 0;
    for(int j = 0; j < ans.size(); j++){
        if(ans[j][0] != -1) cnt++;
    }
    cout << cnt;
    return 0;
}
