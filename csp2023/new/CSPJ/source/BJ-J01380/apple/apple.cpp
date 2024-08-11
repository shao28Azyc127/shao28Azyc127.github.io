#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f(ll x, ll y){
    if(x % y == 0) return x/y;
    else return (x/y) + 1;
}
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.ans", "w", stdout);
    ll n;
    scanf("%d", &n);
    ll cnt = 0;
    ll cur;
    ll ans = 0;
    ll ans2 = 0;
    if(n % 2 == 1) ans2 = 1;
    for(ll i = n; i;){
        cur = f(i, 3);
        ans ++;
        i -= cur;
    }
    for(ll i = 1; n; i ++){
        if(n % 3 == 1){
            ans2 = i;
            break;
        }
        n -= f(n, 3);
    }
    printf("%d %d", ans, ans2);
    return 0;
}