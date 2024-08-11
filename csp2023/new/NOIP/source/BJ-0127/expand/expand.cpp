#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int x[N],y[N],cinx[N],ciny[N];
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c,m,n,q;
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++) cin>>cinx[i],x[i]=cinx[i];
    for(int j=1;j<=m;j++) cin>>ciny[j],y[j]=ciny[j];
    int l=1;
    bool fl=0;
    for(int i=1;i<=m;i++)
        for(;l<=n;l++) if(x[l]<=y[i]) break;
    if(l==n) fl=1;
    else
    {
        l=1;
        for(int i=1;i<=m;i++)
            for(;l<=n;l++) if(x[l]>=y[i]) break;
    }
    if(l==n) fl=1;
    cout<<fl;
    while(q--)
    {
        for(int i=1;i<=n;i++) x[i]=cinx[i];
        for(int i=1;i<=m;i++) y[i]=ciny[i];
        int kkx=0,kky=0;
        cin>>kkx>>kky;
        for(int i=1;i<=kkx;i++)
        {
            int pos,c;
            x[pos]=c;
        }
        for(int i=1;i<=kky;i++)
        {
            int pos,c;
            y[pos]=c;
        }

        int l=1;
        bool fl=0;
        for(int i=1;i<=m;i++)
            for(;l<=n;l++) if(x[l]<=y[i]) break;
        if(l==n) fl=1;
        else
        {
            l=1;
            for(int i=1;i<=m;i++)
                for(;l<=n;l++) if(x[l]>=y[i]) break;
        }
        if(l==n) fl=1;
        cout<<fl;
    }
     return 0;
}

