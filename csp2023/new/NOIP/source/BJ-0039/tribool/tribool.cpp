#include<bits/stdc++.h>
using namespace std;
#define N 300005
int T,c,n,m,out,xx[N],yy[N],a[N],o[N],fa[3*N],vis[N],s[N];
inline int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}
inline int id(int x,int i){return 3*x-i;}
inline void merge(int x,int y){
    x=get(x),y=get(y);
    if(x==y) return;
    fa[x]=y;
}
char op[N];
void dfs(int p){
    if(p==n+1){
        for(int i=1;i<=n;++i) o[i]=a[i];
        for(int i=1;i<=m;++i){
            if(op[i]=='T') o[xx[i]]=0;
            if(op[i]=='F') o[xx[i]]=1;
            if(op[i]=='U') o[xx[i]]=2;
            if(op[i]=='+') o[xx[i]]=o[yy[i]];
            if(op[i]=='-'){
                if(o[yy[i]]!=2) o[xx[i]]=o[yy[i]]^1;
                else o[xx[i]]=o[yy[i]];
            }
        }
        int xfl=1,ans=0;
        for(int i=1;i<=n;++i) xfl&=(a[i]==o[i]);
        if(xfl){
            for(int i=1;i<=n;++i) ans+=(a[i]==2);
            out=min(out,ans);
        }
        return;
    }
    for(int i=0;i<3;++i){
        a[p]=i;
        dfs(p+1);
    }
}
int main(){
    //system("diff tribool4.ans tribool.out -Z");exit(0);
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=m;++i){
            cin>>op[i]>>xx[i];
            if(op[i]=='+'||op[i]=='-') cin>>yy[i];
        }
        if(c<=2){
            out=1e9;
            dfs(1);
            cout<<out<<'\n';
            continue;
        }
        if(c<=4){
            memset(a,0xff,sizeof a),out=0;
            for(int i=1;i<=m;++i){
                if(op[i]=='T') a[xx[i]]=0;
                if(op[i]=='F') a[xx[i]]=1;
                if(op[i]=='U') a[xx[i]]=2;
            }
            for(int i=1;i<=n;++i) out+=(a[i]==2);
            cout<<out<<'\n';
            continue;
        }
        if(c==7||c==8){
            for(int i=1;i<=n;++i) for(int j=0;j<3;++j) fa[id(i,j)]=id(i,j);
            for(int i=1;i<=m;++i){
                if(op[i]=='+') merge(id(xx[i],0),id(yy[i],0)),merge(id(xx[i],1),id(yy[i],1)),merge(id(xx[i],2),id(yy[i],2));
                if(op[i]=='-') merge(id(xx[i],1),id(yy[i],0)),merge(id(xx[i],0),id(yy[i],1)),merge(id(xx[i],2),id(yy[i],2));
            }
            out=0;
            memset(s,0,sizeof s),memset(vis,0,sizeof vis);
            for(int i=1;i<=n;++i) s[get(id(i,2))]++;
            for(int i=1,res;i<=n;++i){
                if(!vis[get(id(i,0))]&&!vis[get(id(i,1))]&&!vis[get(id(i,2))]){
                    res=1e9;
                    if(get(id(i,0))!=get(id(i,1))) res=min(s[get(id(i,0))],s[get(id(i,1))]);
                    res=min(res,s[get(id(i,2))]);
                    out+=res;
                }
            } cout<<out<<'\n';
            continue;
        }
    }
}
