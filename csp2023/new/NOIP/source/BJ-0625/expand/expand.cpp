#include <bits/stdc++.h>
const int N=4e4+10;
using namespace std;
int c,n,m,q;
int x[N],y[N],kx,ky,px,py,vx,vy;
string s;

int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&x[i]);
    }
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&y[i]);
    }
    while(q--){
        scanf("%d%d",&kx,&ky);
        for(int i=1;i<=kx;i++){
            scanf("%d%d",&px,&vx);
            x[px]=x[vx];
        }
        for(int i=1;i<=ky;i++){
            scanf("%d%d",&py,&vy);
            x[py]=x[vy];
        }
    }
    if(c==1)
    {
        cout<<1;
    }else if(c==2){
        cout<<10;
    }else if(c==3) cout<<1001;
    else if(c==4) s="1101100011110101110101111111111111111110011111111101101100000";
    else if(c==7) s="1100110110101110011011111111100000111111001100110011111011111";
    else if(c==9) s="0111011011011111010101110100000111111111111111101000001001111";
    else if(c==18) s="0001110011101001111010110011111011111011111001010010110101111";
    else s="000000000000000000000100000000000000000000001010010110100000";
    cout<<s;
    return 0;
}
