#include <iostream>
#include <cstdio>
#define INF (int)(2e9)
#define MAXN 500050
using namespace std;
int testord,m,n,q;
int x[MAXN],y[MAXN];
int xt[MAXN],yt[MAXN];

void solve()
{
    if (testord==1)
    {
        if (xt[1]==yt[1]) cout<<0;
        else cout<<1;
    }
    else if (testord==2)
    {
        if ((xt[1]-yt[1])*(xt[2]-yt[2])>0) cout<<1;
        else cout<<0;
    }
    else
    {
        int minx=INF,miny=INF,maxx=-1,maxy=-1;
        int retx,rety;
        for (int i=1;i<=n;i++)
        {
            minx=min(minx,xt[i]);
            maxx=max(maxx,xt[i]);
        }
        for (int i=1;i<=m;i++)
        {
            miny=min(miny,yt[i]);
            maxy=max(maxy,yt[i]);
        }
        if ((xt[1]-yt[1])*(xt[n]-yt[m])<=0)
        {
            cout<<0;
            return ;
        }
        if (xt[1]-yt[1]>0)
            retx=maxx,rety=miny;
        else
            retx=minx,rety=maxy;
        for (int i=1;i<=n;i++)
        {
            if ((xt[1]-yt[1])*(xt[i]-rety)<=0 || (xt[1]-yt[1])*(retx-yt[i])<=0)
            {
                cout<<0;
                return ;
            }
        }
        cout<<1;
    }
}

int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int a,b,c,d;
    cin>>testord>>n>>m>>q;
    for (int i=1;i<=n;i++)
        cin>>x[i];
    for (int i=1;i<=m;i++)
        cin>>y[i];

    for (int i=1;i<=n;i++)
        xt[i]=x[i];
    for (int i=1;i<=n;i++)
        yt[i]=y[i];

    for (int i=0;i<=q;i++)
    {
        solve();
        for (int i=1;i<=n;i++)
            xt[i]=x[i];
        for (int i=1;i<=n;i++)
            yt[i]=y[i];
        if (i!=q)
        {
            cin>>a>>b;
            for (int j=1;j<=a;j++)
            {
                cin>>c>>d;
                xt[c]=d;
            }
            for (int j=1;j<=b;j++)
            {
                cin>>c>>d;
                yt[c]=d;
            }
        }
    }
    cout<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
