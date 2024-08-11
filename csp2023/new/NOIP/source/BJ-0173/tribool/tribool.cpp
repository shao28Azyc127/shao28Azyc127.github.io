#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define MAXN 100005
int c,T,n,m;
struct node{
    char op;
    int x,y;
}a[MAXN];
namespace c12{
    int ans;
    short b[MAXN],tmp[MAXN];
    void init(){
        ans=0x3f3f3f3f;
    }
    bool check(){
        for(int i=1;i<=n;i++) tmp[i]=b[i];
        for(int i=1;i<=m;i++){
            if(a[i].op=='T') tmp[a[i].x]=0;
            else if(a[i].op=='F') tmp[a[i].x]=1;
            else if(a[i].op=='U') tmp[a[i].x]=2;
            else if(a[i].op=='+') tmp[a[i].x]=tmp[a[i].y];
            else{
                if(tmp[a[i].y]==2) tmp[a[i].x]=2;
                else tmp[a[i].x]=1-tmp[a[i].y];
            }
        }
        for(int i=1;i<=n;i++) if(tmp[i]!=b[i]) return 0;
        return 1;
    }
    void dfs(int u,int cnt){
        if(u>n){
            if(check()) ans=min(ans,cnt);
            return;
        }
        b[u]=0;
        dfs(u+1,cnt);
        b[u]=1;
        dfs(u+1,cnt);
        b[u]=2;
        dfs(u+1,cnt+1);
    }
    void solve(){
        init();
        dfs(1,0);
        cout<<ans<<endl;
    }
}
namespace c34{
    int ans;
    short b[MAXN];
    void init(){
        ans=0;
        memset(b,0,sizeof(b));
    }
    void solve(){
        init();
        for(int i=1;i<=m;i++){
            if(a[i].op=='F') b[a[i].x]=0;
            else if(a[i].op=='T') b[a[i].x]=1;
            else b[a[i].x]=2;
        }
        for(int i=1;i<=n;i++) if(b[i]==2) ans++;
        cout<<ans<<endl;
    }
}
namespace c579{
    short f[2][MAXN];
    bool check(){
        bool flag=0;
        for(int i=1;i<=n;i++){
            if(f[0][i]!=f[1][i]){
                if(f[0][i]+f[1][i]==1) flag=1;
                else return 0;
            }
        }
        if(flag){
            for(int i=1;i<=n;i++){
                if(f[0][i]=='U'||f[1][i]=='U') continue;
                if(f[0][i]==f[1][i]) return 0;
            }
        }
        return 1;
    }
    void solve(){
        int w=1;
        memset(f,0,sizeof(f));
        while(1){
            memcpy(f[w],f[w^1],sizeof(f[w^1]));
            for(int i=1;i<=m;i++){
                if(a[i].op=='T') f[w][a[i].x]=0;
                else if(a[i].op=='F') f[w][a[i].x]=1;
                else if(a[i].op=='U') f[w][a[i].x]=2;
                else if(a[i].op=='+') f[w][a[i].x]=f[w][a[i].y];
                else{
                    if(f[w][a[i].y]==2) f[w][a[i].x]=2;
                    else f[w][a[i].x]=1-f[w][a[i].y];
                }
            }
            if(check()) break;
            w^=1;
        }
        int ans=0;
        for(int i=1;i<=n;i++) if(f[w][i]==2) ans++;
        cout<<ans<<endl;
    }
}
int main(){
    ios::sync_with_stdio(0);
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            cin>>a[i].op;
            if(a[i].op=='+'||a[i].op=='-') cin>>a[i].x>>a[i].y;
            else cin>>a[i].x;
        }
        if(c==1||c==2) c12::solve();
        else if(c==3||c==4) c34::solve();
        else c579::solve();
    }
    return 0;
}