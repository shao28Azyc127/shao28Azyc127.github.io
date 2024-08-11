#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int NMAX=1e6+10;

int a[NMAX]; //ai<0 means !ai
int b[NMAX]; //0->uncertain 1->T 2->F 3->U
int n,m;
int edge[NMAX*2],fir[NMAX],nex[NMAX*2],ecnt=0;
bool w[NMAX*2]; //0->nothing 1->!
bool flag[NMAX];
bool flag2[NMAX];
bool flag3[NMAX];
int ans[NMAX];

void build(int u,int v,bool _w){
    // printf("bulid:ecnt=%d %d %d %d\n",ecnt,u,v,_w);
    edge[ecnt]=v;
    w[ecnt]=_w;
    nex[ecnt]=fir[u];
    fir[u]=ecnt++;
}

void tp(){
    // for (int i=1;i<=n;i++){
    //     printf("a[%d]=%d b[%d]=%d ans[%d]=%d\n",i,a[i],i,b[i],i,ans[i]);
    // }
    queue<int> q;
    for (int i=1;i<=n;i++){
        if (!flag[i] && ans[i]!=0){
            // printf("tp init: ans[%d]=%d\n",i,ans[i]);
            q.push(i);
            flag[i]=1;
            flag3[i]=1;
        }
    }
    while (!q.empty()){
        int head=q.front();
        q.pop();
        for (int i=fir[head];i!=-1;i=nex[i]){
            // printf("!%d %d\n",head,edge[i]);
            if (flag[edge[i]]) continue;
            if (w[i]){
                if (ans[head]==1) ans[edge[i]]=2;
                else if (ans[head]==2) ans[edge[i]]=1;
                else ans[edge[i]]=3;
            }
            else ans[edge[i]]=ans[head];
            // printf("tp: #%d %d\n",edge[i],ans[edge[i]]);
            q.push(edge[i]);
            flag[edge[i]]=1;
            flag3[edge[i]]=1;
        }
    }
}

void tp2(int x){
    // for (int i=1;i<=n;i++){
    //     printf("a[%d]=%d b[%d]=%d ans[%d]=%d\n",i,a[i],i,b[i],i,ans[i]);
    // }
    // printf("%d tp2:ans=%d\n",x,ans[x]);
    queue<int> q;
    q.push(x);
    flag[x]=1;
    flag3[x]=1;
    while (!q.empty()){
        int head=q.front();
        q.pop();
        for (int i=fir[head];i!=-1;i=nex[i]){
            // printf("!%d %d\n",head,edge[i]);
            if (flag[edge[i]]) continue;
            if (w[i]){
                if (ans[head]==1) ans[edge[i]]=2;
                else if (ans[head]==2) ans[edge[i]]=1;
                else ans[edge[i]]=3;
            }
            else ans[edge[i]]=ans[head];
            // printf("tp: #%d %d\n",edge[i],ans[edge[i]]);
            q.push(edge[i]);
            flag[edge[i]]=1;
            flag3[edge[i]]=1;
        }
    }
}

bool findLoop(int x,int cnt,int deep=1){
    // printf("findLoop: %d %d\n",x,cnt);
    flag2[x]=1;
    for (int i=fir[x];i!=-1;i=nex[i]){
        int tcnt=w[i] ? cnt+1 : cnt;
        if (flag2[edge[i]]){
            if (tcnt&1) ans[edge[i]]=3;
            else ans[edge[i]]=1;
            // printf("deep=%d tcnt&1=%d\n",deep,tcnt&1);
            return 1;
        }
        if (findLoop(edge[i],tcnt,deep+1)){
            return 1;
        }
    }
    return 0;
}

void color(int x){
    queue<int> q;
    q.push(x);
    flag3[x]=1;
    while (!q.empty()){
        int head=q.front();
        q.pop();
        // printf("color:%d\n",head);
        for (int i=fir[head];i!=-1;i=nex[i]){
            if (flag3[edge[i]]) continue;
            q.push(edge[i]);
            flag3[edge[i]]=1;
        }
    }
}

// int a[NMAX]; //ai<0 means !ai
// int b[NMAX]; //0->uncertain 1->T 2->F 3->U
// int n,m;
// int edge[NMAX*2],fir[NMAX],nex[NMAX*2],ecnt=0;
// bool w[NMAX*2]; //0->nothing 1->!
// bool flag[NMAX];
// bool flag2[NMAX];
// bool flag3[NMAX];
// int ans[NMAX];

void foo(){
    scanf("%d%d",&n,&m);
    // printf("%d %d\n",n,m);
    for (int i=1;i<=n;i++) a[i]=i;
    memset(b,0,sizeof(b));
    memset(edge,0,sizeof(edge));
    memset(fir,-1,sizeof(fir));
    memset(nex,0,sizeof(nex));
    ecnt=0;
    memset(w,0,sizeof(w));
    memset(flag,0,sizeof(flag));
    memset(flag2,0,sizeof(flag));
    memset(flag3,0,sizeof(flag3));
    memset(ans,0,sizeof(ans));
    char c;
    int x,y;
    for (int i=0;i<m;i++){
        scanf(" %c",&c);
        if (c=='+'){
            scanf("%d%d",&x,&y);
            a[x]=a[y];
            b[x]=b[y];
        }
        else if (c=='-'){
            scanf("%d%d",&x,&y);
            a[x]=-a[y];
            if (b[y]==1) b[x]=2;
            else if (b[y]==2) b[x]=1;
            else b[x]=b[y];
        }
        else{
            scanf("%d",&x);
            a[x]=0;
            if (c=='T') b[x]=1;
            else if (c=='F') b[x]=2;
            else b[x]=3;
        }
    }
    // for (int i=1;i<=n;i++){
    //     printf("a[%d]=%d b[%d]=%d\n",i,a[i],i,b[i]);
    // }
    for (int i=1;i<=n;i++){
        if (b[i]!=0) ans[i]=b[i];
        else if (a[i]==i) ans[i]=1;
        else if (a[i]==-i) ans[i]=3;
        else if (a[i]>0) build(a[i],i,0);
        else build(-a[i],i,1);
    }
    // for (int i=1;i<=n;i++){
    //     printf("a[%d]=%d b[%d]=%d ans[%d]=%d\n",i,a[i],i,b[i],i,ans[i]);
    // }
    tp();
    for (int i=1;i<=n;i++){
        if (!flag3[i] && ans[i]==0){
            // printf("start find loop\n");
            // color(i);
            if (findLoop(i,0)) tp2(i);
        }
    }
    tp();
    int cnt=0;
    for (int i=1;i<=n;i++){
        if (ans[i]==3) cnt++;
    }
    printf("%d\n",cnt);
    return;
}

int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    for (int i=0;i<t;i++){
        foo();
    }
    return 0;
}
