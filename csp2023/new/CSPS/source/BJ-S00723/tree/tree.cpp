#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const long long inf=1e9+5;
int n=1e5+5,head[N],cnt,x0[N],dl[N];
struct node{
    int v,nxt;
}edge[N];
long long a[N],b[N],c[N],ans=inf;
bool vis[N];
inline void addedge(int u,int v){
    edge[++cnt].v=v;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}
inline long long read(){
    char ch=getchar();
    long long num=0,f=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')  f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        num=num*10+ch-'0';
        ch=getchar();
    }
    return num*f;
}
inline bool check(long long x){
    for(int i=1;i<=n;i++){
        long long num=0;
        if(b[i]+x*c[i]>=1)  num=(x-x0[i])*((x0[i]+x+1)*c[i]+2*b[i])/2;
        else{
            if(dl[i]>x0[i])    num=(dl[i]-x0[i])*((x0[i]+dl[i]+1)*c[i]+2*b[i])/2+(x-dl[i]);
            else num=x-x0[i];
        }
        if(num<a[i])    return 0;
    }
    return 1;
}
inline long long checkans(){
    long long l=n,r=1e9,mid;
    while(l<r){
        mid=(l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    return l;
}
inline void find(int t){
    if(t==n){
        ans=min(ans,checkans());
        return ;
    }
    for(int u=1;u<=n;u++){
        if(!vis[u]) continue;
        for(int i=head[u];i;i=edge[i].nxt){
            int v=edge[i].v;
            if(vis[v])  continue;
            vis[v]=1;
            x0[v]=t;
            find(t+1);
            vis[v]=0;
            x0[v]=0;
        }
    }
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++)   a[i]=read(),b[i]=read(),c[i]=read();
    for(int i=1;i<=n;i++){
        if(c[i]>=0)  continue;
        dl[i]=(long long)((1.0-b[i])/c[i]);
    }
    for(int i=1;i<n;i++){
        int x,y;
        x=read(),y=read();
        addedge(x,y);
        addedge(y,x);
    }
    x0[1]=0;
    vis[1]=1;
    find(1);
    cout<<ans<<endl;
    return 0;
}
