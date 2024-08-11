#include<bits/stdc++.h>
using namespace std;
int n, k, ans, num = 1;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    k = n;
    while(n % 3 != 1)
    {
        num++;
        n -= ceil(n / 3.0);
    }
    while(k > 0)
    {
        ans++;
        k -= ceil(k / 3.0);
    }
    cout << ans << " " << num;
    return 0;
}
