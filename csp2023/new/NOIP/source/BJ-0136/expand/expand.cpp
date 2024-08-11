#include<iostream>
#include<cstring>
using namespace std;
int n,m,x[2002],y[2002],xx[2002],yy[2002];
bool f[2002][2002];
int solv()
{
    memset(f,0,sizeof(f));
    f[1][1]=1;
    int c;
    if(y[1]>x[1])   c=1;
    else if(y[1]<x[1])    c=-1;
    else    return 0;
    if(c*(y[m]-x[n])<=0)    return 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(!f[i][j])    continue;
            if((y[j]-x[i])*c>0)   
                f[i][j+1]=f[i+1][j]=f[i+1][j+1]=1;
        }
    }
    return f[n][m];
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c,q;
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++)
        cin>>x[i];
    for(int i=1;i<=m;i++)
        cin>>y[i];
    cout<<solv();
    for(int i=1;i<=n;i++)
        xx[i]=x[i];
    for(int i=1;i<=m;i++)
        yy[i]=y[i];
    while(q--)
    {
        int kx,ky;
        cin>>kx>>ky;
        for(int i=1;i<=n;i++)
            x[i]=xx[i];
        for(int i=1;i<=m;i++)
            y[i]=yy[i];
        for(int i=1;i<=kx;i++)
        {
            int p,v;
            cin>>p>>v;
            x[p]=v;
        }
        for(int i=1;i<=ky;i++)
        {
            int p,v;
            cin>>p>>v;
            y[p]=v;
        }
        cout<<solv();
    }
    cout<<endl;
    return 0;
}