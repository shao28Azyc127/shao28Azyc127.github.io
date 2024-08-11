#include<iostream>
using namespace std;
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c,n,m,q;
    scanf("%d%d%d%d",&c,&n,&m,&q);
    if (c == 1)
    {
        int x,y,xx,yy;
        scanf("%d%d",&x,&y);
        if (x != y) printf("1");
        else printf("0");
        while(q--)
        {
            xx = x,yy = y;
            int kx,ky;
            scanf("%d%d",&kx,&ky);
            for (int i = 1;i <= kx;i++)
            {
                int p,v;
                scanf("%d%d",&p,&v);
                xx = v;
            }
            for (int i = 1;i <= ky;i++)
            {
                int p,v;
                scanf("%d%d",&p,&v);
                yy = v;
            }
            if (xx != yy) printf("1");
            else printf("0");
        }
    }
    return 0;
}
