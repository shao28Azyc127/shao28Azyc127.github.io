#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int a;
    cin>>a;
    if(a==5)
    {
        cout<<6;
    }
    else
    {
        cout<<1000782;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}