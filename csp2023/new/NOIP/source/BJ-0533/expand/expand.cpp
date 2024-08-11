#include<iostream>
using namespace std;
int a[3],b[3],c,n,m,q,a1,a2,b1,b2;
int main()
{
    freopen("exband.in","r",stdin);
    freopen("exband.out","w",stdout);
    scanf("%d%d%d%d",&c,&n,&m,&q);
    if(c==1||c==2)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&b[i]);
        }
        if(n==1) a[2]=a[1];
        if(m==1) b[2]=b[1];
        a1=a[1];a2=a[2];b1=b[1];b2=b[2];
        if((a[1]>b[1]&&a[2]>b[2])||(a[1]<b[1]&&a[1]<b[2])) printf("1");
        else printf("0");
        while(q--)
        {
            int kx,ky,px,py,vx,vy;
            scanf("%d%d",&kx,&ky);
            for(int i=1;i<=kx;i++)
            {
                scanf("%d%d",&px,&vx);
                a[px]=vx;
            }
            for(int i=1;i<=ky;i++)
            {
                scanf("%d%d",&py,&vy);
                b[py]=vy;
            }
            if(n==1) a[2]=a[1];
            if(m==1) b[2]=b[1];
            if((a[1]>b[1]&&a[2]>b[2])||(a[1]<b[1]&&a[1]<b[2])) printf("1");
            else printf("0");
            a[1]=a1;a[2]=a2;b[1]=b1;b[2]=b2;
        }
    }
    return 0;
}