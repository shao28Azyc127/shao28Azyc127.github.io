#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

const int N=5e5+10;

int c,n,m,q;
int x[N],y[N];

int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&c,&n,&m,&q);
    for(int i=1;i<=n;i++) scanf("%d",&x[i]);
    for(int i=1;i<=m;i++) scanf("%d",&y[i]);
    if(n<=1&&m<=1)
    {
        int ans=1;
        if(x[1]==y[1]) ans=0;
        printf("%d",ans);
        while(q--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            for(int i=1;i<=a;i++)
            {
                int c,d;
                scanf("%d%d",&c,&d);
                x[c]=d;
            }
            for(int i=1;i<=b;i++)
            {
                int c,d;
                scanf("%d%d",&c,&d);
                y[c]=d;
            }
            printf("%d",ans);
        }
        return 0;
    }
    if(n==1&&m==2)
    {
        int ans=1;
        if(x[1]==y[1]||x[1]==y[2]) ans=0;
        if((x[1]<y[1]&&x[1]>y[2])||(x[1]>y[1]&&x[1]<y[2])) ans=0;
        printf("%d",ans);
        while(q--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            for(int i=1;i<=a;i++)
            {
                int c,d;
                scanf("%d%d",&c,&d);
                x[c]=d;
            }
            for(int i=1;i<=b;i++)
            {
                int c,d;
                scanf("%d%d",&c,&d);
                y[c]=d;
            }
            printf("%d",ans);
        }
    }
    return 0;
}