#include<cstdio>
#define M 500005
#define Max(x,y) ((x)>(y)?(x):(y))
int c,n,m,q;
int a[M],b[M],a1[M],b1[M];

void zhishu()
{
    for(int i=1;i<=n;i++)
    {
        a1[i]=a[i];
    }
    for(int i=1;i<=m;i++)
    {
        b1[i]=b[i];
    }
}

int qiuzhi()
{
    int amx=a1[1];
    for(int i=1;i<=n;i++)
        amx=Max(amx,a1[i]);
    if(amx>=b1[m])return 0;
    return 1;
}

int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&c,&n,&m,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&b[i]);
    }
    if(c==1)
    {
        if(a[1]!=b[1])printf("1");
        else printf("0");
        while(q--)
        {
            int kx,ky,p,v;
            scanf("%d%d",&kx,&ky);
            zhishu();
            while(kx--)
            {
                scanf("%d%d",&p,&v);
                a1[p]=v;
            }
            while(ky--)
            {
                scanf("%d%d",&p,&v);
                b1[p]=v;
            }
            if(a1[1]!=b1[1])printf("1");
            else printf("0");
        }
    }
    if(c==2)
    {
        if((a[1]<b[1] && a[2]<b[2])||(a[1]>b[1] && a[2]>b[2]))
            printf("1");
        else printf("0");
        while(q--)
        {
            int kx,ky,p,v;
            scanf("%d%d",&kx,&ky);
            zhishu();
            while(kx--)
            {
                scanf("%d%d",&p,&v);
                a1[p]=v;
            }
            while(ky--)
            {
                scanf("%d%d",&p,&v);
                b1[p]=v;
            }
            if((a1[1]<b1[1] && a1[2]<b1[2])||(a1[1]>b1[1] && a1[2]>b1[2]))
                printf("1");
            else printf("0");
        }
    }

    if(c>=8 && c<=14)
    {
        zhishu();
        printf("%d",qiuzhi());
        while(q--)
        {
            int kx,ky,p,v;
            scanf("%d%d",&kx,&ky);
            zhishu();
            while(kx--)
            {
                scanf("%d%d",&p,&v);
                a1[p]=v;
            }
            while(ky--)
            {
                scanf("%d%d",&p,&v);
                b1[p]=v;
            }
            printf("%d",qiuzhi());
        }
    }
    return 0;
}
