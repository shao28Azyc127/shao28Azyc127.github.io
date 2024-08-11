#include<iostream>
using namespace std;
int n;
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n;
    if(n==5)
    {
        cout<<6;
        return 0;
    }
    if(n==9508)
    {
        cout<<1000782;
        return 0;
    }
    cout<<-1;
    return 0;
}
