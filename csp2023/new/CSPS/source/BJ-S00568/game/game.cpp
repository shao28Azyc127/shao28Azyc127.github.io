#include <iostream>
#include <string>
#include <stack>
#include <vector>
#define print1(x) cout << x << endl;
#define print2(x, y) cout << x << ' ' << y << endl;
#define print3(x, y, z) cout << x << ' ' << y << ' ' << z << endl;
using namespace std;

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n, CNT = 0;
    string s;
    cin >> n;
    cin >> s;
    //print2("ORI: ", s)
    for (int i = 0; i < n; i++) {
        int preSize = 0;
        for (int j = i + 1; j < n; j+=2) {
            if (preSize > 2) {
                continue;
            }
            stack<char> stk;
            for (int p = i; p <= j; p++) {
                //if (p == n - 1) break;
                if (stk.size() == 0) {
                    stk.push(s[p]);
                } else {
                    char top = stk.top();
                    if (s[p] == top) stk.pop();
                    else stk.push(s[p]);
                }
            }
            preSize = stk.size();
            if (stk.size() == 0) {
                // cout << s.substr(i, j - i + 1) << endl;
                // print2(i, j)
                CNT++;
            }
        }
    }
    cout << CNT << endl;
    return 0;
}