#include<bits/stdc++.h>
using namespace std;
int x[100],y[100];
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c,n,m,q;
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++)
        cin>>x[i];
    for(int i=1;i<=m;i++)
        cin>>y[i];
    if(c==1||n==1&&m==1)
    {
        if(x[1]!=y[1])
            cout<<1;
        else
            cout<<0;
    }
    else if(c==2)
    {
        if(n==1&&m==2)
        {
            if((x[1]>y[1]&&x[1]>y[2])||(x[1]<y[1]&&x[1]<y[2]))
                cout<<1;
            else
                cout<<0;
        }
        else if(n==2&&m==1)
        {
            if((y[1]>x[1]&&y[1]>x[2])||(y[1]<x[1]&&y[1]<x[2]))
                cout<<1;
            else
                cout<<0;
        }
        else
        {
            if((x[1]>y[1])&&(x[2]>y[2])||(x[1]<y[1])&&(x[2]<y[2]))
                cout<<1;
            else
                cout<<0;
        }
    }
    int kx,ky,u,v;
    for(int i=1;i<=q;i++)
    {
        cin>>kx>>ky;
        for(int j=1;j<=kx;j++)
        {
            cin>>u>>v;
            x[u]=v;
        }
        for(int j=1;j<=ky;j++)
        {
            cin>>u>>v;
            y[u]=v;
        }
        if(c==1||n==1&&m==1)
    {
        if(x[1]!=y[1])
            cout<<1;
        else
            cout<<0;
    }
    else if(c==2)
    {
        if(n==1&&m==2)
        {
            if((x[1]>y[1]&&x[1]>y[2])||(x[1]<y[1]&&x[1]<y[2]))
                cout<<1;
            else
                cout<<0;
        }
        else if(n==2&&m==1)
        {
            if((y[1]>x[1]&&y[1]>x[2])||(y[1]<x[1]&&y[1]<x[2]))
                cout<<1;
            else
                cout<<0;
        }
        else
        {
            if((x[1]>y[1])&&(x[2]>y[2])||(x[1]<y[1])&&(x[2]<y[2]))
                cout<<1;
            else
                cout<<0;
        }
    }
    }
    return 0;
}