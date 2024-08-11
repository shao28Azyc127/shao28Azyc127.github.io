#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,a = 0,b = 0;
    cin>>n;
    if(n == 1 || (n - 1) % 3 == 0)
    {
        b = 1;
        a++;
    }
    while(n > 0)
    {
        if(n == 1 && a == 1)
        {
            break;
        }
        if(n >= 4)
        {
            if(n == 4)
            {
                n = 2;
                a++;
                b = a;
            }
            else
            {
                if((n-1) % 3 == 0)
                {
                    b = a;
                }
                n -= (n-1) / 3;
                a++;
                n--;
            }
        }
        else
        {
            a += n;
            break;
        }
    }
    if(b == 0)
    {
        b = a;
    }
    cout<<a<<" "<<b;
    return 0;
}