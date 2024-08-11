#include<iostream>
using namespace std;

const int MXN=4010;
int x[MXN],y[MXN],n,m;
int f[MXN][MXN];

void Solve()
{
    f[0][0]=1;// cout<<n<<' '<<m<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            f[i][j]=0;
            if(x[i]-y[j]<=0) continue;
            f[i][j]=max(f[i][j],f[i-1][j]);
            f[i][j]=max(f[i][j],f[i][j-1]);
            f[i][j]=max(f[i][j],f[i-1][j-1]);
        }
    }
    if(f[n][m]) {cout<<1;return ;}
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            f[i][j]=0;
            if(x[i]-y[j]>=0) continue;
            f[i][j]=max(f[i][j],f[i-1][j]);
            f[i][j]=max(f[i][j],f[i][j-1]);
            f[i][j]=max(f[i][j],f[i-1][j-1]);
        }
    }
    if(f[n][m]) {cout<<1;return ;}
    else {cout<<0;return ;}
}

int xB[MXN],yB[MXN];

int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c,q;cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++) cin>>xB[i];
    for(int i=1;i<=m;i++) cin>>yB[i];
    for(int i=1;i<=n;i++) x[i]=xB[i];
    for(int i=1;i<=m;i++) y[i]=yB[i];
    Solve();
    while(q--)
    {
        int Kx,Ky,p,v;cin>>Kx>>Ky;
        for(int i=1;i<=Kx;i++) {cin>>p>>v;x[p]=v;}
        for(int i=1;i<=Ky;i++) {cin>>p>>v;y[p]=v;}
        Solve();
        for(int i=1;i<=n;i++) x[i]=xB[i];
        for(int i=1;i<=m;i++) y[i]=yB[i];
    }cout<<endl;
    return 0;
}
