#include <iostream>
#include <stack>
using namespace std;
int n, ans;
string s;
int solve(int l, int r)
{
    stack<char> st;
    int ans = 0;
    for (int i = l; i <= r; i++)
    {
        if (!st.empty() && st.top() == s[i]) st.pop();
        else st.push(s[i]);
        if (st.size() == 0) ans++;
    }
    return ans;
}
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        ans += solve(i, n - 1);
    cout << ans << '\n';
    return 0;
}
