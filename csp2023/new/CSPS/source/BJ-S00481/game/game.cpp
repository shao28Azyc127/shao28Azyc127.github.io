

#include <bits/stdc++.h>

using namespace std;

int n, ans, top;
char s[1000010];
string str;
int main (){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n;
    cin >> str;
    str = " " + str;
    for(int i = 1; i <= n; i++){
        top = 1;
        s[top] = str[i];
        for(int j = i + 1; j <= n; j++){
            if(top != 0 && str[j] == s[top]) top--;
            else s[++top] = str[j];
            if(top == 0) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}