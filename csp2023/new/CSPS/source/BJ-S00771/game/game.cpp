#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
const int maxn = 8005;
int n,ans = 0;
string s;
bool vis[maxn];
int sum[maxn][30];
bool is(string x){
    if (x == "") return true;
    int l = x.size();
    memset(vis,0,sizeof(vis));
    string ret = "";
    bool flag = true;
    for (int i = 1;i < l;i++){
        if (x[i] == x[i-1] && (!vis[i-1])){
            vis[i] = 1;
            vis[i-1] = 1;
            flag = false;
        }
    }
    for (int i = 0;i < l;i++){
        if (vis[i]) continue;
        ret = ret + x[i];
    }
    if (flag) return false;
    return is(ret);
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n >> s;
    s = ' ' + s;
    for (int i = 1;i <= n;i++){
        for (int j = 0;j < 26;j++){
            sum[i][j] = sum[i-1][j];
        }
        sum[i][s[i] - 'a']++;
    }
    for (int i = 1;i <= n;i++){
        string t = "";
        for (int j = i+1;j <= n;j+=2){
            t = t + s[j-1] + s[j];
            bool flag = false;
            for (int k = 0;k < 26;k++){
                if ((sum[j][k] - sum[i-1][k]) % 2 == 1){
                    flag = true;
                    break;
                }
            }
            if (flag) continue;
            if (is(t)) ans++;
        }
    }
    cout << ans;
    return 0;
}
