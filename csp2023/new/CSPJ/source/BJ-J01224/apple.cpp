#include <iostream>
#include <cstring>
using namespace std;

int a[1000000005];

int main()
{
    int n;
    cin >> n;
    memset(a, 1, sizeof a);
    int cnt = 0, ans = 0, stop = n;
    while (stop != 0)
    {
        ++cnt;
        for (int i = 1; i <= n; i += 3)
        {
            if (n == i && ans == 0) ans = cnt;
            int x = 0;
            if (a[i] == 1)
            {
                if (x % 3 == 0)
                {
                    --stop;
                    x = 1;
                }
                else ++x;
            }
        }
    }
    cout << cnt << " " << ans << endl;
    return 0;
}
