#include<bits/stdc++.h>
using namespace std;
int a[10],b[10],a1[10],b1[10],nd1[10],nd2[10];
int c,n,m,q,tot;
bool judge()
{
    if((a[1]-b[1])*(a[1]-b[1])<=0) return false;
    if((a[2]-b[2])*(a[2]-b[2])<=0) return false;
    if((a[1]-b[1])*(a[2]-b[2])<=0) return false;
    return true;
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    if(c==1)
    {
        for(int i=1;i<=n;i++) cin>>a[i],a1[i]=a[i];
        for(int i=1;i<=m;i++) cin>>b[i],b1[i]=b[i];
        if(a[1]!=b[1]) cout<<1;
        else cout<<0;
        for(int i=1;i<=q;i++)
        {
            int kx,ky,px,ux,py,uy;
            cin>>kx>>ky;
            for(int j=1;j<=kx;j++)
            {
                cin>>px>>ux;
                a[px]=ux;
            }
            for(int j=1;j<=ky;j++)
            {
                cin>>py>>uy;
                b[py]=uy;
            }
            if(a[1]!=b[1]) cout<<1;
            else cout<<0;
            for(int j=1;j<=n;j++) a[j]=a1[j];
            for(int j=1;j<=m;j++) b[j]=b1[j];
        }
    }
    if(c==2)
    {
        for(int i=1;i<=n;i++) cin>>a[i],a1[i]=a[i];
        for(int i=1;i<=m;i++) cin>>b[i],b1[i]=b[i];

        if(judge()) cout<<1;
        else cout<<0;
        for(int i=1;i<=q;i++)
        {
            int kx,ky,px,ux,py,uy;
            cin>>kx>>ky;
            for(int j=1;j<=kx;j++)
            {
                cin>>px>>ux;
                a[px]=ux;
            }
            for(int j=1;j<=ky;j++)
            {
                cin>>py>>uy;
                b[py]=uy;
            }
            if(judge()) cout<<1;
            else cout<<0;
            for(int j=1;j<=n;j++) a[j]=a1[j];
            for(int j=1;j<=m;j++) b[j]=b1[j];
        }
    }

}
