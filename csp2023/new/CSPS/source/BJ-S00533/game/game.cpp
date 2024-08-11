#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 50;
int n = 0;
int ans = 0;
string s;
bool check(string ss){
    int len = ss.length();
    if(len % 2 != 0){
        return false;
    }
    while(len){
        bool p = false;
        for(int j = 0;j < len - 1;j++){
            if(ss[j] == ss[j + 1]){
                p = true;
                for(int k = j + 2;k < n;k++){
                    ss[k - 2] = ss[k];
                }
                len -= 2;
            }
        }
        if(p == false){
            return false;
        }
    }
    return true;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n;
    cin >> s;
    for(int i = 0;i < n;i++){
        for(int j = i + 1;j < n;j++){
            string ss = "";
            for(int k = 0;k < j - i + 1;k++){
                ss += s[k + i];
            }
            if(check(ss) == true){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
