#include <iostream>
using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin >> n;
    int a[n + 10];
    for (int i = 1;i <= n;i++)
    {
        a[i] = i;
    }
    int cishu = 0,cur = 0,cnt = n;
    int ans2 = 0;
    bool first = true;
    while (cnt > 0)
    {
        cishu++;
        for (int i = 1;i <= n;i++)
        {
            if (a[i] != 0)
            {
                if (cur == 2 || first)
                {
                    a[i] = 0;
                    first = false;
                    cnt--;
                    if (i == n)
                    {
                        ans2 = cishu;
                    }
                    cur = 0;
                    continue;
                }
                cur++;
            }
        }
        cur = 0;
        first = true;
    }
    cout << cishu << " " << ans2;
    return 0;
}
