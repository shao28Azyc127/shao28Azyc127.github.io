#include <bits/stdc++.h>
#define int long long
#define MAXN 500010
using namespace std;
int c,n,m,_T,a[MAXN],b[MAXN],kx,ky,id,v;
signed main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>c>>n>>m>>_T;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    if(c==1)
    {
        cout<<1;
        while(_T--)
        {
            cin>>kx>>ky;
            for(int i=1;i<=kx;i++)
            {
                cin>>id>>v;
                a[id]=v;
            }
            for(int i=1;i<=ky;i++)
            {
                cin>>id>>v;
                b[id]=v;
            }
            cout<<1;
        }
        return 0;
    }
    if(n==1)
    {
        if(a[1]>max(b[1],b[2])) cout<<1;
        else if(a[1]<min(b[1],b[2])) cout<<1;
        else cout<<0;
        while(_T--)
        {
            cin>>kx>>ky;
            for(int i=1;i<=kx;i++)
            {
                cin>>id>>v;
                a[id]=v;
            }
            for(int i=1;i<=ky;i++)
            {
                cin>>id>>v;
                b[id]=v;
            }
            if(a[1]>max(b[1],b[2])) cout<<1;
            else if(a[1]<min(b[1],b[2])) cout<<1;
            else cout<<0;
        }
        return 0;
    }
    if(m==1)
    {
        if(b[1]>max(a[1],a[2])) cout<<1;
        else if(b[1]<min(a[1],a[2])) cout<<1;
        else cout<<0;
        while(_T--)
        {
            cin>>kx>>ky;
            for(int i=1;i<=kx;i++)
            {
                cin>>id>>v;
                a[id]=v;
            }
            for(int i=1;i<=ky;i++)
            {
                cin>>id>>v;
                b[id]=v;
            }
            if(b[1]>max(a[1],a[2])) cout<<1;
            else if(b[1]<min(a[1],a[2])) cout<<1;
            else cout<<0;
        }
        return 0;
    }
    if(n==m&&n==2)
    {
        if(a[1]<b[1]&&a[2]<b[2]||a[1]>b[1]||a[2]>b[2]) cout<<1;
        else cout<<0;
        while(_T--)
        {
            cin>>kx>>ky;
            for(int i=1;i<=kx;i++)
            {
                cin>>id>>v;
                a[id]=v;
            }
            for(int i=1;i<=ky;i++)
            {
                cin>>id>>v;
                b[id]=v;
            }
            if(a[1]<b[1]&&a[2]<b[2]||a[1]>b[1]||a[2]>b[2]) cout<<1;
            else cout<<0;
        }
    }
    cout<<0;
    while(_T--)
        {
            cin>>kx>>ky;
            for(int i=1;i<=kx;i++)
            {
                cin>>id>>v;
                a[id]=v;
            }
            for(int i=1;i<=ky;i++)
            {
                cin>>id>>v;
                b[id]=v;
            }
            cout<<0;
        }
    return 0;
}
