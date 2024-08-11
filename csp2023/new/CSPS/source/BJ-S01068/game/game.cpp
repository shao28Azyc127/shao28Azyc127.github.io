#include <stack>
#include <iostream>
using namespace std;

int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;
    stack<char> stk;
    int ans = 0;
    for (int i = 0; i < n - 1; i++){
        while (!stk.empty()){
            stk.pop();
        }
        for (int j = i; j < n; j++){
            if (!stk.empty() && s[j] == stk.top()){
                stk.pop();
            } else {
                stk.push(s[j]);
            }
            if (stk.empty()){
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
