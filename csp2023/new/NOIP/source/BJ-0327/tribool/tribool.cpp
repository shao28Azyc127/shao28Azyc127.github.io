#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100010;
const  int INF=1000000000000;
int sta[N],n;
int c,t,m;
int fa[N];
vector<int> b[N];
int to(char ch){
    if(ch=='T')  return 1;
    if(ch=='F') return 2;
    return 3;
}
bool vis[N];
void dfs(int u){
    for(auto v:b[u]){
        sta[v]=max(sta[v],sta[u]);
        dfs(v);
    }
}
int tmp[N];
struct Option{
    char opt;
    int x,y;
}o[N];
bool check(){
    for(int i=1;i<=n;i++) tmp[i]=sta[i];
    for(int i=1;i<=m;i++){
        if(o[i].opt=='+') tmp[o[i].x]=tmp[o[i].y];
        else if(o[i].opt=='-')  tmp[o[i].x]=(tmp[o[i].y]==3?3:3-tmp[o[i].y]);
        else tmp[o[i].x]=to(o[i].opt);
    }
    for(int  i=1;i<=n;i++) if(tmp[i]!=sta[i])  return false;
    return true;
}
int ans=INF;
void dfs2(int u,int cnt){
    if(u==n+1) return ans=min(ans,check()?cnt:INF),void();
    sta[u]=1;dfs2(u+1,cnt);
    sta[u]=2;dfs2(u+1,cnt);
    sta[u]=3;dfs2(u+1,cnt+1);
}
signed main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        scanf("%lld%lld",&n,&m);
        for(int i=1;i<=n;i++) sta[i]=fa[i]=0;
        for(int i=1;i<=m;i++){
            char opt[3];int x,y;scanf("%s%lld",&opt,&x);
            if(c==1||c==2){
                if(opt[0]=='+'||opt[0]=='-') scanf("%lld",&y);
                o[i]={opt[0],x,y};
            }
            if(c==3||c==4){
                sta[x]=to(opt[0]);
            }
            if(c==5||c==6){
                if(opt[0]=='U') sta[x]=3,fa[x]=0;
                else{
                    scanf("%lld",&y);
                    fa[x]=y;sta[x]=sta[y];
                }
            }
        }
        if(c==5||c==6){
            for(int i=1;i<=n;i++) b[i].clear();
            for(int i=1;i<=n;i++) if(fa[i]) b[fa[i]].push_back(i);
            for(int i=1;i<=n;i++) if(!fa[i]) dfs(i);
        }
        if(c==1||c==2){
            ans=INF;
            dfs2(1,0);
            printf("%lld\n",ans);
        }
        if(c==3||c==4||c==5||c==6){
            ans=0;
            for(int i=1;i<=n;i++) ans+=(sta[i]==3);
            printf("%lld\n",ans);
        }
    }
}
