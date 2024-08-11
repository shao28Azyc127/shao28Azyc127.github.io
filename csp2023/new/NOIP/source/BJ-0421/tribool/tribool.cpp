#include <bits/stdc++.h>
#define pii pair<int,int>
#define mkp(x,y) make_pair(x,y)
#define fir first
#define sec second
using namespace std;
const int maxn=1e5+5;
struct edge{
    int from,to,w,next;
}e[maxn<<1];
int testcase,T,n,m,tot,in[maxn],out[maxn],h[maxn],ans[maxn],id[maxn],vis[maxn],vis2[maxn];
queue <int> q;
pii a[maxn];
char ch;
inline void addEdge(int x,int y,int w){
    e[++tot]=(edge){x,y,w,h[x]};
    id[y]=h[x]=tot;
    in[y]++,out[x]++;
}
inline int have(){
    for (int i=1;i<=n;i++) if (in[i]>0 && out[i]>0) return i;
    return 0;
}
inline void topo(){
    for (int i=1;i<=n;i++) if (!in[i]) q.push(i);
    while (!q.empty()){
        int now=q.front();
        q.pop();
        for (int i=h[now];i;i=e[i].next){
            int v=e[i].to;
            if (ans[now]==2){
                ans[v]=2;
                out[now]--;
                if (!--in[v]) q.push(v);
            }else{
                ans[v]=ans[now]^e[i].w;
                out[now]--;
                if (!--in[v]) q.push(v);
            }
        }
    }
    //for (int i=1;i<=n;i++) printf("%d ",in[i]);
    //printf("\n*");
    //for (int i=1;i<=n;i++) printf("%d ",id[i]);
    //printf("\n");
    //return ;
    int x,flag=false;
    //memset(vis,false,sizeof(vis));
    //memset(vis2,false,sizeof(vis2));
    while (x=have()){
        flag=true;
        int y=x,sum=0;
        int times=0;

        do{
            if (vis[y]) break;
            vis[y]=true;
            sum^=e[id[y]].w;
            y=e[id[y]].from;
            //printf("%d %d %d %d : %d %d %d\n",out[x],x,y,id[y],e[id[y]].from,e[id[y]].to,e[id[y]].w);

        }while (x!=y);
        y=x;
        do{
            if(vis2[y]) break;
            vis2[y]=true;
            ans[y]=((sum&1)?2:0);
            if (in[y]) in[y]--;
            y=e[id[y]].from;
        }while (x!=y);
    }
    if (flag) topo();
}
inline void solve(){
        memset(vis,false,sizeof(vis));
    memset(vis2,false,sizeof(vis2));
    memset(h,0,sizeof(h)),tot=0;
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    memset(ans,-1,sizeof(ans));
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) a[i]=mkp(-1,0);//-1 bg 0 false 1 true 2 Unknown/ id ; -1 is not 0 means value 1 is
    for (int i=1,x,y;i<=m;i++){
        cin>>ch;
        if (ch=='+'){
            scanf("%d%d",&x,&y);
            a[x]=mkp(y,1);
        }else if (ch=='-'){
            scanf("%d%d",&x,&y);
            a[x]=mkp(y,-1);
        }else{
            scanf("%d",&x);
            a[x]=mkp((ch=='T')?1:((ch=='F')?0:2),0);
        }
    }
    //for (int i=1;i<=n;i++) printf("%d %d\n",a[i].fir,a[i].sec);
    for (int i=1;i<=n;i++){
        if (a[i].sec==0 && a[i].fir!=-1) ans[i]=a[i].fir;
        else if (a[i].sec==1 && a[i].fir==i || !a[i].sec && a[i].fir==-1) ans[i]=1;
        else if (a[i].sec==-1 && a[i].fir==i) ans[i]=2;
        else addEdge(a[i].fir,i,(a[i].sec>0)?0:1);
    }
    //for (int i=1;i<=n;i++) printf("%d ",ans[i]);
    //printf("\n");
    topo();
    //for (int i=1;i<=n;i++) printf("%d ",ans[i]);
    //printf("\n");
    int cnt=0;
    for (int i=1;i<=n;i++) cnt+=(ans[i]==2);
    printf("%d\n",cnt);
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&testcase,&T);
    while (T--) solve();
    return 0;
}
