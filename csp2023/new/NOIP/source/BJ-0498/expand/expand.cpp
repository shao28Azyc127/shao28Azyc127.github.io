#include <bits/stdc++.h>
using namespace std;
int c,n,m,q;
int x[2005],y[2005],a[2005],b[2005];
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
        a[i]=x[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>y[i];
        b[i]=y[i];
    }
    bool flag=0;
    if(a[1]<b[1])
    {
        flag=1;
    }
    bool f=0;
    int k=1;
    int la=0;
    for(int j=1;j<=n;j++)
    {
        f=0;
        int lb=la,lk=k;
        la=0;
        if(flag==0)
        {
            while(a[j]<=b[k]&&k>0)
            {
                k--;
            }
            if(k>=lk-lb)
            {
                f=1;
            }
            while(a[j]>b[k]&&k<=m)
            {
                k++;
                la++;
            }
        }
        else
        {
            while(a[j]>=b[k]&&k>0)
            {
                k--;
            }
            if(k>=lk-lb)
            {
                f=1;
            }
            while(a[j]<b[k]&&k<=m)
            {
                k++;
                la++;
            }
        }
        if(f==0)
        {
            //cout<<"8";
            cout<<0;
            break;
        }
    }
    if(f==1&&k<=m)
    {
        cout<<0;
        f=0;
    }
    if(f==1)
    {
        cout<<1;
    }
    for(int i=1;i<=q;i++)
    {
        int kx,ky;
        cin>>kx>>ky;
        for(int j=1;j<=n;j++)
        {
            a[i]=x[i];
        }
        for(int j=1;j<=m;j++)
        {
            b[i]=y[i];
        }
        for(int j=1;j<=kx;j++)
        {
            int p,v;
            cin>>p>>v;
            a[p]=v;
        }
        for(int j=1;j<=ky;j++)
        {
            int p,v;
            cin>>p>>v;
            b[p]=v;
        }
        bool flag=0;
        if(a[1]<b[1])
        {
            flag=1;
        }
        bool f=0;
        int la=0;
        for(int j=1;j<=n;j++)
        {
            f=0;
            int lb=la,lk=k;
            la=0;
            if(flag==0)
            {
                while(a[j]<=b[k]&&k>0)
                {
                    k--;
                }
                if(k>=lk-lb)
                {
                    f=1;
                }
                while(a[j]>b[k]&&k<=m)
                {
                    k++;
                    la++;
                }
            }
            else
            {
                while(a[j]>=b[k]&&k>0)
                {
                    k--;
                }
                if(k>=lk-lb)
                {
                    f=1;
                }
                while(a[j]<b[k]&&k<=m)
                {
                    k++;
                    la++;
                }
            }
            if(f==0)
            {
                cout<<0;
                break;
            }
        }
        if(f==1&&k<=m)
        {
            cout<<0;
            f=0;
            continue;
        }
        if(f==1)
        {
            cout<<1;
        }
    }
    return 0;
}
