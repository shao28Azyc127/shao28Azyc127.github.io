#include <bits/stdc++.h>
using namespace std;

int a[100001] , w[100001];

int main()
{
    freopen("road.in" , "r" , stdin);
    freopen("road.out" , "w" , stdout);
    int n , d , sum = 0 , minn = 100001 , ans = 0;
    cin >> n >> d;
    for (int i = 1;i <= n - 1;i++)
    {
        cin >> w[i];
        sum += w[i];
    }
    for (int i = 1;i <= n - 1;i++)
    {
        cin >> a[i];
        minn = min(minn , a[i]);
    }
    cin >> a[n];
    int now = 0;
    for (int i = 1;i <= n - 1;i++)
    {
        if(a[i] == minn)
        {
            int temp = sum - now * d;
            if(temp % d == 0)
                cout << temp / d * minn + ans << endl;
            else
                cout << temp / d * minn + minn + ans << endl;
            return 0;
        }
        else
        {
            int temp = w[i] - now * d;
            if(temp % d == 0)
            {
                ans += temp / d * a[i];
                sum -= temp / d;
            }
            else
            {
                ans += temp / d * a[i] + a[i];
                sum -= temp / d + d;
            }
        }
    }
    cout << ans << endl;
    return 0;
}