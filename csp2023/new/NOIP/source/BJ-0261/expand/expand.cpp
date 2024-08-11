#include<bits/stdc++.h>
using namespace std;
int x,y,nx,ny,kx,ky,px,vx,py,vy;
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c,n,m,q;
	cin>>c>>n>>m>>q;
	cin>>x>>y;
    if(x!=y) cout<<1;
    else cout<<0;
	while(q--)
    {
        nx=x,ny=y;
        cin>>kx>>ky;
        for(int i=1;i<=kx;i++)
        {
            cin>>px>>vx;
            nx=vx;
        }
        for(int i=1;i<=ky;i++)
        {
            cin>>py>>vy;
            ny=vy;
        }
        if(nx!=ny) cout<<1;
        else cout<<0;
    }
    return 0;
}
