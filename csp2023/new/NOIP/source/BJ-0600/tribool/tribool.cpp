#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int c, t, n, m;
int main ()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    cin >> c >> t;
    while (t--)
    {
        int ans = 0;
        cin >> n >> m;
        while (m--)
        {
            char v;
            int a, b;
            cin >> v >> a;
            if (v=='U')
                ans++;
            else if (v=='+'||v=='-')
                cin>> b;
        }
        cout << ans <<endl;
    }
    return 0;
}
