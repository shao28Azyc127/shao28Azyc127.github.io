#include <bits/stdc++.h>
using namespace std;
int n,top;
string s;
long long cnt;
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n;
    cin >> s;
    for (int j = 0; j < n ; j++) {
        for (int i = j + 1; i < n ; i++){
                char st[500001];
                top = 0;
                for (int k = j;k <= i;k++) {
                    st[top] = s[k];
                    if (st[top] ==  st[top - 1]) {
                        top -= 2;
                    }
                    top++;
                }
            if (top == 0) cnt++;
        }
    }
    cout << cnt;
    return 0;
}