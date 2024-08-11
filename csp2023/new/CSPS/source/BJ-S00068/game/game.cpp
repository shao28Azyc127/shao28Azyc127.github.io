#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 8005;
int n, ans;
string s;
bool check(int l, int r){
    string now = " ";
    for(int i = l;i <= r;i++)now += s[i];
    int len = now.length() - 1;
    while(len){
        int pre = len;
        for(int i = 1;i < len;i++)
            if(now[i] == now[i + 1]){
                for(int j = i;j <= len - 2;j++)now[j] = now[j + 2];
                i = i - 1;
                len -= 2;
            }

        if(len == pre)return 0;
    }
    return 1;
}
void solve(){
    for(int l = 1;l <= n;l++)
        for(int r = l + 1;r <= n;r++)
            if(check(l, r))ans++;
}
int pre[N][30];
void solve1(){
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < 26;j++)
            pre[i][j] = pre[i - 1][j];
        pre[i][(int)(s[i] - 'a')]++;
    }
    for(int l = 1;l <= n;l++){
        for(int r = l + 1;r <= n;r++){
            bool flag = 0;
            for(int k = 0;k < 26;k++){
                if((pre[r][k] - pre[l - 1][k]) % 2){
                    flag = 1;
                    break;
                }
            }
            if(!flag)ans++;
        }
    }
}
signed main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    s = " " + s;
    if(n <= 10){
        solve();
    }else if(n <= 800){
        solve1();
    }else{
        for(int i = 1;i < n;i++){
            if(s[i] == s[i + 1])ans++;
        }
    }
    cout << ans;
    return 0;
}
