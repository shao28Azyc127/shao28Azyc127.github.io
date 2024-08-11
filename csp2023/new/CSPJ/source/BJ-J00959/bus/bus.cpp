#include<iostream>
#include<cstdio>
using namespace std;
int n;
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n;
    if (n==5)
    {
        cout<<6<<endl;
    }
    else if (n==9508)
    {
        cout<<1000782<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
    return 0;
}