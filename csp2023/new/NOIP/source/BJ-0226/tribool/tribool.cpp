#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
ll t,n,m,x[maxn],y[maxn],c,ans,vis[maxn],fa[maxn],col[maxn],sz[maxn];
char v[maxn],op[5],s[15],a[maxn];
void dfs(int k){
    if(k==n+1){
        bool flag=1;
        for(int i=1;i<=n;i++) a[i]=s[i];
        for(int i=1;i<=m;i++){
            if(v[i]=='+') a[x[i]]=a[y[i]];
            else if(v[i]=='-'){
                if(a[y[i]]=='T') a[x[i]]='F';
                else if(a[y[i]]=='F') a[x[i]]='T';
                else a[x[i]]='U';
            }
            else{
                a[x[i]]=v[i];
            }
        }
        ll cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]=='U') ++cnt;
            if(a[i]!=s[i]){
                return ;
            }
        }
        ans=min(ans,cnt);
        return ;
    }
    s[k]='T'; dfs(k+1);
    s[k]='F'; dfs(k+1);
    s[k]='U'; dfs(k+1);
}
int getfa(int p){
    if(fa[p]==p) return p;
    return fa[p]=getfa(fa[p]);
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    if(c<=2){
        while(t--){
            scanf("%lld%lld",&n,&m);
            for(int i=1;i<=m;i++){
                scanf("%s",op); v[i]=op[0];
                if(v[i]=='+'||v[i]=='-'){
                    scanf("%lld%lld",&x[i],&y[i]);
                }
                else{
                    scanf("%lld",&x[i]);
                }
            }
            ans=1e9;
            dfs(1);
            cout<<ans<<endl;
        }
    }
    else if(c==3||c==4){
        while(t--){
            scanf("%lld%lld",&n,&m);
            for(int i=1;i<=m;i++){
                scanf("%s",op); v[i]=op[0];
                if(v[i]=='+'||v[i]=='-'){
                    scanf("%lld%lld",&x[i],&y[i]);
                }
                else{
                    scanf("%lld",&x[i]);
                }
            }
            for(int i=1;i<=n;i++) a[i]='T';
            for(int i=1;i<=m;i++){
                a[x[i]]=v[i];
            }
            ll cnt=0;
            for(int i=1;i<=n;i++){
                if(a[i]=='U') ++cnt;
            }
            cout<<cnt<<endl;
        }
    }
    else if(c==5||c==6){
        while(t--){
            scanf("%lld%lld",&n,&m);
            for(int i=1;i<=m;i++){
                scanf("%s",op); v[i]=op[0];
                if(v[i]=='+'||v[i]=='-'){
                    scanf("%lld%lld",&x[i],&y[i]);
                }
                else{
                    scanf("%lld",&x[i]);
                }
            }
            for(int i=1;i<=n;i++) {
                fa[i]=i;
                col[i]=0;
                sz[i]=1;
            }
            for(int i=m;i>=1;i--){
                if(vis[x[i]]==1) continue;
                vis[x[i]]=1;
                if(v[i]=='U'){
                    int f=getfa(x[i]);
                    col[f]=1;
                }
                else{
                    int f1=getfa(x[i]),f2=getfa(y[i]);
                    if(f1==f2) continue;
                    sz[f2]+=sz[f1];
                    if(col[f1]==1) col[f2]=1;
                    fa[f1]=f2;
                }
            }
            ll cnt=0;
            for(int i=1;i<=n;i++){
                int f=getfa(i);
                if(col[f]==1){
                    cnt+=sz[f];
                }
            }
            cout<<cnt<<endl;
        }
    }
    return 0;
}
