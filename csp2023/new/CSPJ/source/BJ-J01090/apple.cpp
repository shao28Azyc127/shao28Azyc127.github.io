#include <bits/stdc++.h>
using namespace std;
int n,a,b;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n)
    {
        if((n%3==1)&&(b==0))
        {
            b=a+1;
        }
        n-=(n+2)/3;
        a++;
    }
    cout<<a<<" "<<b;
    return 0;
}
