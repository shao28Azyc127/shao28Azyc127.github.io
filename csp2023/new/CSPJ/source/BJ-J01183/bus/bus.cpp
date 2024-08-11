#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);

    int n,m,k;
    cin >> n >> m >> k;
    bool f=0,l=0;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        if(b==n)    f=1;
        if(a==1)    l=1;
    }
    if(f==0||l==0)    cout << "-1" << endl;
    else    cout << 2*k << endl;
    return 0;
}