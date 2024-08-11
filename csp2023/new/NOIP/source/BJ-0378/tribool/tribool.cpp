#include <bits/stdc++.h>
using namespace std;
int fa[100005],v[100005];
int getr(int x){
    if(fa[x]==x) return x;
    return fa[x]=getr(fa[x]);
}
void merge(int x,int y){
    if(getr(x)!=getr(y))fa[getr(y)]=getr(x);
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;cin>>c>>t;
    while(t--){
        int ans=0;
        memset(v,-1,sizeof(v));
        int n,q;cin>>n>>q;
        for(int i=1;i<=n;i++) fa[i]=i;
        while(q--){
            char op;cin>>op;
            if(op=='+'||op=='-'){
                int x,y;cin>>x>>y;
                v[x]=v[y]=1;
                if(op=='+') merge(x,y);
                else if(getr(x)==getr(y)) v[x]=v[y]=-1;
            }else{
                int x;cin>>x;
                if(op=='U')fa[getr(x)]=0;
                else if(op=='T') fa[getr(x)]=1e6;
                else fa[getr(x)]=1e7;
            }
        }
        for(int i=1;i<=n;i++){
            if(!getr(i)) ans++;
            if(v[getr(i)]==-1) ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
//freopen("tribool.in","r",stdin);
/*NOIPRP++
³¹µ×ÃÉÁË
*/
