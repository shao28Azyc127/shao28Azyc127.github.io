#include <iostream>
#include <stdio.h>
using namespace std;
long long n;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin>>n;
    int dayy = 0;
    int ans = -1;
    bool f = true;
    while(n != 1)
    {
        if(f && (n - 1) % 3 == 0)
        {
            ans = dayy;
            f = false;
        }
        if(n % 3 == 0)
        {
            n = n - n / 3;
        }
        else if(n % 3 != 0)
        {
            n = n - ((n - (n % 3)) / 3 + 1);
        }
        dayy++;
    }
    dayy++;
    if(f)
    {
        ans = dayy;
    }
    if(ans == 0)
    {
        ans = 1;
    }
    cout<<dayy<<" "<<ans<<endl;
    return 0;
}
