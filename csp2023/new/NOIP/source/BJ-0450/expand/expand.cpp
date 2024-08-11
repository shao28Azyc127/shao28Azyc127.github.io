#include<iostream>
#include<cstdio>
using namespace std;
int c,n,m,q;

int read()
{
    int f=1, x;
    char c=getchar();
    while(!('0'<=c&&c<='9'))
    {
        if(c=='-')
            f=-1;
        c=getchar();
    }
    while('0'<=c&&c<='9')
    {
        x=x*10+(c-'0');
        c=getchar();
    }
    return f*x;
}
namespace _10pts
{
    int x, y;
    void mian()
    {   
        cin >> x >> y;
        if(x!=y) cout << 1;
        else cout << 0;
        while(q--)
        {
            int kx, ky;
            cin >> kx >> ky;
            while(kx--)
            {
                int px, vx;
                px=read();
                vx=read();
                x=vx;
            }

            while(ky--)
            {
                int py, vy;
                py=read();
                vy=read();
                y=vy;
            }
            if(x!=y) cout << 1;
            else cout << 0;
        }
        return ;
    }
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin >> c >> n >> m >> q;
    if(c==1)
        _10pts::mian();
    return 0;
}
