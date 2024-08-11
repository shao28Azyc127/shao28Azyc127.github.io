#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2000005;
int n;
ll ans;
char s[N];

stack<char> stk;
ll solve(int l){
    ll res = 0;
    for (int i=l; i<=n; i++){
        if (!stk.empty() && stk.top() == s[i]) stk.pop();
        else stk.push(s[i]);
        if (stk.empty()) res++;
    }
    while (!stk.empty()) stk.pop();
    return res;
}

int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d%s", &n, s + 1);
    for (int l=1; l<n; l++) ans += solve(l);
    printf("%lld\n", ans);
    return 0;
}
