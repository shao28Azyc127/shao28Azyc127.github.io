#include<iostream>
#include<algorithm>>

using namespace std;

long long x[500005],y[500005],dx[500005],dy[500005];
long long c,n,m,q,a,b,p,v,minx,maxx,miny,maxy;

int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin >> c >> n >> m >> q ;
    long long i,j;
    for(i=1;i<=n;i++)
        cin >> x[i] ;
    for(i=1;i<=m;i++)
        cin >> y[i] ;
    do{
        for(i=1;i<=n;i++)
            dx[i]=x[i];
        for(i=1;i<=m;i++)
            dy[i]=y[i];
        for(i=1;i<=a;i++)
            cin >> p >> v ;
            dx[p]=v;
        for(i=1;i<=b;i++)
            cin >> p >> v ;
            dy[p]=v;
        if((dx[1]-dy[1])*(dx[n]-dy[m])<=0)
        {
            putchar('0');
            continue;
        }
        minx=0x0f0f0f0f0f0f0f0f;
        miny=0x0f0f0f0f0f0f0f0f;
        maxx=-1;
        maxy=-1;
        for(i=1;i<=n;i++)
        {
            minx=min(dx[i],minx);
            maxx=max(dx[i],maxx);
        }
        for(i=1;i<=m;i++)
        {
            miny=min(dy[i],miny);
            maxy=max(dy[i],maxy);
        }
        if((minx-miny)*(maxx-maxy)<=0)
        {
            putchar('0');
            continue;
        }
        if((minx-miny)*(dx[1]-dy[1])<=0)
        {
            putchar('0');
            continue;
        }
        putchar('1');
    }while(cin >> a >> b);
    return 0;
}
