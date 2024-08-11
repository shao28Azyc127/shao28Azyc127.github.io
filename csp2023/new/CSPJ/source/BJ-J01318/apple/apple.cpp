#include <iostream>
#include <cstdio>
using namespace std;
int n;
bool a[1000000000];
bool abc()
{
    for(int i=0;i<=n;i++)
    {
        if(a[i])
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        a[i]=true;
    }
    int c=0;
    int d=0;
    bool m=true;
    while(abc())
    {
        c++;
        int b=2;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==true)
            {
                b++;
            }
            if(b==3)
            {
                b=0;
                a[i]=false;
            }
        }
        if(a[n]==false&&m)
        {
            d=c;
            m=false;
        }
    }
    cout<<c<<" "<<d;
    return 0;
}
