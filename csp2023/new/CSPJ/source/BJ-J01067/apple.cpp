#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
#define int long long

signed main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    if(n <= 3)
    {
        cout << n << " " << n << endl;
        return 0;
    }
    int ans = 0, ans2 = 0;
    bool flag = false;
    for(int i = 1; ; i++)
    {
        ans++;
        if(n % 3 == 1 && flag == false)
        {
            ans2 = i;
            flag = true;
        }
        int tmp = ceil(1.0 * n / 3);
        n = n - tmp;
        if(n <= 0)
        {
            break;
        }
    }
    cout << ans << " " << ans2 << endl;
    return 0;
}
