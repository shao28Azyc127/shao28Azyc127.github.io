#include<bits/stdc++.h>
using namespace std;
const int N=100005,M=2005;
int sid,n,m,q;
int a[N],b[N],nowa[N],nowb[N];
int f[M][M];
int calc()
{
    memset(f,0,sizeof(f));
    f[0][0]=1;
    if(nowa[1]<nowb[1])
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(nowa[i]<nowb[j]&&(f[i-1][j]||f[i][j-1]||f[i-1][j-1])) f[i][j]=1;
    }
    if(nowa[1]>nowb[1])
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(nowa[i]>nowb[j]&&(f[i-1][j]||f[i][j-1]||f[i-1][j-1])) f[i][j]=1;
    }
    /*
    for(int i=1;i<=n;i++) printf("%d ",a[i]);printf("\n");
    for(int i=1;i<=m;i++) printf("%d ",b[i]);printf("\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) printf("%d ",f[i][j]);printf("\n");}
    */
    return f[n][m];
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&sid,&n,&m,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),nowa[i]=a[i];
    for(int i=1;i<=m;i++) scanf("%d",&b[i]),nowb[i]=b[i];
    printf("%d",calc());
    for(int i=1;i<=q;i++)
    {
        for(int j=1;j<=n;j++) nowa[i]=a[i];
        for(int j=1;j<=m;j++) nowb[i]=b[i];
        int kx,ky,x,v;
        scanf("%d%d",&kx,&ky);
        for(int j=1;j<=kx;j++) scanf("%d%d",&x,&v),nowa[x]=v;
        for(int j=1;j<=ky;j++) scanf("%d%d",&x,&v),nowb[x]=v;
        printf("%d",calc());
    }
    printf("\n");
    return 0;
}
