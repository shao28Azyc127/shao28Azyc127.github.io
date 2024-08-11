#include<bits/stdc++.h>
#pragma GCC(2)
using namespace std;
int n , day = 0 , date = 0  , tmp;
int main()
{
    freopen("apple.in" , "r" , stdin);
    freopen("apple.out"  , "w" , stdout);
    cin >> n;
    tmp = n;
    while(tmp)
    {
        day++;
        tmp -= (tmp - 1) / 3 + 1;
    }
    while(n)
    {
        date++;
        if(n%3==1)
        {
            break;
        }
        else
        {
            n -= (n - 1) / 3 + 1;
        }
    }
    cout << day << ' ' << date;
    return 0;
}