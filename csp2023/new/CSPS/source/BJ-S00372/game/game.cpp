#include <bits/stdc++.h>
#define ll long long
#define MAXN 20005
using namespace std;
int n, ans;
int val[MAXN];
int solve(int l, int r) {
    int flag = false;
    int stk[MAXN] = {}, top = 0;
    int meijia = 0;
    int jump[MAXN] = {l}, jumpcnt = 1;
    for (int i = l; i <= r; i++) {
        if (stk[top] == val[i]) {
            cout << "#!" << i << endl;
            top--;
            meijia++;
            if (i == r && jumpcnt != 1) {
                ans++;
            }
            if (top == 0 && !(i == r && jumpcnt == 1)) {
                flag++;
                for (int j = 1; j <= jumpcnt; j++) {
                    solve(jump[j], i);
                }
                jump[++jumpcnt] = i + 1;
            }
            continue;
        }
        stk[++top] = val[i];
    }
    if (!flag) {
        ans += meijia;
    }
}
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++) {
        char c;
        scanf("%c", &val[i]);
    }
    solve(1, n);
    cout << ans;
    return 0;
}


