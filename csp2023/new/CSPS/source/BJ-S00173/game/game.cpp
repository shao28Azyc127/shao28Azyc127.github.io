#include<bits/stdc++.h>
#define For(i,l,r) for(register int i=(l);i<=(r);++i)
#define For_down(i,r,l) for(register int i=(r);i>=(l);--i)
using namespace std;
const int n_MAX=2000000+5;
char ca[n_MAX]; int a[n_MAX],ch[n_MAX][26],Fa[n_MAX],w[n_MAX],siz[n_MAX],n,m;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>(ca+1);
    For(i,1,n) a[i]=(ca[i]-'a');
    int u=0;
    siz[0]=1,w[0]=(-1);
    For(i,1,n)
    {
        if(w[u]==a[i])
        {
            u=Fa[u];
        }
        else
        {
            if(!ch[u][a[i]])
                ch[u][a[i]]=(++m),Fa[m]=u,w[m]=a[i];
            u=ch[u][a[i]];
        }
        ++siz[u];
    }
    long long ans=0;
    For(i,0,m) ans+=((siz[i]*(siz[i]-1))>>1);
    cout<<ans<<'\n';
    return 0;
}