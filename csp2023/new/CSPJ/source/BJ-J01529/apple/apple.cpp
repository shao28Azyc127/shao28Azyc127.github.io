#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int ans = 0;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    cin >> n;
    int i = 0;
    while (n > 0)
    {
        i ++;
        if (n % 3 == 1 && ans == 0)
            ans = i;
        if (n % 3 == 0)
            n -= n / 3;
        else
            n -= n / 3 + 1;
    }

    cout << i << ' ' << ans;
    return 0;
}
