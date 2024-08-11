#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+ch-'0';
        ch=getchar();
    }
    return x*f;
}
const int inf=2e9,N=100001;
int n,m,tt[N],vv[N],fa[N],du[N],sz[N],ct,an,vis[N],siz;
vector<int> e[N],jg;
queue<int> q;
void dfs(int x){
    if(vis[x]) return ;
    ct++,vis[x]=an;
    for(int y:e[x]){
        dfs(y);
    }
}
void dfs2(int x){
    if(vv[x]) return ;
    siz++;
    jg.push_back(x);
    vv[x]=1;
    for(int y:e[x]) dfs2(y);
}
void work(){
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        e[i].clear();
        tt[i]=i;
        vv[i]=0;
        sz[i]=0;
        du[i]=0;
    }
    while(m--){
        char x;
        int a,b;
        cin>>x;
        a=read();
        if(x=='T'){
            tt[a]=inf;
        }else if(x=='F'){
            tt[a]=-inf;
        }else if(x!='U'){
            b=read();
            if(x=='+') tt[a]=tt[b];
            else tt[a]=-tt[b];
        }else tt[a]=0;
    }/*
    for(int i=1;i<=n;i++){
        cout<<tt[i]<<" ";
    }
    cout<<endl;*/
    for(int a=1;a<=n;a++){
        if(tt[a]>0&&tt[a]!=inf&&a!=tt[a]){
            e[a].push_back(tt[a]);
            e[tt[a]].push_back(a);
        }
    }
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            ct=0,an=i;
            dfs(i);
            sz[i]=ct;
        //    cout<<i<<" "<<ct<<endl;
        }
    }
 //   for(int i=1;i<=n;i++) cout<<vis[i]<<" "<<tt[i]<<" frlgjreiog"<<endl;
 /*   cout<<endl;
     for(int i=1;i<=n;i++){
        if(tt[i]==0){
            cout<<i<<" "<<vis[i]<<" "<<sz[vis[i]]<<endl;
        }
     }
 cout<<endl;*/
    for(int i=1;i<=n;i++) e[i].clear();
    for(int i=1;i<=n;i++){
        if(tt[i]<0){
            if(tt[i]!=-inf){
                e[vis[i]].push_back(vis[-tt[i]]);
                e[vis[-tt[i]]].push_back(vis[i]);
                du[vis[i]]++;
                du[vis[-tt[i]]]++;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(vv[i]==0&&du[i]!=0){
            jg.clear();
            siz=0;
            dfs2(i);
            int fll=0;
            while(!q.empty()) q.pop();
            for(int y:jg){
                if(du[y]==1) q.push(y);
                vv[y]=1;
                if(tt[y]==0){
                    fll=1;
                    break;
                }
            }
            if(fll==1){
                for(int y:jg){
                    ans+=sz[y];
                }
                continue;
            }
            while(!q.empty()){
                int x=q.front();q.pop();
                siz--;
                du[x]--;
                for(int y:e[x]){
                    du[y]--;
                    if(du[y]==1) q.push(y);
                }
            }
        //    cout<<i<<" "<<siz<<" "<<sz[i]<<" "<<ans<<endl;
     //   cout<<"siz "<<siz<<endl;
            if(siz%2==1){
                for(int y:jg){
                    ans+=sz[y];
                }
            }
        }else if(vv[i]==0&&tt[i]==0) ans+=sz[vis[i]];
    }
    cout<<ans;
    puts("");
    return ;
}
signed main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c=read(),t=read();
    while(t--) work();
    return 0;
}
