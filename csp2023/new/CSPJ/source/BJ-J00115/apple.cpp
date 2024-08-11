#include <bits/stdc++.h>
using namespace std;
queue <int> q;
int n, d, o, x, s, ans;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    while (! q.empty())
    {
        d++;
        s = q.size();
        for (int i = 1; i <= s; i++)
        {
            x = q.front();
            q.pop();
            if (i % 3 != 1)
            {
                q.push(x);
            }
            else if (x == n)
            {
                ans = d;
            }
        }
    }
    cout << d << " " << ans;
}