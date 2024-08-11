#include <bits/stdc++.h>
using namespace std;
int n;
char s[2000005];
stack<char> st;
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d%s", &n, s + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        while (!st.empty()) st.pop();
        for (int j = i; j <= n; j++)
        {
            if (!st.empty() && st.top() == s[j]) st.pop();
            else st.push(s[j]);
            if (st.empty()) ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
