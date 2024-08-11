#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=300010;
int c,t,n,m,ans,q[MAXN];
struct node{
    int p,x;
}s[MAXN];
struct cz{
    int u,v,w;
}e[MAXN];
int vis[MAXN];
int tq[MAXN],viss[MAXN];
struct Edge{
    int v,w,nx;
}edge[MAXN];
int h[MAXN],CNT;
void init(){
    memset(h,-1,sizeof(h));CNT=0;
}
void add_side(int u,int v,int w){
    edge[++CNT]={v,w,h[u]};h[u]=CNT;
}
void ddfs(int now,int w){
    q[now]=w;
    for(int i=h[now];i!=-1;i=edge[i].nx){
        if(q[edge[i].v]==5)ddfs(edge[i].v,w*(1-edge[i].w*2));
    }
}
int dfss(int now,int w,int tg){
    int rt=0;
    tq[now]=w;viss[now]=tg;
    if(w==0)rt++;
    for(int i=h[now];i!=-1;i=edge[i].nx){
        if(viss[edge[i].v]==tg&&tq[edge[i].v]!=w*(1-edge[i].w*2))return 1e18;
        if(viss[edge[i].v]!=tg)rt+=dfss(edge[i].v,w*(1-edge[i].w*2),tg);
    }
    return rt;
}
int b[MAXN];
void mj(int now,int sum){
    if(now==n+1){
        for(int i=1;i<=n;i++){
            b[i]=q[i];
        }b[n+1]=1;b[n+2]=0;b[n+3]=-1;
        for(int i=1;i<=m;i++){
            b[e[i].u]=b[e[i].v]*(1-2*(e[i].w));
        }
        for(int i=1;i<=n;i++){
            if(b[i]!=q[i])return;
        }
        ans=sum;
        return;
    }
    q[now]=-1;
    mj(now+1,sum);
    if(ans!=-1)return;
    q[now]=1;
    mj(now+1,sum);
    if(ans!=-1)return;
    q[now]=0;
    mj(now+1,sum+1);
}
signed main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    if(c==1||c==2){
        while(t--){ans=-1;
        scanf("%lld%lld",&n,&m);
        for(int i=1;i<=m;i++){
            char opt=getchar();int u,v;
            while(opt!='T'&&opt!='U'&&opt!='F'&&opt!='-'&&opt!='+')opt=getchar();
            if(opt=='-'){
                scanf("%lld%lld",&u,&v);
                e[i]={u,v,1};
            }
            else if(opt=='+'){
                scanf("%lld%lld",&u,&v);
                e[i]={u,v,0};
            }
            else{
                scanf("%lld",&u);
                if(opt=='T')v=n+1;
                if(opt=='F')v=n+3;
                if(opt=='U')v=n+2;
                e[i]={u,v,0};
            }
        }
        mj(1,0);
        printf("%lld\n",ans);
    }
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    while(t--){
        scanf("%lld%lld",&n,&m);ans=0;
    for(int i=0;i<=n+5;i++){
        q[i]=5;s[i].p=0;s[i].x=0;vis[i]=0;tq[i]=0;viss[i]=0;
    }
        init();
        for(int i=1;i<=m;i++){
            char opt=getchar();int u,v;
            while(opt!='T'&&opt!='U'&&opt!='F'&&opt!='-'&&opt!='+')opt=getchar();
            if(opt=='-'){
                scanf("%lld%lld",&u,&v);
                e[i]={u,v,1};
            }
            else if(opt=='+'){
                scanf("%lld%lld",&u,&v);
                e[i]={u,v,0};
            }
            else{
                scanf("%lld",&u);
                if(opt=='T')v=n+1;
                if(opt=='F')v=n+3;
                if(opt=='U')v=n+2;
                e[i]={u,v,0};
            }
        }
        for(int i=1;i<=n;i++)s[i]={i,0};
        s[n+1]={n+1,0};s[n+2]={n+2,0};s[n+3]={n+3,0};
        for(int i=1;i<=m;i++){
            s[e[i].u].p=s[e[i].v].p;
            s[e[i].u].x=s[e[i].v].x^e[i].w;
        }
        for(int i=1;i<=n;i++){
            //cout<<s[i].p<<" "<<s[i].x<<endl;
            if(s[i].p<=n){
                if(s[i].p!=i){add_side(s[i].p,i,s[i].x);add_side(i,s[i].p,s[i].x);}
                else q[i]=s[i].x-1;
            }
            else{
                q[i]=(s[i].p-n-2)*(1-2*(s[i].x));
            }
        }
        for(int i=1;i<=n;i++){
                //cout<<" "<<i<<" "<<q[i]<<endl;
            if(q[i]!=5){
                ddfs(i,q[i]);
            }
        }
        for(int i=1;i<=n;i++){
            if(q[i]==5){
                int t0=dfss(i,1,i+n),t1=dfss(i,0,i);
                if(t0<=t1){
                    q[i]=1;
                    ddfs(i,q[i]);
                }
                else{
                    q[i]=0;
                    ddfs(i,q[i]);
                }
            }
        }
        for(int i=1;i<=n;i++){
            //cout<<q[i]<<" ";
            if(q[i]==0)ans++;
        }//cout<<endl;
        printf("%lld\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//lylakioi