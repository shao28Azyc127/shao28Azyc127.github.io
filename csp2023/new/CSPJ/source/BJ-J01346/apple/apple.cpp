#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    int ans1 = 0;
    int m = n;
    while (n > 0) {
        ++ans1;
        n -= (n + 2) / 3;
    }
    int ans2 = 1;
    while (m % 3 != 1) {
        m -= (m + 2) / 3;
        ++ans2;
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
