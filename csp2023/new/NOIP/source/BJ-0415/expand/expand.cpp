#include<bits/stdc++.h>
using namespace std;

int c,n,m,q;
int x[100010],y[100010];
int a[100010],b[100010];

int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin >> c >> n >> m >> q ;
    for(int i=1;i<=n;i++)
        cin >> x[i] ;
    for(int i=1;i<=m;i++)
        cin >> y[i] ;
    if(c==1)
    {
        if(x[1]!=y[1])
            for(int i=1;i<=q+1;i++)cout << 1;
        else
            for(int i=1;i<=q+1;i++)cout << 0;
        return 0 ;
    }
    int flag=1;
    for(int i=1;i<=min(m,n);i++)
    {
        if(x[i]>=y[i])
        {
            cout << 0 ;
            flag=0;
            break;
        }
    }
    if(flag)
        cout << 1 ;
    while(q--)
    {
        for(int i=1;i<=n;i++)
            a[i]=x[i];
        for(int i=1;i<=m;i++)
            b[i]=y[i];
        int kx,ky;
        cin >> kx >> ky ;
        for(int i=1;i<=kx;i++)
        {
            int p,d;
            cin >> p >> d ;
            a[p]=d;
        }
        for(int i=1;i<=ky;i++)
        {
            int p,d;
            cin >> p >> d ;
            b[p]=d;
        }
        flag=1;
        for(int i=1;i<=min(n,m);i++)
        {
            if(a[i]>=b[i])
            {
                cout << 0 ;
                flag=0;
                break;
            }
        }
        if(flag)
            cout << 1 ;
    }
    return 0 ;
}