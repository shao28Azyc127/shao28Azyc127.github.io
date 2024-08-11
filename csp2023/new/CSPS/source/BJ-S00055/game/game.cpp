

#include <iostream>
#include <stack>
#define ll long long

const int MAXN = 2e6+9;
using namespace std;

ll ans;
int N, stk[MAXN], tp;
char str[MAXN];

inline int chk (int l, int r) {
    tp = 0;
    for (int i = l; i < r+1; i++) {
        if (str[i] == str[stk[tp]]) tp--;
        else stk[++tp] = i;
    }
    return tp == 0;
}

int main () {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    
    cin >> N;
    for (int i = 1; i < N+1; i++) cin >> str[i];
    for (int i = 1; i < N+1; i++) {
        for (int j = i+1; j < N+1; j++) {
            ans += chk(i, j);
        }
    }
    cout << ans << '\n';

    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}