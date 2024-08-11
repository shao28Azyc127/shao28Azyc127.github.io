#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll ans1, ans2 = 1e9 + 5;
void f(ll x){
//    cout << x << "\n";
    if(x == 0)return;
    ans1 ++;
    if(x % 3 == 1){
        ans2 = min(ans2, ans1);
    }
    if(x % 3 == 0)f(x - (x / 3));
    else f(x - (x / 3 + 1));
}
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    ll n;
    cin >> n;
    f(n);
    cout << ans1 << " " << ans2;
    return 0;
}