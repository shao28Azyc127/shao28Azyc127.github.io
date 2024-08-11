#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int stk[8005],top;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n; cin >> n;
    string s; cin >> s; s = " " + s;
    int ans = 0;
    for(int i = 1;i <= n;i++){
        top = 0;
        for(int j = i;j <= n;j++){
            stk[++top] = s[j] - 'a' + 1;
            while(stk[top] == stk[top - 1] && top > 0) top -= 2;
            if(top == 0) ans++;
        }
    }
    cout << ans;
    return 0;
}