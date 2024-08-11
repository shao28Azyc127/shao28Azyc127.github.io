#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
typedef long long ll;
ll n;
string str;
stack<char> st;
bool check(ll l, ll r) {
    while (!st.empty()) st.pop();
    for (register ll i = l; i <= r; i++) {
        if (!st.empty() && st.top() == str[i]) st.pop();
        else st.push(str[i]);
    }
    return st.empty();
}
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> n >> str;
    str = ' ' + str;
    ll ans = 0;
    for (register ll i = 1; i < n; i++) {
        for (register ll j = i + 1; j <= n; j++) {
            if (check(i, j)) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
