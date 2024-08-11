#include <iostream>
#include <algorithm>
using namespace std;
long long n,num,q = 1,sum,ans,cnt;
short a[1000000005];
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    num = n;
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
    while (num > 0)
    {
        for (int i = q; i <= n; i+=3)
        {
            a[i] = 0;
            num--;
            if ((a[n] == 0) && (cnt == 0))
            {
                ans = sum+1;
                cnt++;
            }
        }
        sum++;
        sort(a+1,a+n+1);
        for (int i = 1; i <= n; i++)
        {
            if (a[i]!=0)
            {
                q = i;
                break;
            }
        }
    }
    cout << sum << " " << ans << endl;
    return 0;
}
