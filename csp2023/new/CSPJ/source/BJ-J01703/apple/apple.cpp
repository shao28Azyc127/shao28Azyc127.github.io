#include<bits/stdc++.h>
using namespace std;
int n,a[260000005],b[260000005];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    b[1] = 1;
    b[2] = 2;
    b[3] = 3;
    if (n <= 3)
    {
        cout << a[n] << " " << b[n];
    }
    else
    {
        for (int i = 4;i <= n;i++)
        {
            if (i % 3 == 0)
            {
                a[i] = a[i - i / 3] + 1;
                b[i] = b[i - i / 3] + 1;
            }
            else
            {
                a[i] = a[i - i / 3 - 1] + 1;
                if (i % 3 == 1)
                {
                    b[i] = 1;
                }
                else
                {
                    b[i] = b[i - i / 3 - 1] + 1;
                }
            }

        }
        cout << a[n] << " " << b[n];
    }
    return 0;
}