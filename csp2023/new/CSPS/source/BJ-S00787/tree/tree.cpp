#include <cstdio>
#include <queue>
#include <cstring>
#define max(x,y) ((x)>(y) ? (x) : (y))
using namespace std;

const int NMAX=1e5+10;

int edge[NMAX*2],ecnt=0;
int fir[NMAX],nex[NMAX*2];
int n;
bool flag[NMAX];

void build(int u,int v){
    edge[ecnt]=v;
    nex[ecnt]=fir[u];
    fir[u]=ecnt++;
}

int cal(int x,int y){
    if (x%y==0) return x;
    else return (x/y+1)*y;
}

int a[NMAX],b[NMAX];

struct cmp{
    bool operator()(int x,int y){
        return cal(a[x],b[x])<cal(a[y],b[y]);
    }
};

priority_queue<int,vector<int>,cmp> pq;

int main(){
    memset(fir,-1,sizeof(fir));
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d%d%*d",a+i,b+i);
    }
    for (int i=0;i<n-1;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        build(x,y);
        build(y,x);
    }
    int ans=0;
    pq.push(1);
    flag[1]=1;
    int day=1;
    while (!pq.empty()){
        int head=pq.top();
        //printf("day%d %d\n",day,head);
        pq.pop();
        ans=max(ans,day+cal(a[head],b[head])-1);
        for (int i=fir[head];i!=-1;i=nex[i]){
            //printf("*%d\n",i);
            if (flag[edge[i]]) continue;
            pq.push(edge[i]);
            flag[edge[i]]=1;
        }
        day++;
    }
    printf("%d\n",ans);
    return 0;
}
