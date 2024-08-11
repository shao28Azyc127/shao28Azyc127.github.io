#include <iostream>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,cnt = 0;
    cin >> n;
    int t = n;
    bool f = 0;
    int ans;
    while (n > 0)
    {
        cnt++;
        n -= t / 3;
        if (t % 3 != 0) n--;
        if (t % 3 == 1 && !f)
        {
            ans = cnt;
            f = 1;
        }
        t = n;
    }
    cout << cnt << " " << ans;
    return 0;
}