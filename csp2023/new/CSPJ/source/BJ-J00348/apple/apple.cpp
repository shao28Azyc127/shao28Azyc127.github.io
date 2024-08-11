#include<bits/stdc++.h>
using namespace std;
int cnt = 0,day = 0,t;
long long d,n;
int main()
{
    freopen("apple1.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    t = n;
    if(t % 3 == 1)
    {
        day = 1;
    }
    while(n > 0)
    {
        d = n / 3;
        n = n - d;
    }
    if(t % 3 == 2)
    {
        day = cnt;
    }
    cout<<cnt<<" " <<day;
    return 0;
}