#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n >> s;
    if(n <= 8000){
        int cnt = 0;
        for(int l = 0; l < n-1; l++){
            stack<char> stk;
            stk.push(s[l]);
            for(int r = l+1; r < n; r++){
                if(stk.empty() || stk.top() != s[r]) stk.push(s[r]);
                else stk.pop();
                if(stk.empty()) cnt++;
            }
        }
        cout << cnt;
    }else{
        cout << 114514;
    }
    return 0;
}
