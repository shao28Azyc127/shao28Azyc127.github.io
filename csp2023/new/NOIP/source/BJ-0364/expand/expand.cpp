#include <bits/stdc++.h>
using namespace std;

int cmp(int x1,int x2,int y1,int y2)
{
    if(x1>y1 &&x2>y2)
        return 1;
    if(x1<y1 &&x2<y2)
        return 1;
    return 0;
}

int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c,n,m,q;
    cin>>c>>n>>m>>q;
    if(c==1 ||(n==1 &&m==1))
    {
        int x,y;
        cin>>x>>y;
        if(x==y)
            cout<<0;
        else
            cout<<1;
        for(int i=1;i<=q;i++)
        {
            int kx,ky,q;
            cin>>kx>>ky;
            for(int j=1;j<=kx;j++)
                cin>>q>>x;
            for(int j=1;j<=ky;j++)
                cin>>q>>y;
            if(x==y)
                cout<<0;
            else
                cout<<1;
        }
        return 0;
    }
    if(n==2 && m==2)
    {
        int x1,x2,y1,y2;
        cin>>x1>>x2>>y1>>y2;
        cout<<cmp(x1,x2,y1,y2);
        for(int i=1;i<=q;i++)
        {
            int kx,ky,q;
            cin>>kx>>ky;
            for(int j=1;j<=kx;j++)
            {
                cin>>q;
                if(q==1)
                    cin>>x1;
                if(q==2)
                    cin>>x2;
            }
            for(int j=1;j<=ky;j++)
            {
                cin>>q;
                if(q==1)
                    cin>>y1;
                if(q==2)
                    cin>>y2;
            }
            cout<<cmp(x1,x2,y1,y2);
        }
        return 0;
    }
    if(n==1 && m==2)
    {
        int x1,y1,y2;
        cin>>x1>>y1>>y2;
        if(x1<min(y1,y2) ||x1>max(y1,y2))
            cout<<1;
        else
            cout<<0;
        for(int i=1;i<=q;i++)
        {
            int kx,ky,q;
            cin>>kx>>ky;
            for(int j=1;j<=kx;j++)
            {
                cin>>q;
                cin>>x1;
            }
            for(int j=1;j<=ky;j++)
            {
                cin>>q;
                if(q==1)
                    cin>>y1;
                if(q==2)
                    cin>>y2;
            }
            if(x1<min(y1,y2) ||x1>max(y1,y2))
                cout<<1;
            else
                cout<<0;
        }
        return 0;
    }
    if(n==2 && m==1)
    {
        int x1,x2,y1;
        cin>>x1>>x2>>y1;
        if(y1<min(x1,x2) ||y1>max(x1,x2))
            cout<<1;
        else
            cout<<0;
        for(int i=1;i<=q;i++)
        {
            int kx,ky,q;
            cin>>kx>>ky;
            for(int j=1;j<=kx;j++)
            {
                cin>>q;
                if(q==1)
                    cin>>x1;
                if(q==2)
                    cin>>x2;
            }
            for(int j=1;j<=ky;j++)
            {
                cin>>q;
                cin>>y1;
            }
            if(y1<min(x1,x2) ||y1>max(x1,x2))
                cout<<1;
            else
                cout<<0;
        }
        return 0;
    }
    return 0;
}

