#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

int main ()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int a,b,x;
    int minn=0;
    cin >> a >> b >> x;
    for(int i=1;i<=b;i++)
    {
        int q,w,e;
        cin >> q >> w >> e;
        minn=min(minn,e);
    }
    if(x*2<(minn+1)*2)x+=2;
    cout << x*2;
    return 0;
}
