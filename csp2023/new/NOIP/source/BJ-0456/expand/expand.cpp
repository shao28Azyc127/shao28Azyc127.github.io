#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
const int N = 5*100005;
int c,n,m,q,kx,ky,p,v;
int x[N],y[N];
int x1[N],y1[N];
int main()
{
    freopen("expand.in","r".stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i = 1;i <= n;++i) cin>>x[i];
    for(int i = 1;i <= m;++i) cin>>y[i];
    if(c == 1)
    {
        if(x[1] == y[1]) cout<<0;
        else cout<<1;
        while(q--)
        {
            for(int i = 1;i <= n;++i) x1[i] = x[i];
            for(int i = 1;i <= m;++i) y1[i] = y[i];
            cin>>kx>>ky;
            for(int i = 1;i <= kx;++i)
            {
                cin>>p>>v;
                x1[p] = v;
            }
            for(int i = 1;i <= ky;++i)
            {
                cin>>p>>v;
                y1[p] = v;
            }
            if(x1[1] == y1[1]) cout<<0;
            else cout<<1;
        }
        cout<<endl;
    }
    else if(c == 2)
    {
        if((x[1] < y[1]&&x[2] < y[2])||(x[1] > y[1]&&x[2] > y[2])) cout<<1;
        else cout<<0;
        while(q--)
        {
            for(int i = 1;i <= n;++i) x1[i] = x[i];
            for(int i = 1;i <= m;++i) y1[i] = y[i];
            cin>>kx>>ky;
            for(int i = 1;i <= kx;++i)
            {
                cin>>p>>v;
                x1[p] = v;
            }
            for(int i = 1;i <= ky;++i)
            {
                cin>>p>>v;
                y1[p] = v;
            }
            if((x1[1] < y1[1]&&x1[2] < y1[2])||(x1[1] > y1[1]&&x1[2] > y1[2])) cout<<1;
            else cout<<0;
        }
        cout<<endl;
    }
    return 0;
}
