#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,t = 0,a = 1e9;
    cin >> n;
    while(n > 0)
    {
        t++;
        if(n % 3 == 1)
        {
            a = min(a,t);
        }
        if(n % 3 != 2)
        {
            n = n / 3 * 2;
        }
        else{
            n = n / 3 * 2 + 1;
        }
    }
    cout << t << " " << a;
    return 0;
}
