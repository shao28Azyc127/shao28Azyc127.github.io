#include <bits/stdc++.h>
using namespace std;
int m, t, a, b, c, ans;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin >> t >> m;
    for (int i = 1;i <= t;i++)
    {
        cin >> a >> b >> c;
        int n = b * b - 4 * a * c;
        if (n >= 0)
            cout << max((-1 * b + sqrt(n)) / (2 * a), (-1 * b - sqrt(n)) / (2 * a)) << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}







