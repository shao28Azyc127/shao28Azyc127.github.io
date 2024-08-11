#include<bits/stdc++.h>
using namespace std;
int tid,T;

namespace Solve1{

const int N=15;
int n,m;
int a[N],b[N];
char op[N][3];
int x[N],y[N];
int ans=N;

void dfs(int pos,int cnt){
    if(cnt>=ans)return;
    if(pos==n+1){
        for(int i=1;i<=n;i++)
            b[i]=a[i];
        for(int i=1;i<=m;i++){
            if(op[i][0]=='T')b[x[i]]=1;
            else if(op[i][0]=='F')b[x[i]]=-1;
            else if(op[i][0]=='U')b[x[i]]=0;
            else if(op[i][0]=='+')b[x[i]]=b[y[i]];
            else b[x[i]]=-b[y[i]];
        }
        //for(int i=1;i<=n;i++)printf("%d ",b[i]);puts("");puts("");
        for(int i=1;i<=n;i++)
            if(a[i]!=b[i])return;
        ans=cnt;
        return;
    }
    for(int i=-1;i<=1;i++){
        a[pos]=i;
        dfs(pos+1,cnt+(i==0));
    }
}

void main(){
    while(T--){
        scanf("%d%d",&n,&m);
        ans=n;
        for(int i=1;i<=m;i++){
            scanf("%s",op[i]);
            if(op[i][0]!='+' && op[i][0]!='-')
                scanf("%d",&x[i]);
            else
                scanf("%d%d",&x[i],&y[i]);
        }
        dfs(1,0);
        printf("%d\n",ans);
    }
}

}

namespace Solve2{

const int N=1e5+5,inf=0x3f3f3f3f;
int n,m,ans;
int a[N],fa[N],siz[N];
int getfa(int x){return x==fa[x]? x : fa[x]=getfa(fa[x]);}
char op[3];
int x,y;
int col[N];
int vis[N];
void dfs(int u,int op,int zu){
    int op2;
    if(a[u]<0)op2=-op;
    else op2=op;
    if(a[u]==inf || a[u]==-inf)return;
    if(a[u]==0){ans+=siz[getfa(u)];return;}
    a[u]=abs(a[u]);
    if(vis[a[u]]){
        if(vis[a[u]]==zu && col[a[u]]!=op2)
            ans+=siz[getfa(u)];
        return;
    }
    vis[a[u]]=zu;
    col[a[u]]=op2;
    dfs(a[u],op2,zu);
}

void main(){
    while(T--){
        scanf("%d%d",&n,&m);
        ans=0;
        memset(col,0,sizeof col);
        memset(vis,0,sizeof vis);
        for(int i=1;i<=n;i++){
            a[i]=i;fa[i]=i;siz[i]=1;
        }
        for(int i=1;i<=m;i++){
            scanf("%s",op);
            switch(op[0]){
                case 'T': scanf("%d",&x); a[x]=inf; break;
                case 'F': scanf("%d",&x); a[x]=-inf; break;
                case 'U': scanf("%d",&x); a[x]=0; break;
                case '+': scanf("%d%d",&x,&y); a[x]=a[y]; break;
                case '-': scanf("%d%d",&x,&y); a[x]=-a[y]; break;
            }
        }
        for(int i=1;i<=n;i++){
            if(a[i]==0 || a[i]==inf || a[i]==-inf)continue;
            int fi=getfa(i),fath=getfa(abs(a[i]));
            if(fi==fath)continue;
            fa[fi]=fath;
            siz[fath]+=siz[fi];
            //printf("%d %d %d\n",i,fath);
        }
        for(int i=1;i<=n;i++){
            if(!col[i]){
                col[i]=1;
                vis[i]=i;
                dfs(i,1,i);
            }
        }
        printf("%d\n",ans);
    }
}

}


int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>tid>>T;
    if(tid<=2)Solve1::main();
    else Solve2::main();
    return 0;
}
