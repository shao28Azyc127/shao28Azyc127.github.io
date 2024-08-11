#include<iostream>
using namespace std;
int n;
string str;
bool hw[8010][8010];
int ans;
int main (){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n >> str;
    for(int i = 1; i <= n; i ++){
        hw[i][i] = true;
    }
    for(int len = 2; len <= n; len += 2){
        for(int l = 1; l + len - 1 <= n; l ++){
            int r = l + len - 1;
            if(str[l - 1] == str[r - 1]){
                if(len == 2){
                    hw[l][r] = true;
                }
                else{
                    hw[l][r] = hw[l + 1][r - 1];
                }
            }
            if(len != 2){
                for(int k = l; k < r; k ++){
                    if(hw[l][k] && hw[k + 1][r]){
                       hw[l][r] = true;
                    }
                }
            }
        }
    }
    for(int len = 2; len <= n; len += 2){
        for(int l = 1; l + len - 1 <= n; l ++){
            int r = l + len - 1;
            if(hw[l][r]){
                ans ++;
            }
        }
    }
    cout << ans;
    return 0;
}