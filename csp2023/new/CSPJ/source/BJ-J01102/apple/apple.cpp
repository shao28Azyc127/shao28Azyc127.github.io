#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,g2=0,c=0;
    cin>>n;
    while(n)
    {
        c++;
        if(n%3==1&&g2==0)
            g2=c;
        if(n%3==0)
            n-=n/3;
        else
            n-=n/3+1;
    }
    cout<<c<<' '<<g2;
    return 0;
}
