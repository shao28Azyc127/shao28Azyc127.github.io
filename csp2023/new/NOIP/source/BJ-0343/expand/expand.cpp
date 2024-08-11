#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N=5e5+5;

int c,n,m,q,x[N],y[N],X[N],Y[N],ans;

int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++)
        cin>>x[i];
    for(int i=1;i<=m;i++)
        cin>>y[i];
    if(c==1)
    {
        cout<<(x!=y);
        for(int i=1;i<=q;i++)
        {
            int kx,ky,p,v;
            cin>>kx>>ky;
            X[1]=x[1],Y[1]=y[1];
            for(int j=1;j<=kx;j++)
            {
                cin>>p>>v;
                X[1]=v;
            }
            for(int j=1;j<=ky;j++)
            {
                cin>>p>>v;
                Y[1]=v;
            }
            cout<<(X[1]!=Y[1]);
        }
    }
    else if(c==2)
    {
        if(n==2&&m==2)
        {
            cout<<((x[1]-y[1])*(x[2]-y[2])>0);
            for(int i=1;i<=q;i++)
            {
                int kx,ky,p,v;
                cin>>kx>>ky;
                for(int j=1;j<=n;j++)
                    X[j]=x[j];
                for(int j=1;j<=m;j++)
                    Y[j]=y[j];
                for(int j=1;j<=kx;j++)
                {
                    cin>>p>>v;
                    X[p]=v;
                }
                for(int j=1;j<=ky;j++)
                {
                    cin>>p>>v;
                    Y[p]=v;
                }
                cout<<((X[1]-Y[1])*(X[2]-Y[2])>0);
            }
        }
        else if(n==2&&m==1)
        {
            cout<<((x[1]-y[1])*(x[2]-y[1])>0);
            for(int i=1;i<=q;i++)
            {
                int kx,ky,p,v;
                cin>>kx>>ky;
                for(int j=1;j<=n;j++)
                    X[j]=x[j];
                for(int j=1;j<=m;j++)
                    Y[j]=y[j];
                for(int j=1;j<=kx;j++)
                {
                    cin>>p>>v;
                    X[p]=v;
                }
                for(int j=1;j<=ky;j++)
                {
                    cin>>p>>v;
                    Y[p]=v;
                }
                cout<<((X[1]-Y[1])*(X[2]-Y[1])>0);
            }
        }
        else
        {
            cout<<((x[1]-y[1])*(x[1]-y[2])>0);
            for(int i=1;i<=q;i++)
            {
                int kx,ky,p,v;
                cin>>kx>>ky;
                for(int j=1;j<=n;j++)
                    X[j]=x[j];
                for(int j=1;j<=m;j++)
                    Y[j]=y[j];
                for(int j=1;j<=kx;j++)
                {
                    cin>>p>>v;
                    X[p]=v;
                }
                for(int j=1;j<=ky;j++)
                {
                    cin>>p>>v;
                    Y[p]=v;
                }
                cout<<((X[1]-Y[1])*(X[1]-Y[2])>0);
            }
        }
    }
    else
    {
        cout<<((x[1]-y[1])*(x[n]-y[m])>0);
        for(int i=1;i<=q;i++)
        {
            int kx,ky,p,v;
            cin>>kx>>ky;
            for(int j=1;j<=n;j++)
                X[j]=x[j];
            for(int j=1;j<=m;j++)
                Y[j]=y[j];
            for(int j=1;j<=kx;j++)
            {
                cin>>p>>v;
                X[p]=v;
            }
            for(int j=1;j<=ky;j++)
            {
                cin>>p>>v;
                Y[p]=v;
            }
            cout<<((X[1]-Y[1])*(X[n]-Y[m])>0);
        }
    }
    return 0;
}
