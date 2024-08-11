#include<bits/stdc++.h>
#define For(i,l,r) for(register int i=(l);i<=(r);++i)
#define For_down(i,r,l) for(register int i=(r);i>=(l);--i)
using namespace std;
const int n_MAX=1000000+5;
int n,m,a[n_MAX],Fa[n_MAX<<1],siz[n_MAX<<1]; char c[n_MAX];
int find(const int u)
{
    if(Fa[u]==u) return u;
    Fa[u]=find(Fa[u]);
    return Fa[u];
}
void merge(const int u,const int v)
{
    const int Fu=find(u),Fv=find(v);
    if(Fu!=Fv) Fa[Fv]=Fu,siz[Fu]+=siz[Fv];
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int sub,task; cin>>sub>>task;
    while(task--)
    {
        int n,q; cin>>n>>q; const int m=((n<<1)+3);
        const int T=((n<<1)+1),F=((n<<1)+2),U=((n<<1)+3);
        For(i,1,n) c[i]='.',a[i]=i;
        while(q--)
        {
            char op; int u=0,v=0;
            cin>>op;
            if(op=='T') cin>>u,c[u]='1',a[u]=0;
            else if(op=='F') cin>>u,c[u]='0',a[u]=0;
            else if(op=='U') cin>>u,c[u]='?',a[u]=0;
            else if(op=='+') cin>>u>>v,c[u]=c[v],a[u]=a[v];
            else if(op=='-')
            {
                cin>>u>>v;
                if(c[v]=='1') c[u]='0',a[u]=0;
                else if(c[v]=='0') c[u]='1',a[u]=0;
                else if(c[v]=='?') c[u]='?',a[u]=0;
                else if(c[v]=='.')
                {
                    if(a[v]<=n) c[u]='.',a[u]=(a[v]+n);
                    else if(a[v]>n) c[u]='.',a[u]=(a[v]-n);
                }
            }
        }
        For(i,1,m) Fa[i]=i,siz[i]=(i<=(n<<1));
        For(i,1,n)
        {
            if(c[i]=='1') merge(i,T),merge(n+i,F);
            else if(c[i]=='0') merge(i,F),merge(n+i,T);
            else if(c[i]=='?') merge(i,U),merge(n+i,U);
            else if(c[i]=='.')
            {
                if(a[i]<=n) merge(i,a[i]),merge(i+n,a[i]+n);
                else if(a[i]>n) merge(i,a[i]),merge(i+n,a[i]-n);
            }
        }
        For(i,1,n) if(find(i)==find(i+n)) merge(i,U),merge(n+i,U);
        cout<<(siz[find(U)]>>1)<<'\n';
    }
    return 0;
}