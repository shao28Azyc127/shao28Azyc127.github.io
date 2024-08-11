#include <bits/stdc++.h>
using namespace std;

long long n, cnt1 = 0, cnt2 = 0, m;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    m = n;
    long long temp = n;


    while (m != 0)
    {
        for (long long i = 1; i <= temp; i++)
        {
            if (i % 3 == 1)
            {
                m--;
            }
        }
        temp = m;
        cnt1++;
    }

    cout << cnt1 << " ";

    m = n;
    temp = n;

    if (n % 3 == 1 || n == 1)
    {
        cout << 1;
        return 0;
    }

    else if (n == 2)
    {
        cout << 2;
        return 0;
    }

    else if (n == 3)
    {
        cout << 3;
        return 0;
    }

    else
    {
        while (m != 0)
        {
            for (long long i = 1; i <= temp; i++)
            {
                if (i % 3 == 1)
                {
                    m--;
                    if (i == temp)
                    {
                        cout << cnt2 + 1;
                        return 0;
                    }
                }
            }
            temp = m;
            cnt2++;
        }
    }

    return 0;
}

