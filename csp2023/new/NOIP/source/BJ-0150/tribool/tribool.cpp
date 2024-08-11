#include <bits/stdc++.h>
#define il inline
using namespace std;
il bool isch(char c){return c=='T' || c=='F' || c=='U' || c=='+' || c=='-';}
il char readc(){
    char c=getchar();
    while(!isch(c)) c=getchar();
    return c;
}
il int read(){
    int x=0,c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) x=x*10+c-48,c=getchar();
    return x;
}
const int N=1e5+5;
int sid,T,n,m,ans,ck1,ck2,ck3,a[N],b[N],to[N];
struct node{
    char c;int x,y;
    il node(){x=y=0;}
}q[N];
il void get(){
    for(int i=1;i<=n;++i) b[i]=a[i];
    for(int i=1;i<=m;++i){
        if(q[i].c=='T') b[q[i].x]=0;
        else if(q[i].c=='F') b[q[i].x]=1;
        else if(q[i].c=='U') b[q[i].x]=2;
        else if(q[i].c=='+') b[q[i].x]=b[q[i].y];
        else b[q[i].x]=(b[q[i].y]==2?2:1-b[q[i].y]);
    }
    int cc=1,ss=0;
    for(int i=1;i<=n;++i) cc&=(a[i]==b[i]),ss+=(b[i]==2);
    if(cc) ans=min(ans,ss);
}
void dfs(int x){
    if(x>n){get();return ;}
    for(int i=0;i<3;++i) a[x]=i,dfs(x+1);
}
vector<int> e[N];int vis[N];
il void add(int x,int y){e[x].push_back(y);}
queue<int> qu;
char c;int x,y;
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&sid,&T);
    while(T--){
        scanf("%d%d",&n,&m);ck1=ck2=ck3=1;
        for(int i=1;i<=n;++i) a[i]=0;
        for(int i=1;i<=m;++i){
            q[i].c=readc(),q[i].x=read();
            if(q[i].c=='+' || q[i].c=='-') q[i].y=read();
            ck1&=(q[i].c=='T' || q[i].c=='F' || q[i].c=='U');
            ck2&=(q[i].c=='U' || q[i].c=='+');
            ck3&=(q[i].c=='+' || q[i].c=='-');
        }
        if(n<=10){
            ans=n,dfs(1);
            printf("%d\n",ans);continue;
        }
        if(ck1){
            for(int i=1;i<=m;++i){
                if(q[i].c=='T') a[q[i].x]=0;
                else if(q[i].c=='F') a[q[i].x]=1;
                else a[q[i].x]=2;
            }
            ans=0;
            for(int i=1;i<=n;++i) if(a[i]==2) ++ans;
            printf("%d\n",ans);continue;
        }
        if(ck2){
            for(int i=1;i<=n;++i) e[i].clear(),vis[i]=0;
            for(int i=1;i<=n;++i) a[i]=0,to[i]=0;
            for(int i=1;i<=m;++i){
                if(q[i].c=='U') a[q[i].x]=2,to[q[i].x]=0;
                else to[q[i].x]=q[i].y,a[q[i].x]=0;
            }
            for(int i=1;i<=n;++i) if(to[i]) add(to[i],i);
            for(int i=1;i<=n;++i) if(a[i]==2) qu.push(i),vis[i]=1;
            while(qu.size()){
               x=qu.front();qu.pop();
               for(int y:e[x]){
                   if(vis[y]) continue;
                   a[y]=2,qu.push(y),vis[y]=1;
               }
            }
            ans=0;
            for(int i=1;i<=n;++i) if(a[i]==2) ++ans;
            printf("%d\n",ans);continue;
        }
    }
    return 0;
}
