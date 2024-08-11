#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c,n,m,q;cin>>c>>n>>m>>q;
    if(c==1)
    {
        int x,y;cin>>x>>y;
        if(x!=y)cout<<1;
        else cout<<0;
        while(q--)
        {
            int kx,ky;cin>>kx>>ky;
            int xx=x,yy=y;
            for(int i=1;i<=kx;i++)
            {
                int p,xxx;cin>>p>>xxx;
                if(p==1)xx=xxx;
            }
            for(int i=1;i<=ky;i++)
            {
                int p,yyy;cin>>p>>yyy;
                if(p==1)yy=yyy;
            }
            if(xx!=yy)cout<<1;
        else cout<<0;
        }
    }
    return 0;
}