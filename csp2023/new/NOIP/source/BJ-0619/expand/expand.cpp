#include<bits/stdc++.h>
using namespace std;
int c,n,m,q;
long long x[500005],y[500005],tx[500005],ty[500005];
int h,t;
int check()
{
    h=1;t=1;
    if(x[1]>y[1]&&x[n]>y[m])
    {
        while(h<=t&&h<=n&&t<=m)
        {
            if(x[h]>y[t])
            t++;
            if(x[h]<=y[t])
            h++;
            if(x[h+1]>y[t]&&h<t)
            h++;
        }
        if(t>=m)
        {
            for(int i=h;i<=n;i++)
            {
                if(x[i]<=y[m])
                {
                    return 0;
                }
            }
            return 1;
        }
        
    }
    if(x[1]<y[1]&&x[n]<y[m])
    {
        while(h<=t&&h<=m&&t<=n)
        {
            if(y[h]>x[t])
            t++;
            if(y[h]<=x[t])
            h++;
            if(y[h+1]>x[t]&&h<t)
            h++;
        }
        if(t>=n)
        {
            for(int i=h;i<=m;i++)
            {
                if(y[i]<=x[n])
                {
                    return 0;
                }
            }
            return 1;
        }
       
    }
    return 0;
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
        tx[i]=x[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>y[i];
        ty[i]=y[i];
    }
    cout<<check();
    for(int i=1;i<=q;i++)
    {
        for(int i=1;i<=n;i++)
        x[i]=tx[i];
        for(int i=1;i<=m;i++)
        y[i]=ty[i];
        int kx,ky;
        cin>>kx>>ky;
        for(int j=1;j<=kx;j++)
        {
            int p,v;
            cin>>p>>v;
            x[p]=v;
        }
        for(int j=1;j<=ky;j++)
        {
            int p,v;
            cin>>p>>v;
            y[p]=v;
        }
        //for(int i=1;i<=n;i++)
        //cout<<x[i];
        //cout<<endl;
    cout<<check();
    }
    return 0;
}
