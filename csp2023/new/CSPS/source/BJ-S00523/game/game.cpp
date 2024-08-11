#include <bits/stdc++.h>
#define MP make_pair
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
int n;
string s;
stack<char> stk;
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s, s = ' ' + s;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        stk = stack<char>();
        for (int j = i; j <= n; j++)
        {
            if (!stk.empty() && stk.top() == s[j])
                stk.pop();
            else
                stk.emplace(s[j]);
            ans += stk.empty();
        }
    }
    cout << ans << '\n';
    return 0;
}