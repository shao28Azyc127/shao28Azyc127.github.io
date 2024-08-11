#include <bits/stdc++.h>
using namespace std;
int c,n,m,q,x[3],y[3];
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&c,&n,&m,&q);
    for(int i = 1;i <= n;i++) scanf("%d",&x[i]);
    for(int i = 1;i <= m;i++) scanf("%d",&y[i]);
    if(c == 1 || (n == 1 && m == 1))
    {
        if(x[1] == y[1]) cout << 0;
        else cout << 1;
        int tx[2],ty[2];
        tx[1] = x[1],ty[1] = y[1];
        for(int i = 1;i <= q;i++)
        {
            x[1] = tx[1],y[1] = ty[1];
            int kx,ky;
            scanf("%d%d",&kx,&ky);
            for(int j = 1;j <= kx;j++)
            {
                int px,vx;
                scanf("%d%d",&px,&vx);
                x[px] = vx;
            }
            for(int j = 1;j <= ky;j++)
            {
                int py,vy;
                scanf("%d%d",&py,&vy);
                y[py] = vy;
            }
            if(x[1] != y[1]) cout << 1;
            else cout << 0;
        }
        return 0;
    }
    if(c == 2)
    {
        if(n == 2 && m == 1)
        {
            if((x[1] - y[1]) * (x[2] - y[1]) > 0) cout << 1;
            else cout << 0;
            int tx[3],ty[2];
            tx[1] = x[1],tx[2] = x[2],ty[1] = y[1];
            for(int i = 1;i <= q;i++)
            {
                x[1] = tx[1],x[2] = tx[2],y[1] = ty[1];
                int kx,ky;
                scanf("%d%d",&kx,&ky);
                for(int j = 1;j <= kx;j++)
                {
                    int px,vx;
                    scanf("%d%d",&px,&vx);
                    x[px] = vx;
                }
                for(int j = 1;j <= ky;j++)
                {
                    int py,vy;
                    scanf("%d%d",&py,&vy);
                    y[py] = vy;
                }
                if((x[1] - y[1]) * (x[2] - y[1]) > 0) cout << 1;
                else cout << 0;
            }
        }
        else if(n == 1 && m == 2)
        {
            int tx[2],ty[3];
            tx[1] = x[1],ty[2] = y[2],ty[1] = y[1];
            if((y[1] - x[1]) * (y[2] - x[1]) > 0) cout << 1;
            else cout << 0;
            for(int i = 1;i <= q;i++)
            {
                x[1] = tx[1],y[2] = ty[2],y[1] = ty[1];
                int kx,ky;
                scanf("%d%d",&kx,&ky);
                for(int j = 1;j <= kx;j++)
                {
                    int px,vx;
                    scanf("%d%d",&px,&vx);
                    x[px] = vx;
                }
                for(int j = 1;j <= ky;j++)
                {
                    int py,vy;
                    scanf("%d%d",&py,&vy);
                    y[py] = vy;
                }
                if((y[1] - x[1]) * (y[2] - x[1]) > 0) cout << 1;
                else cout << 0;
            }
        }
        else
        {
            int tx[3],ty[3];
            tx[1] = x[1],tx[2] = x[2],ty[1] = y[1],ty[2] = y[2];
            bool t1 = ((((x[1] - y[1]) * (x[2] - y[1])) > 0) && (((x[1] - y[1]) * (x[2] - y[2])) > 0));
            bool t2 = ((x[1] - y[1]) * (x[2] - y[2]) > 0);
            bool t3 = ((((x[1] - y[1]) * (x[2] - y[2])) > 0) && (((x[1] - y[2]) * (x[2] - y[2])) > 0));
            if(t1 || t2 || t3) cout << 1;
            else cout << 0;
            for(int i = 1;i <= q;i++)
            {
                x[2] = tx[2],x[1] = tx[1],y[2] = ty[2],y[1] = ty[1];
                int kx,ky;
                scanf("%d%d",&kx,&ky);
                for(int j = 1;j <= kx;j++)
                {
                    int px,vx;
                    scanf("%d%d",&px,&vx);
                    x[px] = vx;
                }
                for(int j = 1;j <= ky;j++)
                {
                    int py,vy;
                    scanf("%d%d",&py,&vy);
                    y[py] = vy;
                }
                bool t1 = ((((x[1] - y[1]) * (x[2] - y[1])) > 0) && (((x[1] - y[1]) * (x[2] - y[2])) > 0));
                bool t2 = ((x[1] - y[1]) * (x[2] - y[2]) > 0);
                bool t3 = ((((x[1] - y[1]) * (x[2] - y[2])) > 0) && (((x[1] - y[2]) * (x[2] - y[2])) > 0));
                if(t1 || t2 || t3) cout << 1;
                else cout << 0;
            }
        }
    }
    return 0;
}
