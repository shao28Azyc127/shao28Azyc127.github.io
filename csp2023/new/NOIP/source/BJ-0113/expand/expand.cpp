#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,a[500010],b[500010],f[2010][2010],tx[500010],ty[500010],ta[500010],tb[500010];
bool check()
{
    if((a[1]-b[1])==0||(a[n]-b[m])==0) return false;
    if((a[1]>b[1]&&a[n]<b[m])||(a[1]<b[1]&&a[n]>b[m])) return false;
    int op=0;
    if(a[1]>b[1]) op=1;
    memset(f,0,sizeof(f));
    f[1][1]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==1&&j==1) continue;
            if(op==1?a[i]>b[j]:a[i]<b[j])
                f[i][j]|=f[i-1][j]|f[i][j-1]|f[i-1][j-1];
       //     printf("%d ",f[i][j]);
        }
     //   printf("\n");
    }
    if(f[n][m]) return true;
    return false;
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&c,&n,&m,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),ta[i]=a[i];
    for(int i=1;i<=m;i++) scanf("%d",&b[i]),tb[i]=b[i];
    if(check()) printf("1");
    else printf("0");
    while(q--)
    {
        int kx,ky; scanf("%d%d",&kx,&ky);
        for(int i=1;i<=kx;i++)
        {
            int x,val; scanf("%d%d",&x,&val);
            a[x]=val; tx[i]=x;
        }
        for(int i=1;i<=ky;i++)
        {
            int x,val; scanf("%d%d",&x,&val);
            b[x]=val; ty[i]=x;
        }
   //     for(int i=1;i<=n;i++) printf("%d ",a[i]);
   //     printf("\n");
   //     for(int i=1;i<=m;i++) printf("%d ",b[i]);
   //     printf("\n");
        if(check()) printf("1");
        else printf("0");
     //   printf("\n");
        for(int i=1;i<=kx;i++)
            a[tx[i]]=ta[tx[i]];
        for(int i=1;i<=ky;i++)
            b[ty[i]]=tb[ty[i]];
    }
    return 0;
}
