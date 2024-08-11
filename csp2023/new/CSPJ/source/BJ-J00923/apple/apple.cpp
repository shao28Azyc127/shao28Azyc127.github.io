#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int i, j, k;
    int n;
    cin >> n;
    int cs = 0;
    int ans = 0;
    while(n > 0)
    {
        k = (n - 1) / 3;
        if(ans == 0 && n == 1 + 3 * k)
        {
            ans = cs + 1;
        }
        n -= k + 1;
        cs++;
    }
    cout << cs << " " << ans << endl;
    return 0;
}
