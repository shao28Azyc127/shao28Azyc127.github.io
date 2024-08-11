#include <iostream>
#include <cstdio>

using namespace std;


int main()
{
    int n,f=0,g=0,h=1;
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    g=n;
    while(g!=0)
    {
        if(g>=3)g=g-g/3-(g==3*(g/3)+1)-(g==3*(g/3)+2);
        else g-=1;
        f++;
    }
    h=1;
    while((n+2)%3!=0)
    {
        n-=n/3+(n%3>=1);
        h+=1;
    }
    cout<<f<<" "<<h;
    return 0;
}
