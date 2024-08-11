#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int c,t,n,m,ans;
int rel[300005],fa[300005],id[300005];
void init(){
    ans=0;
    for(int i=0;i<=n;i++) rel[i]=i;
    for(int i=0;i<=2*n+3;i++) fa[i]=i;
    for(int i=0;i<=2*n+3;i++) id[i]=0;
}
int fin(int now){
    return (fa[now]==now)?now:fa[now]=fin(fa[now]);
}
void mer(int now1,int now2){
    int fa1=fin(now1),fa2=fin(now2);
    if(fa1==fa2) return;
    fa[fa1]=fa2;
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int x,y; char v;
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        init();
        for(int i=1;i<=m;i++){
            cin>>v;
            if(v=='T'){
                cin>>x;
                rel[x]=2*n+1;
            }
            if(v=='F'){
                cin>>x;
                rel[x]=2*n+2;
            }
            if(v=='U'){
                cin>>x;
                rel[x]=2*n+3;
            }
            if(v=='+'){
                cin>>x>>y;
                rel[x]=rel[y];
            }
            if(v=='-'){
                cin>>x>>y;
                if(rel[y]<=n) rel[x]=rel[y]+n;
                else if(rel[y]>n&&rel[y]<=2*n) rel[x]=rel[y]-n;
                else if(rel[y]==2*n+1) rel[x]=2*n+2;
                else if(rel[y]==2*n+2) rel[x]=2*n+1;
                else if(rel[y]==2*n+3) rel[x]=2*n+3;
            }
        }
        for(int i=1;i<=n;i++){
            mer(i,rel[i]);
            if(rel[i]<=n) mer(n+i,rel[i]+n);
            if(rel[i]>n&&rel[i]<=2*n) mer(n+i,rel[i]-n);
            if(rel[i]==2*n+1) mer(n+i,2*n+2);
            if(rel[i]==2*n+2) mer(n+i,2*n+1);
            if(rel[i]==2*n+3) mer(n+i,2*n+3);
        }
        for(int i=1;i<=n;i++){
            if(fin(i)==fin(n+i)) id[fin(i)]=1;
            else if(fin(i)==fin(2*n+3)) id[fin(i)]=id[fin(n+i)]=1;
        }
        for(int i=1;i<=n;i++) if(id[fin(i)]==1) ans++;
        cout<<ans<<endl;
    }
    return 0;
}
// T:2*n+1  F:2*n+2,U:2*n+3
