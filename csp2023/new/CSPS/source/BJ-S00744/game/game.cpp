#include <bits/stdc++.h>
using namespace std;

const int MAXN = 8005;
int n, tops, cnt;
string s;
string subs[MAXN*MAXN/2];

bool can_erase(string str){
    int len = str.length(), top = 0;
    char stk[len] = "";
    stk[top++] = str[0];
    for (int i = 1; i < len; i ++){
        if (str[i] == stk[top-1]){
            stk[--top] = 0;
        } else {
            stk[top++] = str[i];
        }
    }
    if (top == 0)
        return 1;

    return 0;
}

void make_sub() {
    for (int l = 0; l < n; l ++){
        for (int r = 1; r <= n-l; r ++){
            subs[tops++] = s.substr(l,r);
        }
    }

    return;
}

void cnts() {
    for (int i = 0; i < tops; i ++) {
        if (can_erase(subs[i]) == 1){
            cnt ++;
        }
    }

    return;
}

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n;
    cin >> s;

    make_sub();

    cnts();
    cout << cnt;
    return 0;
}
/*

*/
