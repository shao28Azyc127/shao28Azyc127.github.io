#include <bits/stdc++.h>
using namespace std;
long long n, sum, ansn, xun, zhizhen;
bool p[1000000005];

long long xunzhao()
{
    for (int i = 1;i <= n;i++)
        if (p[i] == false)
            return i;
    return 0;
}

void zhao()
{
    for (int i = 1;i <= 2;i++)
    {
        while (1)
        {
            if (p[zhizhen] == true)
                ++zhizhen;
            else
                break;
        }
        ++zhizhen;
    }
    if (zhizhen == n)
        ansn = sum;
    p[zhizhen] = true;
}

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    while (1)
    {
        xun = xunzhao();
        if (xun == 0)
            break;
        ++sum;
        if (xun == n)
            ansn = sum;
        p[xun] = true;
        zhizhen = xun;
        while(1)
        {
            zhao();
            if (zhizhen + 3 > n)
                break;
        }
    }
    cout << sum << " " << ansn;
    return 0;
}






