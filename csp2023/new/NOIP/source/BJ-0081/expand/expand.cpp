#include <bits/stdc++.h>
#define MAXN 2010
using namespace std;
int c,n,m,q,op,kx,ky,x[MAXN],y[MAXN],f[MAXN][MAXN];
int tx[MAXN],ty[MAXN];
bool cmp(int x,int y)
{
    if(op) return x<y;
    return x>y;
}
int check()
{
    memset(f,0,sizeof(f));
    if(x[1]==y[1]) return 0;
    else
    {
  /*      for(int i=1;i<=n;i++)
            cout<<x[i]<<' ';
        cout<<'\n';
        for(int i=1;i<=m;i++)
            cout<<y[i]<<' ';
        cout<<'\n';*/
        if(x[1]<y[1]) op=1;
        else op=0;
        f[1][1]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(cmp(x[i],y[j]))
                    f[i][j]|=(f[i-1][j-1]|f[i-1][j]|f[i][j-1]);
    }
    return f[n][m];
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin.sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++) cin>>x[i];
    for(int i=1;i<=m;i++) cin>>y[i];
    cout<<check();
    memcpy(tx,x,sizeof(x));
    memcpy(ty,y,sizeof(y));
    while(q--)
    {
        cin>>kx>>ky;
        int p,v;
        for(int i=1;i<=kx;i++)
            cin>>p>>v,x[p]=v;
        for(int i=1;i<=ky;i++)
            cin>>p>>v,y[p]=v;
        cout<<check();
        memcpy(x,tx,sizeof(x));
        memcpy(y,ty,sizeof(y));
    }

    return 0;
}
