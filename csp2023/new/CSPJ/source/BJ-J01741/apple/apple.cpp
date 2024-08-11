#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int m = n;
    int x,day = 0,day2 = 0;
    while(n != 0)
    {
        day++;
        n = n*2/3;
    }
    while(m != 0)
    {
        day2++;
        if(m % 3 == 1)
        {
            break;
        }
        m = m*2/3;
    }
    cout<<day<<" "<<day2;
    return 0;
}
