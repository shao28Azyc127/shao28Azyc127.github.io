#include <iostream>
#include <cstdio>
using namespace std;
int c,n,m,q,x[500005],y[500005],mxx,mny=2e9;
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int i;
    cin>>c>>n>>m>>q;
    for(i=1;i<=n;i++)
    {
        cin>>x[i];
        mxx=max(mxx,x[i]);
    }
    for(i=1;i<=m;i++)
    {
        cin>>y[i];
        mny=min(mny,y[i]);
    }
    cout<<mxx<<" "<<endl;
    if(mxx>=y[m]||mny<=x[n]||(mxx>=y[1]&&mny<=x[1]))
        cout<<0;
    else
        cout<<1;
    while(q--)
    {
        int k1,k2,x1[500005],y1[500005];
        mxx=0;
        mny=2e9;
        for(i=1;i<=n;i++)
            x1[i]=x[i];
        for(i=1;i<=m;i++)
            y1[i]=y[i];
        for(i=1;i<=k1;i++)
        {
            int p,v;
            cin>>p>>v;
            x1[p]=v;
        }
        for(i=1;i<=k2;i++)
        {
            int p,v;
            cin>>p>>v;
            y1[p]=v;
        }
        for(i=1;i<=n;i++)
            mxx=max(mxx,x1[i]);
        for(i=1;i<=m;i++)
            mny=min(mny,y1[i]);
        if(mxx>=y1[m]||mny<=x1[n]||(mxx>=y1[1]&&mny<=x1[1]))
            cout<<0;
        else
            cout<<1;
    }
    return 0;
}
