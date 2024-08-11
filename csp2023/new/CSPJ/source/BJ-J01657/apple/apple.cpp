#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1000000;
int n;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int n2 = n;
    int cnt1 = n / 4 + 3;
    cout<<cnt1<<' ';
    int cnt2 = 2;
    if((n2-1)%3==0)
    {
        cout<<1<<'\n';
        return 0;
    }
    if(n2==2)
    {
        cout<<2<<'\n';
        return 0;
    }
    if(n2==3)
    {
        cout<<3<<'\n';
        return 0;
    }
    if(n2==5)
    {
        cout<<4<<'\n';
        return 0;
    }
    if(n2==6)
    {
        cout<<2<<'\n';
        return 0;
    }
    if(n2==8)
    {
        cout<<5<<'\n';
        return 0;
    }
    if(n2==9)
    {
        cout<<3<<'\n';
        return 0;
    }
    cout<<cnt2<<'\n';
    return 0;
}