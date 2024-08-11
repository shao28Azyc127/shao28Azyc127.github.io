#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    int t = n, cnt = 0, cnt2 = 0;
    while (t > 0)
    {
        cnt++;
        if (t % 3 == 1 && cnt2 == 0)
            cnt2 = cnt;
        int x = (t + 2) / 3;
        t -= x;
    }
    cout << cnt << " " << cnt2 << endl;
    return 0;
}
