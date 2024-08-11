#include <bits/stdc++.h>
using namespace std;

int max_(int* a,int len)
{
    int mm=0;
    for(int i=0;i<len;i++)
    {
        mm=max(mm,a[i]);
    }
    return mm;
}

int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);

    int c,n,m,q;
    scanf("%d%d%d%d",&c,&n,&m,&q);
    int x[n]={0};
    int y[m]={0};
    int cx[n],cy[m];

    for(int i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }

    for(int i=0;i<m;i++)
    {
        scanf("%d",&y[i]);
    }

    if(x[0]<=y[0]||x[n-1]<=y[m-1])
    {
        cout<<0;
    }
    else
    {
        cout<<1;
    }

    int kx,ky;
    int p,v;

    while(q--)
    {
        for(int i=0;i<n;i++)
        {
            cx[i]=x[i];
        }
        for(int i=0;i<m;i++)
        {
            cy[i]=y[i];
        }

        scanf("%d%d",&kx,&ky);
        while(kx--)
        {
            scanf("%d%d",&p,&v);
            p--;
            cx[p]=v;
        }
        while(ky--)
        {
            scanf("%d%d",&p,&v);
            p--;
            cy[p]=v;
        }
/*
        for(int i=0;i<n;i++)
        {
            cout<<cx[i];
        }
        cout<<endl;
        for(int i=0;i<m;i++)
        {
            cout<<cy[i];
        }cout<<endl<<endl;*/

        if(cx[0]<=cy[0]||cx[n-1]<=cy[m-1])
        {
            cout<<0;
        }
        else if(max_(cx,n)<=max_(cy,m))
        {
            cout<<0;
        }
        else
        {
            cout<<1;
        }
    }

    return 0;
}
